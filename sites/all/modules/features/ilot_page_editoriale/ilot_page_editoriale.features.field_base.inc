<?php
/**
 * @file
 * ilot_page_editoriale.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ilot_page_editoriale_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_page_editoriale_corps'
  $field_bases['field_page_editoriale_corps'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_page_editoriale_corps',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
