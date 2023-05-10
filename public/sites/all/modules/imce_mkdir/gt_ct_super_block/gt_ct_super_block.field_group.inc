<?php
/**
 * @file
 * gt_ct_super_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gt_ct_super_block_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nbsb_image|node|super_block|form';
  $field_group->group_name = 'group_nbsb_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'super_block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nbsb';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '7',
    'children' => array(
      0 => 'field_nbsb_image_placement',
      1 => 'field_nbsb_primary_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-nbsb-image field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_nbsb_image|node|super_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nbsb_links|node|super_block|form';
  $field_group->group_name = 'group_nbsb_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'super_block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nbsb';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '8',
    'children' => array(
      0 => 'field_nbsb_jump_link',
      1 => 'field_nbsb_jump_link_location',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-nbsb-links field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_nbsb_links|node|super_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nbsb_styling|node|super_block|form';
  $field_group->group_name = 'group_nbsb_styling';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'super_block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nbsb';
  $field_group->data = array(
    'label' => 'Styling',
    'weight' => '9',
    'children' => array(
      0 => 'field_nbsb_skin',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nbsb-styling field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_nbsb_styling|node|super_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nbsb_text|node|super_block|form';
  $field_group->group_name = 'group_nbsb_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'super_block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nbsb';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '6',
    'children' => array(
      0 => 'field_nbsb_teaser_text',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Text',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-nbsb-text field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_nbsb_text|node|super_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nbsb|node|super_block|form';
  $field_group->group_name = 'group_nbsb';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'super_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Super Block Details',
    'weight' => '2',
    'children' => array(
      0 => 'group_nbsb_image',
      1 => 'group_nbsb_links',
      2 => 'group_nbsb_styling',
      3 => 'group_nbsb_text',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-nbsb field-group-htabs',
      ),
    ),
  );
  $field_groups['group_nbsb|node|super_block|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('Link');
  t('Styling');
  t('Super Block Details');
  t('Text');

  return $field_groups;
}
