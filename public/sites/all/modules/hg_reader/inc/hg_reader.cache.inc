<?php

/**
 * Georgia Institute of Technology Mercury Feed Reader — Cache include
 *
 * This file contains functions related to retrieving and caching Mercury data.
 *
 * @author Office of Communications and Marketing <web@comm.gatech.edu>
 *
 */

/**
 * The main feed reader function. Given a Mercury ID, this returns transformed XML.
 *
 * @param int $id
 *   A Mercury ID
 * @param array $attr
 *   An associative array containing:
 *     - xslt: The path to an XSLT document to be used to transfrom XML from Mercury. Defaults to
 *       /sites/all/modules/hg_reader/xsl/hgSerializedItem.xsl.
 *     - xslParams: An associative array for passing arbitrary variables to the XSLT document
 *     - cacheTime: Number of seconds until cache is considered invalid. Defaults to 3600. It is
 *       recommended you do not change this.
 * @param string $type
 *   Set to either "feed" or "item" in order to trigger appropriate transformation.
 *
 * @return array
 *   An indexed array containing:
 *     0 - A Boolean indicating success or failure
 *     1 - Transformed XML. Defaults to a serialized PHP array.
 */
function hg_reader_reader($id = NULL, $attr = array(), $type = 'feed') {
  // if no id, return nothing
  if (!$id) { return; }

  if (!isset($attr['xslt'])) { $attr['xslt'] = drupal_get_path('module', 'hg_reader') . '/xsl/hgSerialized' . ucfirst($type) . '.xsl'; }
  if (!isset($attr['xslParams'])) { $attr['xslParams'] = array(); }
  if (!isset($attr['cacheTime'])) { $attr['cacheTime'] = intval(variable_get('hg_cache_item_timeout', 3600)); }

  // might be multiple feeds specified
  $ids = explode(',', $id);
  foreach ($ids as $fid) {
    $fid = trim($fid);
    $xml = hg_reader_get_xml($fid, $attr, $type);

    if (!$xml) { return false; }

    // Handle 404s
    if ($xml == '404') {
      // 404 header
      drupal_add_http_header('Status', '404 Not Found');

      // Check for and return a fast 404 page if configured.
      drupal_fast_404();

      $path = drupal_get_normal_path(variable_get('site_404', ''));
      if ($path && $path != $_GET ['q']) {
        // Custom 404 handler. Set the active item in case there are tabs to
        // display, or other dependencies on the path.
        menu_set_active_item($path);
        $return = menu_execute_active_handler($path, FALSE);
      }
      if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
        // Standard 404 handler.
        drupal_set_title(t('Page not found'));
        $return = t('The requested page "@path" could not be found.', array('@path' => request_uri()));
      }

      drupal_set_page_content($return);
      $page = element_info('page');
      print drupal_render_page($page);
    }

    // load XML into DOMDocument
    $xmlDoc = new DOMDocument();
    $xmlDoc->loadXML($xml);

    // load XSL into DOMDocument
    $xslDoc = new DomDocument();
    $xslDoc->load($attr['xslt']);

    // mix 'em together
    $proc = new XSLTProcessor();
    $proc->registerPHPFunctions();
    $proc->importStylesheet($xslDoc);

    // You can pass variables to use in the XSLT document by populating the $attr['xslParams'] array
    foreach ($attr['xslParams'] as $key => $value) {
      $proc->setParameter('', $key, $value);
    }

    // $result[0] = result code (boolean)
    // $result[1] = the transformed XML
    $result[] = $proc->transformToXML($xmlDoc);
  }
  array_unshift($result, 1);
  return $result;
}

/**
 * Determine how XML is to be retrieved and do it.
 *
 * @param int $id
 *   A Mercury ID
 * @param string $type
 *   Either 'feed', 'item', 'image', or 'file'.
 *
 * @return string
 *   Raw XML
 */
