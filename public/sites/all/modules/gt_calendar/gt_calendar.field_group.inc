<?php
/**
 * @file
 * gt_calendar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gt_calendar_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|event|default';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For More Information Contact',
    'weight' => '5',
    'children' => array(
      0 => 'field_event_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'For More Information Contact',
      'instance_settings' => array(
        'classes' => 'hg-sidebar hg-event-contact group-event-contact field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_event_full_group_event_contact',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_event_contact|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_details|node|event|default';
  $field_group->group_name = 'group_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_event_body',
      1 => 'field_event_url_related',
      2 => 'field_event_image',
      3 => 'field_event_attachment_url',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Event Details',
      'instance_settings' => array(
        'classes' => 'hg-sidebar hg-event-details group-event-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_event_full_group_event_details',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_event_details|node|event|default'] = $field_group;

  return $export;
}
