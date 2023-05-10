<?php

/**
 * Georgia Institute of Technology Mercury Feed Reader — Node include
 *
 * This file contains functions related to displaying and editing Mercury feeds on nodes.
 *
 * @author Office of Communications and Marketing <web@comm.gatech.edu>
 *
 */

/**
 * Implementation of hook_node_delete().
 */
function hg_reader_node_delete($node) {
  $fid = hg_reader_get_feed_fid($node->nid);

  // delete the feed
  db_delete('hg_feeds')
    ->condition('fid', $fid)
    ->execute();

  // delete the node info
  db_delete('hg_feeds_nodes')
    ->condition('fid', $fid)
    ->execute();

  // delete the classes
  db_delete('hg_feeds_classes')
    ->condition('fid', $fid)
    ->execute();
}

/**
 * Implementation of hook_node_load().
 */
function hg_reader_node_load($nodes, $types) {
  foreach ($nodes as $node) {

    // get the feed
    $query = db_select('hg_feeds', 'hg');
    $query->join('hg_feeds_nodes', 'hgn', 'hg.fid = hgn.fid');
    $query->fields('hg', array('fid', 'hg_fid', 'maximum', 'parent', 'page', 'sort', 'feed_fields', 'item_fields'));
    $query->condition('hgn.nid', $node->nid);
    try {
      $result = $query->execute();
    } catch (Exception $e) {
      // Updates still pending. Prod the user into running them.
      $message = 'Mercury Reader cannot function properly until you run ' . l('update.php', '/update.php') . '.';
      drupal_get_messages();
      drupal_set_message($message, 'error');
      return;
    }
    $feed = $result->fetchAssoc();

    // apply feed characteristics to the node
    $nodes[$node->nid]->feed_id = $feed['hg_fid'];
    $nodes[$node->nid]->feed_item_count = $feed['maximum'];
    $nodes[$node->nid]->feed_parent = $feed['parent'];
    $nodes[$node->nid]->feed_page = $feed['page'];
    $nodes[$node->nid]->feed_sort = $feed['sort'];

    // get the feed field selections
    if (isset($feed['feed_fields'])) {
      $selected_fields = unserialize($feed['feed_fields']);
      $available_fields = hg_reader_field_defaults();
      foreach ($selected_fields as $key => &$fields) {
        foreach ($fields as &$field) {
          if (isset($available_fields[substr($key, 12)][$field])) {
            $field = $available_fields[substr($key, 12)][$field];
          }
        }
      }
    } else {
      // no selections available; go with defaults
      $selected_fields = hg_reader_field_defaults('feed_defaults');
    }
    $nodes[$node->nid]->feed_fields = $selected_fields;

    // get the item field selections
    if (isset($feed['item_fields']) && $feed['item_fields'] != '') {
      $selected_fields = unserialize($feed['item_fields']);
      $available_fields = hg_reader_field_defaults('fieldnames', 'items');
      foreach ($selected_fields as $key => &$fields) {
        foreach ($fields as &$field) {
          if (isset($available_fields[substr($key, 12)][$field])) {
            $field = $available_fields[substr($key, 12)][$field];
          }
        }
      }
    } else {
      // no selections available; go with defaults
      $selected_fields = hg_reader_field_defaults('item_defaults', 'items');
    }
    $nodes[$node->nid]->item_fields = $selected_fields;

    // get the feed classes
    $classes = db_select('hg_feeds_classes', 'hgc')
      ->fields('hgc', array('class'))
      ->condition('fid', $feed['fid'])
      ->execute();
    $nodes[$node->nid]->feed_classes = Array();
    while ($class = $classes->fetchField()) {
      array_push($nodes[$node->nid]->feed_classes, $class);
    }

  }
}

/**
 * Implementation of hook_node_type().
 * Rename or delete the settings variable if a type changes.
 */
function hg_reader_node_type($op, $info) {
  switch ($op) {
    case 'delete':
      variable_del('hg_use_'. $info->type);
      break;
    case 'update':
      if (!empty($info->old_type) && $info->old_type != $info->type) {
        if (hg_reader_has_mercury_fields($info->old_type)) {
          variable_del('hg_use_'. $info->old_type);
          variable_set('hg_use_'. $info->type, 1);
        }
      }
      break;
  }
}

/**
 * Implementation of hook_node_view().
 *
 * @todo $combined_feeds should be trimmed to feed_item_count before going to the theme.
 */
function hg_reader_node_view($node, $view_mode, $langcode) {
  $offset = isset($_GET['hgo']) ? intval($_GET['hgo']) : 0;
  if (!isset($node->feed_id) || $node->feed_id == '') { return; }

  // go grab the feed xsl and mull it over appropriately
  $feeds = hg_reader_reader($node->feed_id);
  if ($feeds[0] == 0) { return; }
  array_shift($feeds);
  $combined_feeds = array();
  foreach ($feeds as $feed) { $combined_feeds = array_merge($combined_feeds, unserialize($feed)); }
  foreach ($combined_feeds as &$feed) { hg_reader_decode($feed); }

  if (count($feeds) > 1) {
    // remove dupes and sort combined feeds
    $combined_feeds = array_map('unserialize', array_unique(array_map('serialize', $combined_feeds)));
    usort($combined_feeds, 'hg_reader_sort_feed');
  }

  $total = count($combined_feeds);

  // reverse feed if sorting is set
  if ($node->feed_sort == 1) { $combined_feeds = array_reverse($combined_feeds); }

  // trim combined feeds to feed_item_count
  if ($node->feed_item_count > 0) { $combined_feeds = array_slice($combined_feeds, $offset, $node->feed_item_count); }

  // go
  $node->content['hg_feed'] = array(
    '#markup' => theme('hg_feed', array(
      'feeds' => $combined_feeds,
      'fields' => isset($node->feed_fields) ? $node->feed_fields : '',
      'page' => $node->feed_page,
      'maximum' => $node->feed_item_count,
      'offset' => $offset,
      'total' => $total,
      'parent' => $node->feed_parent,
      'classes' => $node->feed_classes,
      'is_block' => FALSE)),
    '#weight' => 10,
  );
}