function hg_reader_get_xml($id, $attr, $type) {
  if ($cache = hg_reader_pull_cache($id)) {
    // Successfully pulled item from cache.
    if ($cache['expire'] <= time()) {
      // Cache is expired.
      if ($xml_fresh = hg_reader_pull_remote($id, $type)) {
        if ($xml_fresh == '404') {
          hg_reader_delete_cache($id);
          return '404';
        }
        // Fresh XML pulled from Mercury.
        hg_reader_push_cache($id, $xml_fresh['data'], $attr['cacheTime']);
        return $xml_fresh['data'];
      } else {
        // Mercury failed but cache was still available.
        hg_reader_message('Mercury notice: Expired ' . ($type) . ' (' . $id . ') pulled from cache.', 'warning');
        return $cache['data'];
      }
    } else {
      // Cache is valid.
      return $cache['data'];
    }
  } else {
    if ($xml = hg_reader_pull_remote($id, $type)) {
      // Item isn't on Mercury; respond appropriately.
      if ($xml == '404') { return '404'; }
      // Item not in cache but pulled from Mercury.
      hg_reader_push_cache($id, $xml['data'], $attr['cacheTime']);
      return $xml['data'];
    } else {
      // Item not in cache and not available from Mercury.
      hg_reader_message('Mercury error: The ' . $type . ' (' . $id . ') could not be retrieved. See the <a href="/admin/help/hg_reader">help pages</a> for information on this error.', 'error');
      return false;
    }
  }
}

/**
 * Given a Mercury ID, this pulls content and returns XML.
 *
 * @param int $id
 *   The Mercury ID
 * @param string $type
 *   Either 'feed', 'item', 'image', or 'file'.
 *
 * @return string
 *   Raw XML
 */
function hg_reader_pull_remote($id, $type = 'feed', $option = NULL) {
  // Fetch the data.
  switch ($type) {
    case 'feed':
    case 'item':
      $url = HG_URL . '/node/' . $id . '/xml';
      break;
    case 'file':
      // This has to be an alias because we don't have the file deets yet.
      $url = HG_URL . '/hgfile/' . $id;
      break;
    case 'image':
      // Same here.
      $url = HG_URL . '/hgimage/' . $id . '/' . $option;
      break;
  }
  $ch = hg_reader_curl_setup($url);
  $data['data'] = curl_exec($ch);
  $data['info'] = curl_getinfo($ch);
  $data['err'] = curl_error($ch);

  // Check for errahs.
  if ($data['info']['http_code'] == 404) {
    if ($type == 'feed') {
      hg_reader_message('Mercury error: The ' . $type . ' (' . $id . ') was not found.', 'warning');
      return false;
    } else { return '404'; }
  } else if ($data['info']['http_code'] == 403) {
    if ($type == 'item' || $type == 'feed') { hg_reader_message('Mercury error: Access to the ' . $type . ' (' . $id . ') is restricted.', 'warning'); }
    return false;
  } else if ($data['info']['http_code'] == 307) {
    if ($type == 'item' || $type == 'feed') { hg_reader_message('Mercury error: This ' . $type . ' (' . $id . ') is unpublished.', 'warning'); }
    return false;
  } else if ($data['info']['http_code'] == 503) {
    if ($type == 'item' || $type == 'feed') { hg_reader_message('Mercury error: Mercury is offline.', 'warning'); }
    return false;
  } else if (strpos($data['err'], 'Operation timed out') > -1) {
    if ($type == 'item' || $type == 'feed') { hg_reader_message('Mercury error: ' . $data['err'] . '. You may want to consider increasing the Mercury Reader\'s <a href="/admin/config/hg/hg-reader?destination=' . $_GET['q'] . '">curl timeout value</a>.', 'warning'); }
    return false;
  } else if ($data['err']) {
    if ($type == 'item' || $type == 'feed') { hg_reader_message('Mercury error: ' . $data['err'] . '.', 'warning'); }
    return false;
  } else if (!$data['data']) {
    // No XML received. Set an error and return false.
    if ($type == 'item' || $type == 'feed') { hg_reader_message('Mercury error: Mercury is not responding for an unknown reason.', 'warning'); }
    return false;
  }

  // Success
  curl_close($ch);
  return $data;
}

/**
 * Given a Mercury ID, this pulls content from the database cache and returns XML.
 *
 * @param int $id
 *   The Mercury ID
 *
 * @return array
 *   An associative array containing:
 *     'cid' - The cache ID
 *     'data' - Raw XML
 *     'expire' - A Unix timestamp indicating the expiration time
 */
