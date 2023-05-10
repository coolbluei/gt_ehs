<?php
/**
 * @file
 * gt_editor.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function gt_editor_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-editor-menu_add-or-change-events-mercury:http://hg.gatech.edu/cas?destination=front_page
  $menu_links['menu-editor-menu_add-or-change-events-mercury:http://hg.gatech.edu/cas?destination=front_page'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'http://hg.gatech.edu/cas?destination=front_page',
    'router_path' => '',
    'link_title' => 'add or change Events (Mercury)',
    'options' => array(
      'identifier' => 'menu-editor-menu_add-or-change-events-mercury:http://hg.gatech.edu/cas?destination=front_page',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_change-menu-links:admin/structure/menu/manage/main-menu
  $menu_links['menu-editor-menu_change-menu-links:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'change Menu links',
    'options' => array(
      'identifier' => 'menu-editor-menu_change-menu-links:admin/structure/menu/manage/main-menu',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_find-pages-list:admin/content
  $menu_links['menu-editor-menu_find-pages-list:admin/content'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'find Pages (list)',
    'options' => array(
      'identifier' => 'menu-editor-menu_find-pages-list:admin/content',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_get-new-events-mercury-cache:http://mysite.gatech.edu/?clearcache=1
  $menu_links['menu-editor-menu_get-new-events-mercury-cache:http://mysite.gatech.edu/?clearcache=1'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'http://mysite.gatech.edu/?clearcache=1',
    'router_path' => '',
    'link_title' => 'get new Events (Mercury cache)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editor-menu_get-new-events-mercury-cache:http://mysite.gatech.edu/?clearcache=1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_move-blocks:admin/structure/block
  $menu_links['menu-editor-menu_move-blocks:admin/structure/block'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'move Blocks',
    'options' => array(
      'identifier' => 'menu-editor-menu_move-blocks:admin/structure/block',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_new-block:admin/structure/block/add
  $menu_links['menu-editor-menu_new-block:admin/structure/block/add'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'admin/structure/block/add',
    'router_path' => 'admin/structure/block/add',
    'link_title' => 'new Block',
    'options' => array(
      'identifier' => 'menu-editor-menu_new-block:admin/structure/block/add',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_new-horizontal-layout:node/add/horizontal-landing-page
  $menu_links['menu-editor-menu_new-horizontal-layout:node/add/horizontal-landing-page'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'node/add/horizontal-landing-page',
    'router_path' => 'node/add/horizontal-landing-page',
    'link_title' => 'new Horizontal layout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editor-menu_new-horizontal-layout:node/add/horizontal-landing-page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_new-multipurpose-layout:node/add/multipurpose-page
  $menu_links['menu-editor-menu_new-multipurpose-layout:node/add/multipurpose-page'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'node/add/multipurpose-page',
    'router_path' => 'node/add/multipurpose-page',
    'link_title' => 'new Multipurpose layout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editor-menu_new-multipurpose-layout:node/add/multipurpose-page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_new-page:node/add/page
  $menu_links['menu-editor-menu_new-page:node/add/page'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'new Page',
    'options' => array(
      'identifier' => 'menu-editor-menu_new-page:node/add/page',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-editor-menu_new-vertical-layout:node/add/vertical-landing-page
  $menu_links['menu-editor-menu_new-vertical-layout:node/add/vertical-landing-page'] = array(
    'menu_name' => 'menu-editor-menu',
    'link_path' => 'node/add/vertical-landing-page',
    'router_path' => 'node/add/vertical-landing-page',
    'link_title' => 'new Vertical layout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editor-menu_new-vertical-layout:node/add/vertical-landing-page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('add or change Events (Mercury)');
  t('change Menu links');
  t('find Pages (list)');
  t('get new Events (Mercury cache)');
  t('move Blocks');
  t('new Block');
  t('new Horizontal layout');
  t('new Multipurpose layout');
  t('new Page');
  t('new Vertical layout');


  return $menu_links;
}
