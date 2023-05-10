<?php
/**
 * @file
 * gt_content_types.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function gt_content_types_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_articles_1'
  $field_bases['field_articles_1'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_articles_1',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_articles_2'
  $field_bases['field_articles_2'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_articles_2',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_articles_3'
  $field_bases['field_articles_3'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_articles_3',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_aside_1'
  $field_bases['field_aside_1'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aside_1',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_aside_2'
  $field_bases['field_aside_2'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aside_2',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_aside_3'
  $field_bases['field_aside_3'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aside_3',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_row_1'
  $field_bases['field_block_row_1'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_row_1',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_row_2'
  $field_bases['field_block_row_2'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_row_2',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_row_3'
  $field_bases['field_block_row_3'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_row_3',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_row_4'
  $field_bases['field_block_row_4'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_row_4',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_body_1'
  $field_bases['field_body_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_body_1',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_body_2'
  $field_bases['field_body_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_body_2',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_body_3'
  $field_bases['field_body_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_body_3',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_column_left'
  $field_bases['field_column_left'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_column_left',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_column_right'
  $field_bases['field_column_right'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_column_right',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'devel' => 0,
        'menu' => 0,
        'node' => 0,
        'nodeblock' => 0,
        'system' => 0,
        'user' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'content_close' => 0,
        'content_lead' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'help' => 0,
        'left' => 0,
        'left_nav' => 0,
        'main_bottom' => 0,
        'main_top' => 0,
        'right' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  return $field_bases;
}
