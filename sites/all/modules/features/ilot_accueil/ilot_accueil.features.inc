<?php
/**
 * @file
 * ilot_accueil.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_accueil_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_accueil_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_accueil_node_info() {
  $items = array(
    'accueil' => array(
      'name' => t('Accueil'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
