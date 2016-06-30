<?php
/**
 * @file
 * ilot_savoir_plus_don.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_savoir_plus_don_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_savoir_plus_don_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_savoir_plus_don_node_info() {
  $items = array(
    'don_savoir_plus' => array(
      'name' => t('En savoir plus Don'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
