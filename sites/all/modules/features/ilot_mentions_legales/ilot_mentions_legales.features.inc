<?php
/**
 * @file
 * ilot_mentions_legales.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_mentions_legales_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_mentions_legales_node_info() {
  $items = array(
    'mentions_legales' => array(
      'name' => t('Mentions légales'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
