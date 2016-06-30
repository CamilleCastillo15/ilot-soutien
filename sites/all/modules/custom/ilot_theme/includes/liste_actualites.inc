<?php

/**
 * Implement hook_preprocess_node_type().
 */
function ilot_theme_preprocess_node_liste_actualites(&$variables, $hook) {
  if ($variables['view_mode'] == 'full') {
    $wrapper = entity_metadata_wrapper('node', $variables['node']);
    $node = $variables['node'];

    $variables['content']['archive_article'] = ilot_theme_get_archive_article($node, $wrapper);
    $archive = 'all';

    if (isset($_GET['archive'])) {
      $archive = $_GET['archive'];
    }

    $variables['views_liste_actu'] = views_embed_view('liste_actu', 'default', $archive);
  }
}

/**
 * Prepare the block 'archive d'article'
 * @param $node
 * @param $wrapper
 */
function ilot_theme_get_archive_article($node, $wrapper = NULL) {
  $get_key = 'archive';

  $query = db_select('node', 'n');
  $query->condition('n.type', 'actualites');
  $query->condition('n.status', 1);

  $query->leftJoin('field_data_field_actualite_date', 'date', 'n.nid = date.entity_id');
  $query->addField('date', 'field_actualite_date_value');
  $results = $query->execute()->fetchAll();
  if (empty($results)) {
    return array();
  }
  $dates = array();
  $dates_display = array();
  foreach ($results as $result) {

    $date = explode('T', $result->field_actualite_date_value);
    $date = $date[0];
    $date = DateTime::createFromFormat('Y-m-d', $date);
    $timestamp = $date->format('U');
    $month = date('m', $timestamp);
    $year = date('Y', $timestamp);
    if (isset($i[$year . '-' . $month])) {
      $i[$year . '-' . $month] += 1;
    }
    else {
      $i[$year . '-' . $month] = 1;
    }
    if (in_array($year . '-' . $month, $dates)){
      continue;
    }
    $dates[] = $year . '-' . $month;
    $dates_display[] = format_date($timestamp, 'custom', 'F Y');
  }
  $items = array();
  foreach ($dates as $key => $date) {

    $options = array(
      'html' => TRUE,
      'query' => array(
        $get_key => $date,
      ),
      'attributes'=> array(
        'class' => array(),
      ),
    );
    if (isset($_GET[$get_key]) && ($_GET[$get_key] == $date)) {
      $options['attributes']['class'][] = 'active_sort';
    }
    $items[] = l($dates_display[$key] . ' <span> (' . $i[$date] . ') </span>', current_path(), $options);

  }

  $content = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#type' => 'ul',
    '#title' => t('Archives'),
    '#attributes' => array(),
  );
  return $content;
}
