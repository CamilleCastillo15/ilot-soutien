<?php
/**
 * @file
 * ilot_page_intro_categorie.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_page_intro_categorie_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_page_intro_categorie_node_info() {
  $items = array(
    'intro_categories' => array(
      'name' => t('Page intro catégories'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
