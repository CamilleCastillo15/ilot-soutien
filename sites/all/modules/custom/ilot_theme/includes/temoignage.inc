<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_temoignage(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];

  // get Temoignage page :

  $path = current_path();
  $path_alias = drupal_lookup_path('alias',$path);

  if($path_alias == 'témoignages/témoignages')
  {
    $_SESSION['categorie'] = 'tout';
    $variables['lien'] = $path_alias;

  }
  elseif($path_alias == 'temoignages-residants' OR $path_alias == 'type-de-temoignage/temoignages-de-salaries' OR $path_alias == 'temoignages-de-benevoles' OR $path_alias == 'temoignages-de-donateurs' OR $path_alias == 'temoignages-partenaires')
  {
    $_SESSION['categorie'] = 'filtre';
    $variables['lien'] = $path_alias;
  }
  else
  {

  }

  // Navigation prev/next:

    if ($variables['view_mode'] == 'full') {

      if(isset($_SESSION['categorie']) AND $_SESSION['categorie'] == 'filtre')
      {

        // get temoignage type tid :
        $value_tid = $variables['node']->field_temoignage_type[LANGUAGE_NONE][0]['tid'];

        // previous
        $query = db_select('node', 'n');
        $query->leftJoin('publication_date', 'date', 'n.nid = date.nid');
        $query->leftJoin('taxonomy_index', 'taxonomy', 'n.nid = taxonomy.nid');
        $query->fields('n',array('nid'));
        $query->condition('n.status', 1,'=');
        $query->condition('n.type', $node->type);
        $query->condition('taxonomy.tid', $value_tid);
        $query->condition('date.published_at', $node->published_at, '<')
        ->orderBy('date.published_at','DESC')
        ->range(0,1);
        $prev = $query->execute()->fetchField();

        // next or false if none
        $query = db_select('node', 'n');
        $query->leftJoin('publication_date', 'date', 'n.nid = date.nid');
        $query->leftJoin('taxonomy_index', 'taxonomy', 'n.nid = taxonomy.nid');
        $query->fields('n',array('nid'));
        $query->condition('n.status', 1,'=');
        $query->condition('n.type', $node->type);
        $query->condition('taxonomy.tid', $value_tid);
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
      else
      {

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

  } // end view mode

}
