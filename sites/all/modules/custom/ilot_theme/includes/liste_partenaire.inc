<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_liste_partenaire(&$variables, $hook) {
  //$wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {

    $voc = taxonomy_vocabulary_machine_name_load('type_partner');
    $tree = taxonomy_get_tree($voc->vid);
    $type_partner = 'all';
    if (isset($_GET['partenaire']) && is_numeric($_GET['partenaire'])) {
    	$type_partner = $_GET['partenaire'];
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
        'query' => array('partenaire' => $term->tid),
      );
      if ($term->tid == $type_partner) {
      	$options['attributes']['class'] = array('active-sort');
      }
      $block_filters['#items'][] = l('<span>' . $term->name . '</span>', current_path(), $options);
    }
    $variables['content']['block_filters'] = $block_filters;
    $variables['views_liste_partenaire'] = views_embed_view('liste_partenaire', 'default', $type_partner);
  }
}







