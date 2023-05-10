<?php

/**
 * @file
 * gt_ct_super_block.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gt_ct_super_block_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create super_block content'.
  $permissions['create super_block content'] = array(
    'name' => 'create super_block content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any super_block content'.
  $permissions['delete any super_block content'] = array(
    'name' => 'delete any super_block content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any super_block content'.
  $permissions['edit any super_block content'] = array(
    'name' => 'edit any super_block content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'override super_block published option'.
  $permissions['override super_block published option'] = array(
    'name' => 'override super_block published option',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override super_block revision option'.
  $permissions['override super_block revision option'] = array(
    'name' => 'override super_block revision option',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'publish revisions of any super_block content'.
  $permissions['publish revisions of any super_block content'] = array(
    'name' => 'publish revisions of any super_block content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any super_block content'.
  $permissions['view revisions of any super_block content'] = array(
    'name' => 'view revisions of any super_block content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Editor' => 'Editor',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
