<?php
/**
 * @file
 * ilot_mission.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ilot_mission_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blocs|node|mission|form';
  $field_group->group_name = 'group_blocs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mission';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Illustrations',
    'weight' => '2',
    'children' => array(
      0 => 'field_missions_blocs',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Illustrations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-blocs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_blocs|node|mission|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_textes|node|mission|form';
  $field_group->group_name = 'group_textes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mission';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Texte principal',
    'weight' => '1',
    'children' => array(
      0 => 'field_mission_missions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Texte principal',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-textes field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_textes|node|mission|form'] = $field_group;

  return $export;
}
