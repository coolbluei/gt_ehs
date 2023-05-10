<?php
/**
 * Georgia Institute of Technology Mercury Feed Reader — Admin stuff
 *
 * This file contains stuff related to administration of Hg Reader
 *
 * @author Office of Communications and Marketing <web@comm.gatech.edu>
 *
 */

/**
 * Administration form
 */
function hg_reader_settings() {
  $form['hg_cache'] = array(
    '#type' => 'fieldset',
    '#title' => 'Cache settings',
  );
  $form['hg_cache']['hg_cache_location'] = array(
    '#type' => 'textfield',
    '#description' => 'This must be a path relative to your Drupal root.',
    '#default_value' => variable_get('hg_cache_location', file_default_scheme() . '://hg/cache' . '/'),
    '#title' => 'Cache location',
    '#required' => TRUE,
    '#after_build' => array('system_check_directory'),
  );
  $form['hg_cache']['hg_cache_item_timeout'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hg_cache_item_timeout', 3600),
    '#title' => 'Feed/node cache timeout',
    '#required' => TRUE,
  );
  $form['hg_cache']['hg_cache_file_timeout'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hg_cache_file_timeout', 86400),
    '#title' => 'File cache timeout',
    '#required' => TRUE,
  );
  $form['hg_misc'] = array(
    '#type' => 'fieldset',
    '#title' => 'Miscellaneous settings',
  );
  $form['hg_misc']['hg_feed_xsl'] = array(
    '#type'=> 'textfield',
    '#description' => 'This must be a path relative to your Drupal root.',
    '#default_value' => variable_get('hg_feed_xsl', drupal_get_path('module', 'hg_reader') . '/xsl/hgSerializedFeed.xsl'),
    '#title' => 'Serialized feed XSL',
    '#required' => TRUE,
    '#after_build' => array('hg_reader_file_check_exists'),
  );
  $form['hg_misc']['hg_item_xsl'] = array(
    '#type'=> 'textfield',
    '#description' => 'This must be a path relative to your Drupal root.',
    '#default_value' => variable_get('hg_item_xsl', drupal_get_path('module', 'hg_reader') . '/xsl/hgSerializedItem.xsl'),
    '#title' => 'Serialized item XSL',
    '#required' => TRUE,
    '#after_build' => array('hg_reader_file_check_exists'),
  );
  $form['hg_misc']['hg_curl_timeout'] = array(
    '#type'=> 'textfield',
    '#description' => 'Please do not set this higher than 30 seconds unless you have a very good reason.',
    '#default_value' => variable_get('hg_curl_timeout', 10),
    '#title' => 'Curl timeout',
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
