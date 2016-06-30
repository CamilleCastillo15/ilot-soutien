<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_accueil(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $variables['views_accueil_actu'] = views_embed_view('accueil_actu');
    $variables['views_accueil_mosaique_temoignage'] = views_embed_view('mosaique_accueil');
    $variables['views_accueil_mosaique_projet'] = views_embed_view('mosaique_accueil_projet');
    $variables['views_accueil_chiffres'] = views_embed_view('accueil_chiffres');
  }
}



