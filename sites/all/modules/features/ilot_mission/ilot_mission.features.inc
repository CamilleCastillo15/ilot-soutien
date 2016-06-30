<?php
/**
 * @file
 * ilot_mission.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ilot_mission_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ilot_mission_node_info() {
  $items = array(
    'mission' => array(
      'name' => t('mission'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
