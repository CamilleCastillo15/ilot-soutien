<?php
/**
 * @file
 * ilot_profile.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ilot_profile_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_customer_profile-billing-field_billing_telephone'
  $field_instances['commerce_customer_profile-billing-field_billing_telephone'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -8,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_billing_telephone',
    'label' => 'Téléphone',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Téléphone');

  return $field_instances;
}
