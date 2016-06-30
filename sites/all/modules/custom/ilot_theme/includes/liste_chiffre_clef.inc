<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_liste_chiffre_clef(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $variables['views_liste_chiffres_clefs'] = views_embed_view('liste_chiffres_clefs');
  }
}







