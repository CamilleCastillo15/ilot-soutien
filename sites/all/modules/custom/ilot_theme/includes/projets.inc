<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_projets(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $variables['views_actu_contextuel'] = views_embed_view('actualites_contextuel', 'default');

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
