<?php
/**
 * @file
 * gt_editor.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function gt_editor_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-editor-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-editor-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Administrator' => 4,
      'Editor' => 3,
      'Super Administrator' => 5,
    ),
    'themes' => array(
      'gt_subtheme' => array(
        'region' => 'right',
        'status' => 1,
        'theme' => 'gt_subtheme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'gt_subtheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'gt_subtheme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'gt_subtheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'gt_subtheme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
