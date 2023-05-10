<?php
/**
 * @file
 * gt_editor.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function gt_editor_user_default_roles() {
  $roles = array();

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => '3',
  );
  
  // Exported role: Administrator.
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => '4',
  );  

  // Exported role: Super Administrator.
  $roles['Super Administrator'] = array(
    'name' => 'Super Administrator',
    'weight' => '5',
  );

  return $roles;
}
