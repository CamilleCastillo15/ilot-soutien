<?php
/**
 * @file
 * ilot_rapport_activite.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_rapport_activite_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_rapport_activite_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_rapport_activite_node_info() {
  $items = array(
    'liste_rapport_activite' => array(
      'name' => t('Liste rapport activite'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'rapport_activite' => array(
      'name' => t('Rapport d\'activité'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
