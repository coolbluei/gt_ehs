<?php

/**
 * Georgia Institute of Technology Mercury Feed Reader — Block include
 *
 * This file contains functions related to displaying and editing Mercury blocks.
 *
 * @author Office of Communications and Marketing <web@comm.gatech.edu>
 *
 */

/**
 * Implementation of hook_block_info
 *
 * @return array
 */
function hg_reader_block_info() {
  $blocks = array();

  $result = db_select('hg_feeds_blocks', 'hg')
    ->fields('hg', array('bid', 'title'))
    ->orderBy('title')
    ->execute();

  while ($block = $result->fetchObject()) {
    $blocks[$block->bid]['info'] = $block->title;
    // Not worth caching.
    $blocks[$block->bid]['cache'] = DRUPAL_NO_CACHE;
  }

  return $blocks;
}

/**
 * Implementation of hook_block_configure
 *
 * @param $delta
 * @return mixed
 */
function hg_reader_block_configure($delta) {
  //drupal_add_css(drupal_get_path('module', 'hg_reader') . '/hg_reader.css');
  //drupal_add_js(drupal_get_path('module', 'hg_reader') . '/hg_reader.js');

  // get the feed
  $query = db_select('hg_feeds', 'hg');
  $query->join('hg_feeds_blocks', 'hgb', 'hg.fid = hgb.fid');
  $query->fields('hg');
  $query->fields('hgb');
  $query->condition('bid', $delta);
  $result = $query->execute();
  $block = $result->fetchObject();

  if ($block) {
    // get the feed classes
    $classes = db_select('hg_feeds_classes', 'hgc')
      ->fields('hgc', array('class'))
      ->condition('fid', $block->fid)
      ->execute();
    $feed_classes = Array();
    while ($class = $classes->fetchField()) {
      array_push($feed_classes, $class);
    }
  }


  // FEED SETTINGS

  $form['admin_title'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($block->title) ? $block->title : '',
    '#title' => t('Block description'),
    '#description' => t('A brief description of your block. Used on the block overview page.'),
    '#weight' => -20,
  );

  $form['feed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mercury settings'),
    '#weight' => 32,
  );
  $form['feed']['feed_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Feed ID'),
    '#default_value' => isset($block->hg_fid) ? $block->hg_fid : '',
    '#description' => 'This is the five- or six-digit ID in the URL of your feed in Mercury. You may enter multiple feed IDs, separating them with commas.',
    '#size' => 20,
    '#maxlength' => 255,
  );
  $form['feed']['feed_item_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum items'),
    '#default_value' => isset($block->maximum) ? $block->maximum : 0,
    '#description' => 'Enter a the maximum number of items you want the feed to display, or 0 for unlimited.',
    '#size' => 20,
    '#maxlength' => 8,
  );
  $form['feed']['feed_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Feed Classes'),
    '#description' => 'Feed classes are used to generate template suggestions and css classes specific to this feed. Separate classes with spaces.',
    '#default_value' => isset($feed_classes) ? $feed_classes : '',
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['feed']['feed_parent'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent URL'),
    '#description' => 'Specify a URL serve as a parent to Mercury items in this block. E.g. <em>news</em>.',
    '#default_value' => isset($block->parent) ? $block->parent : '',
    '#size' => 40,
    '#maxlength' => 255,
  );
  /*
  $form['feed']['feed_page'] = array(
    '#type' => 'checkboxes',
    '#description' => 'Check this box if you want a paged feed, with next and prev links.',
    '#options' => array(
      1 => t('Use a pager'),
    ),
    '#default_value' => isset($feed['page']) ? array($feed['page']) : array(0),
  );
  */
  $form['feed']['feed_sort'] = array(
    '#type' => 'checkboxes',
    '#description' => 'Check this box if you wish the feed to appear in reverse order.',
    '#options' => array(
      1 => t('Reverse sort'),
    ),
    '#default_value' => isset($block->sort) ? array($block->sort) : array(0),
  );

  // FEED FIELDS
  /*
  $form['feed_fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Teaser field selections'),
    '#description' => t('Show the selected fields in lists of teasers.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 40,
  );

  $feed_defaults = hg_reader_field_defaults('defaults_numeric', 'feeds');

  $form['feed_fields']['feed_fields_events'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Event fields',
    '#default_value' => isset($feed['feed_fields_events']) ? $feed['feed_fields_events'] : $feed_defaults['events'],
  );

  $form['feed_fields']['feed_fields_news'] = array(
    '#type' => 'checkboxes',
    '#title' => 'News fields',
    '#default_value' => isset($feed['feed_fields_news']) ? $feed['feed_fields_news'] : $feed_defaults['news'],
  );

  $form['feed_fields']['feed_fields_external_news'] = array(
    '#type' => 'checkboxes',
    '#title' => 'External news fields',
    '#default_value' => isset($feed['feed_fields_external_news']) ? $feed['feed_fields_external_news'] : $feed_defaults['external_news'],
  );
  */

  $feed_fields = hg_reader_field_defaults('fieldnames', 'feeds');
  foreach ($feed_fields as $type => $options) {
    $form['feed_fields']['feed_fields_' . $type]['#options'] = $options;
  }

  return $form;
}

