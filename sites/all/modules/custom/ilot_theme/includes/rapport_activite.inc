<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_rapport_activite(&$variables, $hook) {
  $wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  $variables['rapport_links'] = array();
  if ($variables['view_mode'] == 'full') {
    $files = $wrapper->field_rapport_activite_fichier->value();
    foreach ($files as $file) {
      $variables['rapport_links'][] = file_create_url($file['uri']);
    }
  }
}