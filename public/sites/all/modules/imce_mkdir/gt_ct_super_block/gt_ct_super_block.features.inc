<?php
/**
 * @file
 * gt_ct_super_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gt_ct_super_block_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function gt_ct_super_block_node_info() {
  $items = array(
    'super_block' => array(
      'name' => t('Super Block'),
      'base' => 'node_content',
      'description' => t('Dynamic callout/highlight elements that are pulled into pages via block reference fields.'),
      'has_title' => '1',
      'title_label' => t('Description'),
      'help' => t('Enter a Description that will be easy to find in a long list of blocks. For example, Block - Homepage - Contact Info'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
