<?php
/**
 * @file
 * gt_editor.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function gt_editor_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-editor-menu.
  $menus['menu-editor-menu'] = array(
    'menu_name' => 'menu-editor-menu',
    'title' => 'My Links',
    'description' => 'The <em>Editor</em> menu contains default links for editing site content.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My Links');
  t('The <em>Editor</em> menu contains default links for editing site content.');


  return $menus;
}
