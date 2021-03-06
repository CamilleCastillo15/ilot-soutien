<?php
/**
 * @file
 * ilot_page_simple.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_page_simple_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_page_simple_node_info() {
  $items = array(
    'page_simple' => array(
      'name' => t('Page simple'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
