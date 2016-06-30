<?php
/**
 * @file
 * ilot_page_editoriale.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_page_editoriale_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_page_editoriale_node_info() {
  $items = array(
    'page_editoriale' => array(
      'name' => t('Page éditoriale'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
