<?php
/**
 * @file
 * ilot_accueil.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ilot_accueil_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-accueil-field_accueil_edito'
  $field_instances['node-accueil-field_accueil_edito'] = array(
    'bundle' => 'accueil',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choisissez l\'édito qui sera affiché sur votre page d\'accueil.',
    'display' => array(
      'contextual_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'full',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'short_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_accueil_edito',
    'label' => 'Edito',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Choisissez l\'édito qui sera affiché sur votre page d\'accueil.');
  t('Edito');

  return $field_instances;
}
