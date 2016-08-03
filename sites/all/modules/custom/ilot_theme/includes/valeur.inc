<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_valeur(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {
    $variables['views_temoignages_contextuel'] = views_embed_view('temoignages_contextuel', 'default', $node->nid);
  }
}







