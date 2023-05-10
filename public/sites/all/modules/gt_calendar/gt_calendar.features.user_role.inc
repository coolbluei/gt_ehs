<?php
/**
 * @file
 * gt_calendar.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function gt_calendar_user_default_roles() {
  $roles = array();

  // Exported role: GT Calendar Manager.
  $roles['GT Calendar Manager'] = array(
    'name' => 'GT Calendar Manager',
    'weight' => 5,
  );

  return $roles;
}