function hg_reader_pull_cache($id) {
  $cache = db_select('cache_hg', 'c')
    ->fields('c')
    ->condition('cid', $id)
    ->execute()
    ->fetchAssoc();
  return $cache;
}

/**
 * Given a Mercury ID, this pushes XML into the database cache.
 *
 * @param int $id
 *   The Mercury ID
 * @param string $id
 *   The Mercury ID
 * @param string $xml
 *   The XML to be stored
 * @param string $cache_time
 *   The number of seconds until the cache expires
 */
function hg_reader_push_cache($id, $data, $cache_time) {
  db_merge('cache_hg')
    ->key(array('cid' => $id))
    ->fields(array(
      'cid' => $id,
      'data' => $data,
      'expire' => time() + $cache_time,
    ))
    ->execute();
}

/**
 * Delete an item from the cache if it can't be found in Mercury
 * @param $id
 */
function hg_reader_delete_cache($id) {
  db_delete('cache_hg')
    ->condition('cid', $id)
    ->execute();
  return;
}

/**
 * This function fetches files (including images) from Mercury.
 *
 * @param string $type
 *   Either "image" or "file"
 * @param int $id
 *   Either a Mercury image node ID or a Mercury file ID (note that this corresponds to node/files/
 *   item/fid within a node's XML.
 * @param string $option
 *   For images, the name of the Mercury ImageCache preset desired (contact webteam@gatech.edu for
 *   details. For files, this option will be automatically set to "other."
 *
 * @todo Switch options can be combined. Do it.
 */
function hg_reader_get_file($type, $id, $option = 'original') {
  switch ($type) {
    case 'image':
      // We still want to support the deprecated function signature.
      $format = (isset($_GET['f']) && $_GET['f']) ? check_plain($_GET['f']) : check_plain($option);
      echo hg_reader_file_helper($type, $id, $format);
      break;
    case 'file':
      $option = 'other';
      echo hg_reader_file_helper($type, $id, $option);
      break;
  }
}

/**
 * This function fetches files from Mercury and caches them.
 *
 * @param int $id
 *   A Mercury file or image ID. Note that files are not nodes and thus have a separate set of indices.
 * @param string $option
 *   For images this will indicate the desired ImageCache preset.
 *
 * @return string
 *   Returns the contents of the file or false if the file can't be retrieved.
 *
 * @todo Proper error handling for unavailable items.
 * @todo Remove all formats when an image cache is cleared.
 */
