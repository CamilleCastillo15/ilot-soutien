<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_page_editoriale(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

  }
}