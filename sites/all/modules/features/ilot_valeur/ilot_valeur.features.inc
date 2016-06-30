<?php
/**
 * @file
 * ilot_valeur.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_valeur_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_valeur_node_info() {
  $items = array(
    'valeur' => array(
      'name' => t('Valeur'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
