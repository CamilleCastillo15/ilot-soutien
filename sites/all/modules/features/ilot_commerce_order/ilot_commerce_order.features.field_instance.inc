<?php
/**
 * @file
 * ilot_commerce_order.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ilot_commerce_order_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_order-commerce_order-field_generate_account'
  $field_instances['commerce_order-commerce_order-field_generate_account'] = array(
    'bundle' => 'commerce_order',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'commerce_order',
    'field_name' => 'field_generate_account',
    'label' => 'Generer un numero de donateur',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'commerce_order-commerce_order-field_numero_donateur'
  $field_instances['commerce_order-commerce_order-field_numero_donateur'] = array(
    'bundle' => 'commerce_order',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'commerce_order',
    'field_name' => 'field_numero_donateur',
    'label' => 'Numéro de donateur',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Generer un numero de donateur');
  t('Numéro de donateur');

  return $field_instances;
}