/**
 * Implementation of hook_block_save
 *
 * @param $delta
 * @param $edit
 */
function hg_reader_block_save($delta, $edit) {
  $fid = hg_reader_get_feed_fid($edit['delta'], 'hg_feeds_blocks', 'bid');

  // update the feed
  db_update('hg_feeds')
    ->fields(array(
      'hg_fid' => $edit['feed_id'],
      'maximum' => $edit['feed_item_count'],
      'parent' => $edit['feed_parent'],
      'sort' => $edit['feed_sort']))
    ->condition('fid', $fid)
    ->execute();

  db_update('hg_feeds_blocks')
    ->fields(array(
      'title' => $edit['admin_title'],
    ))
    ->condition('bid', $edit['delta'])
    ->execute();

  // delete the old classes
  db_delete('hg_feeds_classes')
    ->condition('fid', $fid)
    ->execute();

  // insert the new classes
  $classes = array_unique(explode(' ', $edit['feed_classes']));
  foreach ($classes as $class) {
    db_insert('hg_feeds_classes')
      ->fields(array(
        'fid' => $fid,
        'class' => $class,
      ))
      ->execute();
  }

}

/**
 * Implementation of hook_block_view
 *
 * @param $delta
 * @return array|string
 */
function hg_reader_block_view($delta) {
  module_load_include('cache.inc', 'hg_reader', 'hg_reader');

  // get the feed
  $query = db_select('hg_feeds', 'hg');
  $query->join('hg_feeds_blocks', 'hgb', 'hg.fid = hgb.fid');
  $query->fields('hg');
  $query->fields('hgb');
  $query->condition('bid', $delta);
  $result = $query->execute();
  $unprocessed = $result->fetchObject();

  // get the feed classes
  $classes = db_select('hg_feeds_classes', 'hgc')
    ->fields('hgc', array('class'))
    ->condition('fid', $unprocessed->fid)
    ->execute();
  $feed_classes = Array();
  while ($class = $classes->fetchField()) {
    array_push($feed_classes, $class);
  }

  $feeds = hg_reader_reader($unprocessed->hg_fid);
  if ($feeds[0] == 0) { return ''; }
  array_shift($feeds);
  $combined_feeds = array();
  foreach ($feeds as $feed) { $combined_feeds = array_merge($combined_feeds, unserialize($feed)); }
  foreach ($combined_feeds as &$feed) { hg_reader_decode($feed); }

  if (count($feeds) > 1) {
    // remove dupes and sort combined feeds
    $combined_feeds = array_map("unserialize", array_unique(array_map("serialize", $combined_feeds)));
    usort($combined_feeds, 'hg_reader_sort_feed');
  }
  // reverse feed if sorting is set
  if ($unprocessed->sort == 1) { $combined_feeds = array_reverse($combined_feeds); }
  // trim combined feeds to feed_item_count
  if ($unprocessed->maximum > 0) { $combined_feeds = array_slice($combined_feeds, 0, $unprocessed->maximum); }

  $block = array(
    'subject' => $unprocessed->title,
    'content' => theme('hg_block', array(
      'feeds' => $combined_feeds,
      'maximum' => $unprocessed->maximum,
      'classes' => $feed_classes,
      'parent' => $unprocessed->parent,
      'is_block' => TRUE,
    )),
  );

  return $block;
}

/**
 * Mercury block configuration form
 *
 * @param $node
 * @param $form_state
 * @return mixed
 */
function hg_reader_add_block_form($node, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  return block_admin_configure(NULL, $form_state, 'hg_reader', NULL);
}

/**
 * Custom block submission handler
 *
 * @param $form
 * @param $form_state
 */
