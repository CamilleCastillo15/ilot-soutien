<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_liste_medias(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $voc = taxonomy_vocabulary_machine_name_load('type_de_medias');
    $tree = taxonomy_get_tree($voc->vid);
    $type_medias = 'all';
//    print "test";
    if (isset($_GET['medias']) && is_numeric($_GET['medias'])) {
    	$type_medias = $_GET['medias'];
    }
    $block_filters = array(
    	'#theme' => 'item_list',
    	'#items' => array(),
    	'#title' => '',
    	'#type' => 'ul',
    	'#attributes' => array(
    	  'class' => array(
    	    'block-filters'
        ),
      ),
    );

    foreach ($tree as $term) {
      $options = array(
      	'html' => TRUE,
        'attributes' => array(),
        'query' => array('medias' => $term->tid),
      );
      if ($term->tid == $type_medias) {
      	$options['attributes']['class'] = array('active-sort');
      }
      $block_filters['#items'][] = l('<span>' . $term->name . '</span>', current_path(), $options);
    }
    $variables['content']['block_filters'] = $block_filters;
    $variables['views_liste_medias'] = views_embed_view('liste_medias', 'default', $type_medias);
//    $variables['views_liste_medias'] = views_embed_view('liste_medias');
  }
}







