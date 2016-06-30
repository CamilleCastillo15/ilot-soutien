<?php
/**
 * @file
 * ilot_association.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ilot_association_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|association|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'association';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenu',
    'weight' => '3',
    'children' => array(
      0 => 'field_association_contenu',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contenu',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-content field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_content|node|association|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_donation|node|association|form';
  $field_group->group_name = 'group_donation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'association';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Phrase donation',
    'weight' => '4',
    'children' => array(
      0 => 'field_association_phrase_1',
      1 => 'field_association_phrase_2',
      2 => 'field_association_phrase_bouton',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Phrase donation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-donation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_donation|node|association|form'] = $field_group;

  return $export;
}
