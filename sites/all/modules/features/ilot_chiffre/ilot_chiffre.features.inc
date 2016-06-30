<?php
/**
 * @file
 * ilot_chiffre.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_chiffre_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ilot_chiffre_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ilot_chiffre_node_info() {
  $items = array(
    'chiffres_clefs' => array(
      'name' => t('Chiffres clefs'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'liste_chiffre_clef' => array(
      'name' => t('Liste chiffre clef'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
