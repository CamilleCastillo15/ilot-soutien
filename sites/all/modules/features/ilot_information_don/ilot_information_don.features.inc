<?php
/**
 * @file
 * ilot_information_don.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_information_don_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_information_don_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_information_don_node_info() {
  $items = array(
    'info_don' => array(
      'name' => t('Information don'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
