<?php
/**
 * @file
 * ilot_edito.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_edito_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_edito_node_info() {
  $items = array(
    'edito' => array(
      'name' => t('Édito'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
