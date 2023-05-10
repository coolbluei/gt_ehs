<?php
/**
 * @file
 * Documentation of Mercury Reader API.
 */

/**
 * Mercury Reader offers a simple API for developers. Some of these functions will be of particular
 * use to those using the local node approach to Mercury data (Feeds + XPath Parser or similar Ñ 
 * contact webteam@gatech.edu for details). Function signatures within this document will be 
 * maintained throughout the life of the 7.x-2.x branch. Call other functions at your own risk.
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
 * Barf up JSON representations of an arbitrary Mercury node.
 *
 * @param int $id
 *   A Mercury ID
 *
 * @return string
 *   A JSON representation of the node title and summary.
 */
function hg_reader_get_feature_json($id) {
  $filter_date = date('Ymd');
  $feed_attrs = array(
       'xslt' => variable_get('hg_item_xsl', drupal_get_path('module', 'hg_reader') . '/xsl/hgSerializedItem.xsl'),
       'cacheTime' => 3600,
       'xslParams' => array('filter_string'=>$filter_date, 'index'=> 1)
  );

  $hg_item = unserialize(array_pop(hg_reader_reader($id, $feed_attrs, 'json')));

  $out['title'] = base64_decode($hg_item['title']['value']);
  $out['summary'] = base64_decode($hg_item['summary']['value']);
  
  return drupal_json_output($out);
}
