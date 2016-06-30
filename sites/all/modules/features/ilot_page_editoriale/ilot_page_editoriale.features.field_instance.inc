<?php
/**
 * @file
 * ilot_page_editoriale.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ilot_page_editoriale_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-page_editoriale-field_page_editoriale_corps'
  $field_instances['node-page_editoriale-field_page_editoriale_corps'] = array(
    'bundle' => 'page_editoriale',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contextual_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_page_editoriale_corps',
    'label' => 'Corps',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Corps');

  return $field_instances;
}
