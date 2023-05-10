<?php
/**
 * @file
 * gt_login.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gt_login_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
