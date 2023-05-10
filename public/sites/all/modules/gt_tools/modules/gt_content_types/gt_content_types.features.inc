<?php
/**
 * @file
 * gt_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gt_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function gt_content_types_node_info() {
  $items = array(
    'horizontal_landing_page' => array(
      'name' => t('Horizontal landing page'),
      'base' => 'node_content',
      'description' => t('Horizontal landing pages provide four rows stacked horizontally below the main body copy where blocks can be included. Node entities that are available as blocks via the nodeblock module can be placed within the four horizontal rows. This content type is ideal for organizing page content into a horizontal format.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'multipurpose_page' => array(
      'name' => t('Multipurpose page'),
      'base' => 'node_content',
      'description' => t('Multipurpose pages provide three separate fields for body copy, plus a horizontal row below each body copy element where blocks of related content can be placed. Each body copy element can include a sidebar, which also allows blocks of related content. This content type is ideal for breaking up content-heavy pages into separate sections.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'vertical_landing_page' => array(
      'name' => t('Vertical landing page'),
      'base' => 'node_content',
      'description' => t('Vertical landing pages provide two vertical columns for related content blocks below an optional main body copy area. This content type is ideal for organizing page content into a vertical format.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