function hg_reader_file_helper($type, $id, $option) {
  if ($cache = hg_reader_pull_cache($id . '-' . $option)) {
    // Successfully pulled item from cache.
    if ($cache['expire'] <= time()) {
      // Cache is expired.
      if ($data_fresh = hg_reader_pull_remote($id, $type, $option)) {
        // Fresh data pulled from Mercury.
        $data_fresh['info']['file_name'] = trim(strrchr($data_fresh['info']['url'], '/'), '/');

        hg_reader_push_cache($id . '-' . $option, serialize($data_fresh['info']), intval(variable_get('hg_cache_item_timeout', 86400)));
        $dir = variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/') . $option;
        file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
        file_put_contents(variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/') . $option . '/' . $data_fresh['info']['file_name'], $data_fresh['data']);

        hg_reader_set_headers($data_fresh['info']);
        return $data_fresh['data'];
      } else {
        // Mercury failed but cache was still available.
        $data = unserialize($cache['data']);
        hg_reader_set_headers($data);
        return file_get_contents(variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/') . $option . '/' . $data['file_name']);
      }
    } else {
      // Cache is valid.
      $data = unserialize($cache['data']);
      hg_reader_set_headers($data);
      return file_get_contents(variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/') . $option . '/' . $data['file_name']);
    }
  } else {
    if ($data = hg_reader_pull_remote($id, $type, $option)) {
      // Item not in cache but pulled from Mercury.
      $data['info']['file_name'] = trim(strrchr($data['info']['url'], '/'), '/');

      hg_reader_push_cache($id . '-' . $option, serialize($data['info']), intval(variable_get('hg_cache_item_timeout', 86400)));
      $dir = variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/') . $option;
      file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
      file_put_contents(variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/') . $option . '/' . $data['info']['file_name'], $data['data']);

      hg_reader_set_headers($data['info']);
      return $data['data'];
    } else {
      // Item not in cache and not available from Mercury.
      if ($id != HG_IMAGE_NOT_FOUND) {
        return hg_reader_get_file('image', HG_IMAGE_NOT_FOUND, $option);
      } else {
        hg_reader_message('Mercury error: The ' . $type . ' (' . $id . ') could not be retrieved. See the <a href="/admin/help/hg_reader">help pages</a> for information on this error.', 'error');
        #drupal_goto(drupal_get_normal_path(variable_get('site_frontpage', 'node')));
      }
    }
  }
}

/**
 * Set headers appropriately for files and images.
 *
 * @param array $info
 *   An array of information about the file as it was received from Mercury
 */
function hg_reader_set_headers($info) {
  drupal_add_http_header('Content-type', $info['content_type']);
  if (strpos($info['content_type'], 'image/') != 0 || strpos($info['content_type'], 'video/') != 0) {
    // Content-disposition header is for files only, so they will be downloaded and not displayed.
    drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $info['file_name'] . '"');
  }
}

/**
 * Perform curl_setopt routine.
 *
 * @param string $url
 *   The URL to be cURLed.
 *
 * @return handle
 *   A cURL handle.
 */
function hg_reader_curl_setup($url) {
  $ch = curl_init();

  /*
  * see: http://www.php.net/manual/en/function.curl-setopt.php#102121
  */
  $mr = 5;
  $rch = curl_copy_handle($ch);
  curl_setopt($rch, CURLOPT_URL, $url);
  curl_setopt($rch, CURLOPT_FOLLOWLOCATION, true);
  curl_setopt($rch, CURLOPT_HEADER, true);
  curl_setopt($rch, CURLOPT_NOBODY, true);
  curl_setopt($rch, CURLOPT_FORBID_REUSE, false);
  curl_setopt($rch, CURLOPT_RETURNTRANSFER, true);

  // follow up to $mr redirects
  do {
    $header = curl_exec($rch);
    if (curl_errno($rch)) {
      $code = 0;
    } else {
      $code = curl_getinfo($rch, CURLINFO_HTTP_CODE);
      if ($code == 301 || $code == 302) {
        preg_match('/Location:(.*?)\n/', $header, $matches);
        $newurl = trim(array_pop($matches));
      } else {
        $code = 0;
      }
    }
  } while ($code && --$mr);

  curl_close($rch);
  curl_setopt($ch, CURLOPT_URL, isset($newurl) ? $newurl : $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
  curl_setopt($ch, CURLOPT_TIMEOUT, variable_get('hg_curl_timeout', 10));
  curl_setopt($ch, CURLOPT_BINARYTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_HEADER, 0);
  curl_setopt($ch, CURLOPT_USERAGENT, 'hg_reader / drupal / ' . READER_VERSION . ' / ' . $_SERVER['HTTP_HOST']);

  return $ch;
}

/**
 * Invalidate a single item in the cache.
 *
 * @param string $id
 * @param string $type
 * @param string $hg_type
 */
function hg_reader_expire_caches($id = '', $type = 'all', $hg_type = '') {
  if ($type == 'all') {
    db_update('cache_hg')
      ->fields(array('expire' => time()))
      ->execute();
  } else if ($type == 'node') {
    $node = node_load($id);
    db_update('cache_hg')
      ->fields(array('expire' => time()))
      ->condition('cid', $node->feed_id)
      ->execute();
    drupal_set_message('Cache flushed.', 'status');
    drupal_goto('node/' . $id);
  } else {
    db_update('cache_hg')
      ->fields(array('expire' => time()))
      ->condition('cid', $id)
      ->execute();
    drupal_set_message('Cache flushed.', 'status');
    drupal_goto($type . '/' . $hg_type . '/' . $id);
  }
}

/**
 * Invalidate all Hg caches when Drupal caches are flushed
 */
function hg_reader_flush_caches() {
  hg_reader_expire_caches();
}
