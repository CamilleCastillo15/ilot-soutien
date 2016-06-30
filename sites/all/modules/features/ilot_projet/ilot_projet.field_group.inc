<?php
/**
 * @file
 * ilot_projet.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ilot_projet_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|projets|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'projets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '10',
    'children' => array(
      0 => 'field_projet_mail',
      1 => 'field_projet_nom',
      2 => 'field_projet_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contact|node|projets|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contenu|node|projets|form';
  $field_group->group_name = 'group_contenu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'projets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenu texte',
    'weight' => '6',
    'children' => array(
      0 => 'field_projet_contenu',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contenu texte',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-contenu field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contenu|node|projets|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_encart|node|projets|form';
  $field_group->group_name = 'group_encart';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'projets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Encart Information',
    'weight' => '9',
    'children' => array(
      0 => 'field_projet_info_sous_titre',
      1 => 'field_projet_info_titre',
      2 => 'field_projet_liste_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Encart Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-encart field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_encart|node|projets|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image|node|projets|form';
  $field_group->group_name = 'group_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'projets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '5',
    'children' => array(
      0 => 'field_projet_image_accroche',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-image field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_image|node|projets|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_primary|node|projets|form';
  $field_group->group_name = 'group_info_primary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'projets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Encart premiére(s) information(s)',
    'weight' => '8',
    'children' => array(
      0 => 'field_projet_info_primary_texte',
      1 => 'field_projet_info_primary_titre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Encart premiére(s) information(s)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-info-primary field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_info_primary|node|projets|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_temoin|node|projets|form';
  $field_group->group_name = 'group_temoin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'projets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Témoignage',
    'weight' => '7',
    'children' => array(
      0 => 'field_projet_temoignage_titre',
      1 => 'field_projet_temoin_citation',
      2 => 'field_projet_temoin_sous_titre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Témoignage',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-temoin field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_temoin|node|projets|form'] = $field_group;

  return $export;
}
