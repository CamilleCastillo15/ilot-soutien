<?php
/**
 * @file
 * ilot_partenaires.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_partenaires_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_partenaires_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_partenaires_node_info() {
  $items = array(
    'liste_partenaire' => array(
      'name' => t('Liste partenaire'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'partenaire' => array(
      'name' => t('Partenaire'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
