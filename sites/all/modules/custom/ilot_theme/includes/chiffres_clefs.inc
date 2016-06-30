<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_chiffres_clefs(&$variables, $hook) {
  $wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'teaser') {
    //get and rewrite number markup
    $chiffres = $wrapper->field_chiffres_clefs_chiffre->value();
    if (strpos($chiffres, '|') !== FALSE) {
      $chiffres = str_replace('|', '</span>', $chiffres);
      $chiffres = '<span class="chiffre-bold">'.$chiffres;
    }
    $variables['chiffres_clefs'] = $chiffres;
  }
  if ($variables['view_mode'] == 'full') {
    //get and rewrite number markup
    $chiffres = $wrapper->field_chiffres_clefs_chiffre->value();
    if (strpos($chiffres, '|') !== FALSE) {
      $chiffres = str_replace('|', '</h1><h2>', $chiffres);
      $chiffres = '<h1>'.$chiffres;
      $chiffres .= '</h2>';
    }
    $variables['chiffres_clefs'] = $chiffres;
  }
  if ($variables['view_mode'] == 'short_teaser') {
    //get and rewrite number markup
    $chiffres = $wrapper->field_chiffres_clefs_chiffre->value();
    if (strpos($chiffres, '|') !== FALSE) {
      $chiffres = str_replace('|', '</h1><h2>', $chiffres);
      $chiffres = '<h1>'.$chiffres;
      $chiffres .= '</h2>';
    }
    $variables['chiffres_clefs'] = $chiffres;
  }
}