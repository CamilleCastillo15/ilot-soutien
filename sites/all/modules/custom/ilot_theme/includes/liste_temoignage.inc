<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_liste_temoignage(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $variables['views_liste_temoignage_entreprises'] = views_embed_view('liste_temoignage',"default", array(11));
    $variables['views_liste_temoignage_benevoles'] = views_embed_view('liste_temoignage',"default", array(8));
    $variables['views_liste_temoignage_donateurs'] = views_embed_view('liste_temoignage',"default", array(5));
    $variables['views_liste_temoignage_partenaires'] = views_embed_view('liste_temoignage',"default", array(6));
    $variables['views_liste_temoignage_residents'] = views_embed_view('liste_temoignage',"default", array(7));
    $variables['views_liste_temoignage_salaries'] = views_embed_view('liste_temoignage',"default", array(9));
  }
}







