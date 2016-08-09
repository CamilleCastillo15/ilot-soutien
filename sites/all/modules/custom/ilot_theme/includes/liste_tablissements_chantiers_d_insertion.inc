<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_liste_tablissements_chantiers_d_insertion(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $variables['views_liste_etablissements'] = views_embed_view('liste_etablissements');
    $variables['views_liste_chantiers_insertion'] = views_embed_view('liste_chantiers_insertion');
  }
}







