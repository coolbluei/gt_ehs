<?php
/**
 * @file
 * gt_ct_super_block.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function gt_ct_super_block_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-super_block-field_nbsb_image_placement'
  $field_instances['node-super_block-field_nbsb_image_placement'] = array(
    'bundle' => 'super_block',
    'default_value' => array(
      0 => array(
        'value' => 'sb-image-left',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select an image placement option. This applies to when a super block sits alone in a region, or is set to be the full width of the region. The image will not take up the entire width of the block so you need to select whether it sits to the left, or right of the teaser text.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_image_placement',
    'label' => 'Image placement',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-super_block-field_nbsb_jump_link'
  $field_instances['node-super_block-field_nbsb_jump_link'] = array(
    'bundle' => 'super_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide the URL and title for a jump link (if required.) This will serve as the standard "read more" link that typically sits below the teaser text.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_jump_link',
    'label' => 'Jump link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'linkit' => array(
        'button_text' => 'Link to a page or file on this site',
        'enable' => 1,
        'profile' => 'basic_field',
      ),
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-super_block-field_nbsb_jump_link_location'
  $field_instances['node-super_block-field_nbsb_jump_link_location'] = array(
    'bundle' => 'super_block',
    'default_value' => array(
      0 => array(
        'value' => 'bottom',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a location for the jump link. It can be below the teaser, as an overlay in the lower right of the image (provided an image was uploaded,) or both.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_jump_link_location',
    'label' => 'Jump link location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-super_block-field_nbsb_primary_image'
  $field_instances['node-super_block-field_nbsb_primary_image'] = array(
    'bundle' => 'super_block',
    'deleted' => 0,
    'description' => 'Upload an image to serve as the primary image/graphic for this super block.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_primary_image',
    'label' => 'Primary image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'uploads/images/superblock_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1024x1024',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-super_block-field_nbsb_skin'
  $field_instances['node-super_block-field_nbsb_skin'] = array(
    'bundle' => 'super_block',
    'default_value' => array(
      0 => array(
        'value' => 'sb-skin-standard',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a "skin" for this super block. <strong>Note:</strong> standard appearance classes will <strong><em>NOT</em></strong> be applied to Super Blocks when editing the blocks settings, but block layout options will apply.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_skin',
    'label' => 'Skin',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-super_block-field_nbsb_teaser_text'
  $field_instances['node-super_block-field_nbsb_teaser_text'] = array(
    'bundle' => 'super_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide teaser text, if required.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_teaser_text',
    'label' => 'Teaser text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-super_block-field_nbsb_title'
  $field_instances['node-super_block-field_nbsb_title'] = array(
    'bundle' => 'super_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide a title for the super block that visitors can read.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_nbsb_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image placement');
  t('Jump link');
  t('Jump link location');
  t('Primary image');
  t('Provide a title for the super block that visitors can read.');
  t('Provide teaser text, if required.');
  t('Provide the URL and title for a jump link (if required.) This will serve as the standard "read more" link that typically sits below the teaser text.');
  t('Select a "skin" for this super block. <strong>Note:</strong> standard appearance classes will <strong><em>NOT</em></strong> be applied to Super Blocks when editing the blocks settings, but block layout options will apply.');
  t('Select a location for the jump link. It can be below the teaser, as an overlay in the lower right of the image (provided an image was uploaded,) or both.');
  t('Select an image placement option. This applies to when a super block sits alone in a region, or is set to be the full width of the region. The image will not take up the entire width of the block so you need to select whether it sits to the left, or right of the teaser text.');
  t('Skin');
  t('Teaser text');
  t('Title');
  t('Upload an image to serve as the primary image/graphic for this super block.');

  return $field_instances;
}
