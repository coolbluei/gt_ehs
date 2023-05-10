<?php
/**
 * @file
 * gt_calendar.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gt_calendar_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear gt_calendar_importer feeds'.
  $permissions['clear gt_calendar_importer feeds'] = array(
    'name' => 'clear gt_calendar_importer feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_event_attachment_url'.
  $permissions['create field_event_attachment_url'] = array(
    'name' => 'create field_event_attachment_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_audience'.
  $permissions['create field_event_audience'] = array(
    'name' => 'create field_event_audience',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_body'.
  $permissions['create field_event_body'] = array(
    'name' => 'create field_event_body',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_boilerplate'.
  $permissions['create field_event_boilerplate'] = array(
    'name' => 'create field_event_boilerplate',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_category'.
  $permissions['create field_event_category'] = array(
    'name' => 'create field_event_category',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_contact'.
  $permissions['create field_event_contact'] = array(
    'name' => 'create field_event_contact',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_extra'.
  $permissions['create field_event_extra'] = array(
    'name' => 'create field_event_extra',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_fee'.
  $permissions['create field_event_fee'] = array(
    'name' => 'create field_event_fee',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_group'.
  $permissions['create field_event_group'] = array(
    'name' => 'create field_event_group',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_group_primary'.
  $permissions['create field_event_group_primary'] = array(
    'name' => 'create field_event_group_primary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_image'.
  $permissions['create field_event_image'] = array(
    'name' => 'create field_event_image',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_image_title'.
  $permissions['create field_event_image_title'] = array(
    'name' => 'create field_event_image_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_keyword'.
  $permissions['create field_event_keyword'] = array(
    'name' => 'create field_event_keyword',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_location'.
  $permissions['create field_event_location'] = array(
    'name' => 'create field_event_location',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_location_email'.
  $permissions['create field_event_location_email'] = array(
    'name' => 'create field_event_location_email',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_location_phone'.
  $permissions['create field_event_location_phone'] = array(
    'name' => 'create field_event_location_phone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_location_url'.
  $permissions['create field_event_location_url'] = array(
    'name' => 'create field_event_location_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_nodeid'.
  $permissions['create field_event_nodeid'] = array(
    'name' => 'create field_event_nodeid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_sidebar'.
  $permissions['create field_event_sidebar'] = array(
    'name' => 'create field_event_sidebar',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_summary'.
  $permissions['create field_event_summary'] = array(
    'name' => 'create field_event_summary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_summary_sentence'.
  $permissions['create field_event_summary_sentence'] = array(
    'name' => 'create field_event_summary_sentence',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_time'.
  $permissions['create field_event_time'] = array(
    'name' => 'create field_event_time',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_event_url_related'.
  $permissions['create field_event_url_related'] = array(
    'name' => 'create field_event_url_related',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create gt_calendar_feed content'.
  $permissions['create gt_calendar_feed content'] = array(
    'name' => 'create gt_calendar_feed content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any gt_calendar_feed content'.
  $permissions['delete any gt_calendar_feed content'] = array(
    'name' => 'delete any gt_calendar_feed content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own gt_calendar_feed content'.
  $permissions['delete own gt_calendar_feed content'] = array(
    'name' => 'delete own gt_calendar_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in event_audience'.
  $permissions['delete terms in event_audience'] = array(
    'name' => 'delete terms in event_audience',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_category'.
  $permissions['delete terms in event_category'] = array(
    'name' => 'delete terms in event_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_extra'.
  $permissions['delete terms in event_extra'] = array(
    'name' => 'delete terms in event_extra',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_group'.
  $permissions['delete terms in event_group'] = array(
    'name' => 'delete terms in event_group',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_keyword'.
  $permissions['delete terms in event_keyword'] = array(
    'name' => 'delete terms in event_keyword',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any gt_calendar_feed content'.
  $permissions['edit any gt_calendar_feed content'] = array(
    'name' => 'edit any gt_calendar_feed content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_event_attachment_url'.
  $permissions['edit field_event_attachment_url'] = array(
    'name' => 'edit field_event_attachment_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_audience'.
  $permissions['edit field_event_audience'] = array(
    'name' => 'edit field_event_audience',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_body'.
  $permissions['edit field_event_body'] = array(
    'name' => 'edit field_event_body',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_boilerplate'.
  $permissions['edit field_event_boilerplate'] = array(
    'name' => 'edit field_event_boilerplate',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_category'.
  $permissions['edit field_event_category'] = array(
    'name' => 'edit field_event_category',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_contact'.
  $permissions['edit field_event_contact'] = array(
    'name' => 'edit field_event_contact',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_extra'.
  $permissions['edit field_event_extra'] = array(
    'name' => 'edit field_event_extra',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_fee'.
  $permissions['edit field_event_fee'] = array(
    'name' => 'edit field_event_fee',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_group'.
  $permissions['edit field_event_group'] = array(
    'name' => 'edit field_event_group',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_group_primary'.
  $permissions['edit field_event_group_primary'] = array(
    'name' => 'edit field_event_group_primary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_image'.
  $permissions['edit field_event_image'] = array(
    'name' => 'edit field_event_image',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_image_title'.
  $permissions['edit field_event_image_title'] = array(
    'name' => 'edit field_event_image_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_keyword'.
  $permissions['edit field_event_keyword'] = array(
    'name' => 'edit field_event_keyword',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_location'.
  $permissions['edit field_event_location'] = array(
    'name' => 'edit field_event_location',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_location_email'.
  $permissions['edit field_event_location_email'] = array(
    'name' => 'edit field_event_location_email',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_location_phone'.
  $permissions['edit field_event_location_phone'] = array(
    'name' => 'edit field_event_location_phone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_location_url'.
  $permissions['edit field_event_location_url'] = array(
    'name' => 'edit field_event_location_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_nodeid'.
  $permissions['edit field_event_nodeid'] = array(
    'name' => 'edit field_event_nodeid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_sidebar'.
  $permissions['edit field_event_sidebar'] = array(
    'name' => 'edit field_event_sidebar',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_summary'.
  $permissions['edit field_event_summary'] = array(
    'name' => 'edit field_event_summary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_summary_sentence'.
  $permissions['edit field_event_summary_sentence'] = array(
    'name' => 'edit field_event_summary_sentence',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_time'.
  $permissions['edit field_event_time'] = array(
    'name' => 'edit field_event_time',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_url_related'.
  $permissions['edit field_event_url_related'] = array(
    'name' => 'edit field_event_url_related',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_event_attachment_url'.
  $permissions['edit own field_event_attachment_url'] = array(
    'name' => 'edit own field_event_attachment_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_audience'.
  $permissions['edit own field_event_audience'] = array(
    'name' => 'edit own field_event_audience',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_body'.
  $permissions['edit own field_event_body'] = array(
    'name' => 'edit own field_event_body',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_boilerplate'.
  $permissions['edit own field_event_boilerplate'] = array(
    'name' => 'edit own field_event_boilerplate',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_category'.
  $permissions['edit own field_event_category'] = array(
    'name' => 'edit own field_event_category',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_contact'.
  $permissions['edit own field_event_contact'] = array(
    'name' => 'edit own field_event_contact',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_extra'.
  $permissions['edit own field_event_extra'] = array(
    'name' => 'edit own field_event_extra',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_fee'.
  $permissions['edit own field_event_fee'] = array(
    'name' => 'edit own field_event_fee',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_group'.
  $permissions['edit own field_event_group'] = array(
    'name' => 'edit own field_event_group',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_group_primary'.
  $permissions['edit own field_event_group_primary'] = array(
    'name' => 'edit own field_event_group_primary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_image'.
  $permissions['edit own field_event_image'] = array(
    'name' => 'edit own field_event_image',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_image_title'.
  $permissions['edit own field_event_image_title'] = array(
    'name' => 'edit own field_event_image_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_keyword'.
  $permissions['edit own field_event_keyword'] = array(
    'name' => 'edit own field_event_keyword',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_location'.
  $permissions['edit own field_event_location'] = array(
    'name' => 'edit own field_event_location',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_location_email'.
  $permissions['edit own field_event_location_email'] = array(
    'name' => 'edit own field_event_location_email',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_location_phone'.
  $permissions['edit own field_event_location_phone'] = array(
    'name' => 'edit own field_event_location_phone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_location_url'.
  $permissions['edit own field_event_location_url'] = array(
    'name' => 'edit own field_event_location_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_nodeid'.
  $permissions['edit own field_event_nodeid'] = array(
    'name' => 'edit own field_event_nodeid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_sidebar'.
  $permissions['edit own field_event_sidebar'] = array(
    'name' => 'edit own field_event_sidebar',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_summary'.
  $permissions['edit own field_event_summary'] = array(
    'name' => 'edit own field_event_summary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_summary_sentence'.
  $permissions['edit own field_event_summary_sentence'] = array(
    'name' => 'edit own field_event_summary_sentence',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_time'.
  $permissions['edit own field_event_time'] = array(
    'name' => 'edit own field_event_time',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_url_related'.
  $permissions['edit own field_event_url_related'] = array(
    'name' => 'edit own field_event_url_related',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own gt_calendar_feed content'.
  $permissions['edit own gt_calendar_feed content'] = array(
    'name' => 'edit own gt_calendar_feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in event_audience'.
  $permissions['edit terms in event_audience'] = array(
    'name' => 'edit terms in event_audience',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_category'.
  $permissions['edit terms in event_category'] = array(
    'name' => 'edit terms in event_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_extra'.
  $permissions['edit terms in event_extra'] = array(
    'name' => 'edit terms in event_extra',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_group'.
  $permissions['edit terms in event_group'] = array(
    'name' => 'edit terms in event_group',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_keyword'.
  $permissions['edit terms in event_keyword'] = array(
    'name' => 'edit terms in event_keyword',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'import gt_calendar_importer feeds'.
  $permissions['import gt_calendar_importer feeds'] = array(
    'name' => 'import gt_calendar_importer feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock gt_calendar_importer feeds'.
  $permissions['unlock gt_calendar_importer feeds'] = array(
    'name' => 'unlock gt_calendar_importer feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'view field_event_attachment_url'.
  $permissions['view field_event_attachment_url'] = array(
    'name' => 'view field_event_attachment_url',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_audience'.
  $permissions['view field_event_audience'] = array(
    'name' => 'view field_event_audience',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_body'.
  $permissions['view field_event_body'] = array(
    'name' => 'view field_event_body',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_boilerplate'.
  $permissions['view field_event_boilerplate'] = array(
    'name' => 'view field_event_boilerplate',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_category'.
  $permissions['view field_event_category'] = array(
    'name' => 'view field_event_category',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_contact'.
  $permissions['view field_event_contact'] = array(
    'name' => 'view field_event_contact',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_extra'.
  $permissions['view field_event_extra'] = array(
    'name' => 'view field_event_extra',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_fee'.
  $permissions['view field_event_fee'] = array(
    'name' => 'view field_event_fee',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_group'.
  $permissions['view field_event_group'] = array(
    'name' => 'view field_event_group',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_group_primary'.
  $permissions['view field_event_group_primary'] = array(
    'name' => 'view field_event_group_primary',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_image'.
  $permissions['view field_event_image'] = array(
    'name' => 'view field_event_image',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_image_title'.
  $permissions['view field_event_image_title'] = array(
    'name' => 'view field_event_image_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_keyword'.
  $permissions['view field_event_keyword'] = array(
    'name' => 'view field_event_keyword',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_location'.
  $permissions['view field_event_location'] = array(
    'name' => 'view field_event_location',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_location_email'.
  $permissions['view field_event_location_email'] = array(
    'name' => 'view field_event_location_email',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_location_phone'.
  $permissions['view field_event_location_phone'] = array(
    'name' => 'view field_event_location_phone',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_location_url'.
  $permissions['view field_event_location_url'] = array(
    'name' => 'view field_event_location_url',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_nodeid'.
  $permissions['view field_event_nodeid'] = array(
    'name' => 'view field_event_nodeid',
    'roles' => array(
      'Administrator' => 'Administrator',
      'GT Calendar Manager' => 'GT Calendar Manager',
      'Super Administrator' => 'Super Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_sidebar'.
  $permissions['view field_event_sidebar'] = array(
    'name' => 'view field_event_sidebar',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_summary'.
  $permissions['view field_event_summary'] = array(
    'name' => 'view field_event_summary',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_summary_sentence'.
  $permissions['view field_event_summary_sentence'] = array(
    'name' => 'view field_event_summary_sentence',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_time'.
  $permissions['view field_event_time'] = array(
    'name' => 'view field_event_time',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_url_related'.
  $permissions['view field_event_url_related'] = array(
    'name' => 'view field_event_url_related',
    'roles' => array(
      'Super Administrator' => 'Super Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_attachment_url'.
  $permissions['view own field_event_attachment_url'] = array(
    'name' => 'view own field_event_attachment_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_audience'.
  $permissions['view own field_event_audience'] = array(
    'name' => 'view own field_event_audience',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_body'.
  $permissions['view own field_event_body'] = array(
    'name' => 'view own field_event_body',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_boilerplate'.
  $permissions['view own field_event_boilerplate'] = array(
    'name' => 'view own field_event_boilerplate',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_category'.
  $permissions['view own field_event_category'] = array(
    'name' => 'view own field_event_category',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_contact'.
  $permissions['view own field_event_contact'] = array(
    'name' => 'view own field_event_contact',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_extra'.
  $permissions['view own field_event_extra'] = array(
    'name' => 'view own field_event_extra',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_fee'.
  $permissions['view own field_event_fee'] = array(
    'name' => 'view own field_event_fee',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_group'.
  $permissions['view own field_event_group'] = array(
    'name' => 'view own field_event_group',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_group_primary'.
  $permissions['view own field_event_group_primary'] = array(
    'name' => 'view own field_event_group_primary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_image'.
  $permissions['view own field_event_image'] = array(
    'name' => 'view own field_event_image',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_image_title'.
  $permissions['view own field_event_image_title'] = array(
    'name' => 'view own field_event_image_title',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_keyword'.
  $permissions['view own field_event_keyword'] = array(
    'name' => 'view own field_event_keyword',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_location'.
  $permissions['view own field_event_location'] = array(
    'name' => 'view own field_event_location',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_location_email'.
  $permissions['view own field_event_location_email'] = array(
    'name' => 'view own field_event_location_email',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_location_phone'.
  $permissions['view own field_event_location_phone'] = array(
    'name' => 'view own field_event_location_phone',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_location_url'.
  $permissions['view own field_event_location_url'] = array(
    'name' => 'view own field_event_location_url',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_nodeid'.
  $permissions['view own field_event_nodeid'] = array(
    'name' => 'view own field_event_nodeid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_sidebar'.
  $permissions['view own field_event_sidebar'] = array(
    'name' => 'view own field_event_sidebar',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_summary'.
  $permissions['view own field_event_summary'] = array(
    'name' => 'view own field_event_summary',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_summary_sentence'.
  $permissions['view own field_event_summary_sentence'] = array(
    'name' => 'view own field_event_summary_sentence',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_time'.
  $permissions['view own field_event_time'] = array(
    'name' => 'view own field_event_time',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_url_related'.
  $permissions['view own field_event_url_related'] = array(
    'name' => 'view own field_event_url_related',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  return $permissions;
}
