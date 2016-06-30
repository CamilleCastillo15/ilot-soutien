<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_actualites(&$variables, $hook) {
  $wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];

  //Get date
  $time = $wrapper->field_actualite_date->value();
  if ($time) {
    $month = format_date($time, 'custom', 'M');
    $day = format_date($time, 'custom', 'd');
    $year = format_date($time, 'custom', 'Y');
    $date_article = '<div class="date-actualite"><div class="jour">' . $day .'</div><div class="mois">' . $month . '</div><div class="annee">' . $year . '</div></div>';
    $variables['actualites_date'] = $date_article;
  }
  if ($variables['view_mode'] == 'teaser' || $variables['view_mode'] == 'contextual_teaser') {
    //Get auteur
      $auteur = $wrapper->field_actualite_auteur_nom->value();
    if(!empty($auteur)) {
      if (strpos($auteur, '|') !== FALSE) {
        $auteur = str_replace('|', '<div class="auteur-bold">', $auteur);
        $auteur .= '</div>';
      }
      $variables['auteur'] = $auteur;
    }
  }

  if ($variables['view_mode'] == 'contextual_teaser') {
    //Get date
    $time = $wrapper->field_actualite_date->value();
    if ($time) {
      $date = format_date($time, 'custom', 'd F Y');
      $date_article = '<div class="date-actualite-long">' . $date . '</div>';
      $variables['actualites_date'] = $date_article;
    }
  }

  if ($variables['view_mode'] == 'full') {
    //Get auteur
      $auteur = $wrapper->field_actualite_auteur_nom->value();
    if(!empty($auteur)) {
      if (strpos($auteur, '|') !== FALSE) {
        $auteur = str_replace('|', ' ', $auteur);
      }
      $variables['auteur'] = $auteur;
    }

    // previous
    $query = db_select('node', 'n');
    $query->leftJoin('publication_date', 'date', 'n.nid = date.nid');
    $query->fields('n',array('nid'));
    $query->condition('n.status', 1,'=');
    $query->condition('n.type', $node->type);
    $query->condition('date.published_at', $node->published_at, '<')
    ->orderBy('date.published_at','DESC')
    ->range(0,1);
    $prev = $query->execute()->fetchField();

    // next or false if none
    $query = db_select('node', 'n');
    $query->leftJoin('publication_date', 'date', 'n.nid = date.nid');
    $query->fields('n',array('nid'));
    $query->condition('n.status', 1,'=');
    $query->condition('n.type', $node->type);
    $query->condition('date.published_at', $node->published_at, '>');
    $query->orderBy('date.published_at','ASC');
    $query->range(0,1);
    $next = $query->execute()->fetchField();


    if($next){
      $variables['next'] = $next;
    }
    if($prev){
      $variables['prev'] = $prev;
    }
  }
}
