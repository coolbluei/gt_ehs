<?php
/**
 * @file
 * gt_editor.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gt_editor_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create vertical_landing_page content'.
  $permissions['create vertical_landing_page content'] = array(
    'name' => 'create vertical_landing_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create multipurpose_page content'.
  $permissions['create multipurpose_page content'] = array(
    'name' => 'create multipurpose_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create horizontal_landing_page content'.
  $permissions['create horizontal_landing_page content'] = array(
    'name' => 'create horizontal_landing_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any vertical_landing_page content'.
  $permissions['delete any vertical_landing_page content'] = array(
    'name' => 'delete any vertical_landing_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any multipurpose_page content'.
  $permissions['delete any multipurpose_page content'] = array(
    'name' => 'delete any multipurpose_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any horizontal_landing_page content'.
  $permissions['delete any horizontal_landing_page content'] = array(
    'name' => 'delete any horizontal_landing_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any vertical_landing_page content'.
  $permissions['edit any vertical_landing_page content'] = array(
    'name' => 'edit any vertical_landing_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any multipurpose_page content'.
  $permissions['edit any multipurpose_page content'] = array(
    'name' => 'edit any multipurpose_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any horizontal_landing_page content'.
  $permissions['edit any horizontal_landing_page content'] = array(
    'name' => 'edit any horizontal_landing_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit revisions'.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions'.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of any page content'.
  $permissions['publish revisions of any page content'] = array(
    'name' => 'publish revisions of any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'unpublish current revision'.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'use text format minimal_html'.
  $permissions['use text format minimal_html'] = array(
    'name' => 'use text format minimal_html',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format text_editor_basic'.
  $permissions['use text format text_editor_basic'] = array(
    'name' => 'use text format text_editor_basic',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revision status messages'.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions of any page content'.
  $permissions['view revisions of any page content'] = array(
    'name' => 'view revisions of any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
