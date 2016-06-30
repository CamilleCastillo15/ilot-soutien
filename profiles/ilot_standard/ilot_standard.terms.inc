<?php

/**
 * Create terms in auteur taxonomy
 */
function ilot_standard_profile_create_auteur() {
  $vocabulary = taxonomy_vocabulary_machine_name_load('auteur');
  $tid = array();

  //Evénements
  $term = ilot_standard_profile_create_term_default($vocabulary);
  $term->name ="Ernest | Hemingway";
  $term->field_auteur_fonction = array(
    LANGUAGE_NONE => array(
      0 => array(
        "value" => "Ecrivain",
      ),
    ),
  );
  taxonomy_term_save($term);
  $tid['target_id'] = $term->tid;
  variable_set('ilot_standard_profile_auteur_tid', $tid);
  return $tid;
}

/**
 * Create terms in type temoignage
 */
function ilot_standard_profile_create_type_temoignage() {
	$vocabulary = taxonomy_vocabulary_machine_name_load('type_temoignage');
	$tid = array();

	// Mon témoignage
	$term = ilot_standard_profile_create_term_default($vocabulary);
	$term->name = "Témoignages de bénévole";
	taxonomy_term_save($term);

	// Mon témoignage
	$term = ilot_standard_profile_create_term_default($vocabulary);
	$term->name = "Témoignages de nos partenaires";
	taxonomy_term_save($term);
	$tid[]['target_id'] = $term->tid;
	variable_set('ilot_standard_profile_type_temoignage_tid', $term->tid);
	return $tid;
}

/**
 * Create terms in type partenaire
 */
function ilot_standard_profile_create_type_partner() {
  $vocabulary = taxonomy_vocabulary_machine_name_load('type_partner');
  $tids = array();


  $term = ilot_standard_profile_create_term_default($vocabulary);
  $term->name = "Publics";
  taxonomy_term_save($term);
  $tids[]['tid'] = $term->tid;

  $term = ilot_standard_profile_create_term_default($vocabulary);
  $term->name = "Financiers";
  taxonomy_term_save($term);
  $tids[]['tid'] = $term->tid;

  $term = ilot_standard_profile_create_term_default($vocabulary);
  $term->name = "Associatifs";
  taxonomy_term_save($term);
  $tids[]['tid'] = $term->tid;

  variable_set('ilot_standard_profile_type_partner_tids', $tids);
  return $tids;
}
/**
 * Create a default term object
 */
function ilot_standard_profile_create_term_default($vocabulary) {
  $term = new stdClass();
  $term->name = '';
  $term->description = '';
  $term->format = 'full_html';
  $term->vid = $vocabulary->vid;
  $term->vocabulary_machine_name = $vocabulary->machine_name;
  $term->tid = NULL;
  $term->weight = 0;

  return $term;
}

