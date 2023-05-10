<?php
/**
 * @file
 * gt_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gt_calendar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gt_calendar_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function gt_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An Event that is automatically copied from Mercury, using a GT Calendar Feed URL.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'gt_calendar_feed' => array(
      'name' => t('Feed URL (GT Calendar)'),
      'base' => 'node_content',
      'description' => t('A feed URL from Mercury that only contains Events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
