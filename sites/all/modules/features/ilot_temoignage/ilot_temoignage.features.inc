<?php
/**
 * @file
 * ilot_temoignage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_temoignage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_temoignage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_temoignage_node_info() {
  $items = array(
    'liste_temoignage' => array(
      'name' => t('Liste de témoignages'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'temoignage' => array(
      'name' => t('Témoignage'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
