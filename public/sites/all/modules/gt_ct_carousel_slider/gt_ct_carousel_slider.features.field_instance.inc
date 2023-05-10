<?php

/**
 * @file
 * gt_ct_carousel_slider.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function gt_ct_carousel_slider_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-gt_ct_carousel-field_gtct_crsl_slides'
  $field_instances['node-gt_ct_carousel-field_gtct_crsl_slides'] = array(
    'bundle' => 'gt_ct_carousel',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the carousel slides to be included in this carousel. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
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
    'field_name' => 'field_gtct_crsl_slides',
    'label' => 'Slides',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_bg_color'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_bg_color'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'default_value' => array(
      0 => array(
        'value' => 'white',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a background color for the slide.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gtct_cs_bg_color',
    'label' => 'Background Color',
    'required' => 1,
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

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_bg_image'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_bg_image'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'deleted' => 0,
    'description' => 'If required, provide a background image for this slide. Optimum dimensions are ~2000px wide by ~750px tall, but make sure it\'s optimized to be the smallest file size.',
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
    'field_name' => 'field_gtct_cs_bg_image',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'uploads/images/carousel_slides/bg',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 'imce',
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_link_location'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_link_location'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide a URL that this slide will link to. The title is used as the "action" message for the link that is include with the summary sentence, provided a summary sentence is included, and no title graphic is included.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gtct_cs_link_location',
    'label' => 'Link Location',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => 'Read more',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'required',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_overlay_image'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_overlay_image'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'deleted' => 0,
    'description' => 'Overlay images will be centered in the main viewing area of the slide. Optimum dimensions are 1024px wide by 600px tall. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_gtct_cs_overlay_image',
    'label' => 'Overlay Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'uploads/images/carousel_slides/overlay',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 'imce',
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_summary_sentence'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_summary_sentence'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If required, provide a summary sentence. This will display below the title if a title graphic is not used. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gtct_cs_summary_sentence',
    'label' => 'Summary Sentence',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_title'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_title'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide a title for the slide. If you provide a link, this title will appear in the Title Box, otherwise it will be used to describe the main background image for SEO/accessibility purposes.',
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
    'field_name' => 'field_gtct_cs_title',
    'label' => 'Slide Title',
    'required' => 1,
    'settings' => array(
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_title_graphic'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_title_graphic'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'deleted' => 0,
    'description' => 'Use this field to provide a graphic treatment for the title text. File dimensions should be exactly 512px wide by 440px tall, and file types should be transparent PNG. If a title graphic is provided the title text and summary will not appear.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_gtct_cs_title_graphic',
    'label' => 'Title Graphic',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'uploads/images/carousel_slides/title_graphics',
      'file_extensions' => 'png',
      'max_filesize' => '',
      'max_resolution' => '512x440',
      'min_resolution' => '512x440',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 'imce',
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-gt_ct_carousel_slide-field_gtct_cs_title_placement'
  $field_instances['node-gt_ct_carousel_slide-field_gtct_cs_title_placement'] = array(
    'bundle' => 'gt_ct_carousel_slide',
    'default_value' => array(
      0 => array(
        'value' => 'left',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a placement for the title. Choose None to hide the title box.',
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
    'field_name' => 'field_gtct_cs_title_placement',
    'label' => 'Title Placement',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Color');
  t('Background Image');
  t('If required, provide a background image for this slide. Optimum dimensions are ~2000px wide by ~750px tall, but make sure it\'s optimized to be the smallest file size.');
  t('If required, provide a summary sentence. This will display below the title if a title graphic is not used. ');
  t('Link Location');
  t('Overlay Image');
  t('Overlay images will be centered in the main viewing area of the slide. Optimum dimensions are 1024px wide by 600px tall. ');
  t('Provide a URL that this slide will link to. The title is used as the "action" message for the link that is include with the summary sentence, provided a summary sentence is included, and no title graphic is included.');
  t('Provide a title for the slide. Depending on title treatment settings this will appear as the main title, or just be used for SEO/accessibility purposes.');
  t('Select a background color for the slide.');
  t('Select a placement for the title. ');
  t('Select the carousel slides to be included in this carousel. ');
  t('Slide Title');
  t('Slides');
  t('Summary Sentence');
  t('Title Graphic');
  t('Title Placement');
  t('Use this field to provide a graphic treatment for the title text. File dimensions should be exactly 512px wide by 440px tall, and file types should be transparent PNG. If a title graphic is provided the title text and summary will not appear.');

  return $field_instances;
}
