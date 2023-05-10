<?php

/**
 * @file
 * gt_ct_carousel_slider.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gt_ct_carousel_slider_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function gt_ct_carousel_slider_image_default_styles() {
  $styles = array();

  // Exported image style: slide_overlay_image.
  $styles['slide_overlay_image'] = array(
    'name' => 'slide_overlay_image',
    'label' => 'Slide Overlay Image',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1024,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function gt_ct_carousel_slider_node_info() {
  $items = array(
    'gt_ct_carousel' => array(
      'name' => t('Carousel'),
      'base' => 'node_content',
      'description' => t('A rotating carousel that uses the Carousel Slide content type.'),
      'has_title' => '1',
      'title_label' => t('Carousel Name'),
      'help' => t('Provide the carousel slides that this carousel uses, and order them in the way that you want them to appear (order goes from the top of the list to the bottom.) '),
    ),
    'gt_ct_carousel_slide' => array(
      'name' => t('Carousel Slide'),
      'base' => 'node_content',
      'description' => t('Slides for rotating image carousels.'),
      'has_title' => '1',
      'title_label' => t('Description'),
      'help' => '',
    ),
  );
  return $items;
}
