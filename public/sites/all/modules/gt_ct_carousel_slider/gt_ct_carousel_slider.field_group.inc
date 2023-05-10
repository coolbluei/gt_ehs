<?php
/**
 * @file
 * gt_ct_carousel_slider.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gt_ct_carousel_slider_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gtct_cs_img_settings|node|gt_ct_carousel_slide|form';
  $field_group->group_name = 'group_gtct_cs_img_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gt_ct_carousel_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_gtct_cs_bg_image',
      1 => 'field_gtct_cs_overlay_image',
      2 => 'field_gtct_cs_title_gt_color',
      3 => 'field_gtct_cs_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gtct-cs-img-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gtct_cs_img_settings|node|gt_ct_carousel_slide|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gtct_cs_title_settings|node|gt_ct_carousel_slide|form';
  $field_group->group_name = 'group_gtct_cs_title_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gt_ct_carousel_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title Settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_gtct_cs_title',
      1 => 'field_gtct_cs_title_graphic',
      2 => 'field_gtct_cs_title_placement',
      3 => 'field_gtct_cs_summary_sentence',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gtct-cs-title-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gtct_cs_title_settings|node|gt_ct_carousel_slide|form'] = $field_group;

  return $export;
}