function hg_reader_add_block_form_submit($form, &$form_state) {
  // Determine the delta of the new block.
  $block_ids = variable_get('hg_reader_block_ids', array());
  $delta = empty($block_ids) ? 1 : max($block_ids) + 1;

  // Save the new array of blocks IDs.
  $block_ids[] = $delta;
  variable_set('hg_reader_block_ids', $block_ids);

  // Save the block configuration.
  hg_reader_hg_block_save($delta, $form_state['values']);

  // Run the normal new block submission (borrowed from block_add_block_form_submit).
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      db_insert('block')
        ->fields(array(
          'visibility' => $form_state['values']['visibility'],
          'pages' => trim($form_state['values']['pages']),
          'custom' => $form_state['values']['custom'],
          'title' => $form_state['values']['title'],
          'module' => $form_state['values']['module'],
          'theme' => $theme->name,
          'status' => 0,
          'weight' => 0,
          'delta' => $delta,
          'cache' => DRUPAL_NO_CACHE,
        ))
        ->execute();
    }
  }

  foreach (array_filter($form_state['values']['roles']) as $rid) {
    db_insert('block_role')
      ->fields(array(
        'rid' => $rid,
        'module' => $form_state['values']['module'],
        'delta' => $delta,
      ))
      ->execute();
  }

  drupal_set_message(t('The block has been created.'));
  cache_clear_all();

  $form_state['redirect'] = 'admin/structure/block';
  return;
}

/**
 * Mercury block save handler
 *
 * @param $delta
 * @param $values
 */
function hg_reader_hg_block_save($delta, $values) {

  // save the feed
  $feed = db_insert('hg_feeds');
  $feed->fields(array(
    'hg_fid' => $values['feed_id'],
    'maximum' => $values['feed_item_count'],
    'parent' => $values['feed_parent'],
    'sort' => $values['feed_sort'],
  ));
  $fid = $feed->execute();

  $block = db_insert('hg_feeds_blocks');
  $block->fields(array(
    'fid' => $fid,
    'bid' => $delta,
    'title' => $values['admin_title'],
  ));
  $block->execute();

  // save the feed classes
  $classes = array_unique(explode(' ', $values['feed_classes']));
  foreach ($classes as $class) {
    db_insert('hg_feeds_classes')
      ->fields(array(
        'fid' => $fid,
        'class' => $class,
      ))
      ->execute();
  }

}

/**
 * Menu callback: confirm deletion of menu blocks.
 *
 * @param $form
 * @param $form_state
 * @param $delta
 * @return mixed
 */
function hg_reader_block_delete($form, &$form_state, $delta) {
  $block = block_load('hg_reader', $delta);

  $form['block_title'] = array('#type' => 'hidden', '#value' => $block->title);
  $form['delta'] = array('#type' => 'hidden', '#value' => $delta);

  return confirm_form($form, t('Are you sure you want to delete the block "%name"?', array('%name' => $block->title)), 'admin/structure/block', NULL, t('Delete'), t('Cancel'));
}

/**
 * Deletion of hg blocks.
 *
 * @param $form
 * @param $form_state
 */
function hg_reader_block_delete_submit($form, &$form_state) {
  // Remove the menu block configuration variables.
  $delta = $form_state['values']['delta'];
  $block_ids = variable_get('hg_reader_block_ids', array());
  unset($block_ids[array_search($delta, $block_ids)]);
  sort($block_ids);
  variable_set('hg_reader_block_ids', $block_ids);

  $fid = hg_reader_get_feed_fid($delta, 'hg_feeds_blocks', 'bid');

  db_delete('block')->condition('module', 'hg_reader')->condition('delta', $delta)->execute();
  db_delete('block_role')->condition('module', 'hg_reader')->condition('delta', $delta)->execute();
  db_delete('hg_feeds')->condition('fid', $fid)->execute();
  db_delete('hg_feeds_blocks')->condition('bid', $delta)->execute();
  db_delete('hg_feeds_classes')->condition('fid', $fid)->execute();

  drupal_set_message(t('The "%name" block has been removed.', array('%name' => $form_state['values']['block_title'])));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
  return;
}

/**
 * Add delete links to block list page for Mercury blocks.
 *
 * @param $form
 * @param $form_state
 */
function hg_reader_form_block_admin_display_form_alter(&$form, $form_state) {
  foreach (variable_get('hg_reader_block_ids', array()) AS $delta) {
    $form['blocks']['hg_reader_' . $delta]['delete'] = array('#type' => 'link', '#title' => 'delete', '#href' => 'admin/structure/hg-block/manage/block/' . $delta . '/delete');  }
}

