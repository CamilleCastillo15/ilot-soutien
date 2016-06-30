<?php

function gd_donate_admin_form($form, &$form_state) {

  $form = system_settings_form($form);

  $form['gd_donate_monthly_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Monthly donation options'),
    '#description' => t('List of options, one by line, key value separated by a pipe character'),
    '#default_value' => gd_donate_admin_form_unprocess_options(variable_get('gd_donate_monthly_options')),
    '#element_validate' => array('gd_donate_admin_form_options_process'),
  );

  $form['gd_donate_unique_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Direct donation options'),
    '#description' => t('List of options, one by line, key value separated by a pipe character'),
    '#default_value' => gd_donate_admin_form_unprocess_options(variable_get('gd_donate_unique_options')),
    '#element_validate' => array('gd_donate_admin_form_options_process'),
  );

  $form['gd_donate_ceiling'] = array(
    '#type' => 'textfield',
    '#title' => t('Ceiling for regular donation'),
    '#description' => t('The annual donation ceiling after wich tax deduction decrease for those who make a regular donation.'),
    '#default_value' => variable_get('gd_donate_ceiling'),
    '#element_validate' => array('gd_donate_admin_form_ceiling_process'),
  );

  $form['gd_donate_ceiling_isf'] = array(
      '#type' => 'textfield',
      '#title' => t('Ceiling for ISF donation'),
      '#description' => t('The annual donation ceiling after wich tax deduction decrease for those who make a ISF donation.'),
      '#default_value' => variable_get('gd_donate_ceiling_isf'),
      '#element_validate' => array('gd_donate_admin_form_ceiling_process'),
  );

  $form['gd_donate_answer_below_ceiling'] = array(
      '#type' => 'textfield',
      '#title' => t('Answer below ceiling'),
      '#description' => t("The answer if the donation don't exceed the ceiling donation. Use the token [donation] and [ceiling]"),
      '#size' => '256',
      '#maxlength' => '512',
      '#default_value' => variable_get('gd_donate_answer_below_ceiling'),
  );

  $form['gd_donate_answer_above_ceiling'] = array(
      '#type' => 'textfield',
      '#title' => t('Answer above ceiling'),
      '#description' => t("The answer if the donation exceed the ceiling donation. Use the token [donation] and [ceiling]"),
      '#size' => '256',
      '#maxlength' => '512',
      '#default_value' => variable_get('gd_donate_answer_above_ceiling'),
  );

  $form['gd_donate_calculate_below_ceiling'] = array(
      '#type' => 'textfield',
      '#title' => t('Calculate below the ceiling'),
      '#description' => t("Enter your own formula to calculate the tax deduction. Use the token [ceiling] and [user-amount]"),
      '#default_value' => variable_get('gd_donate_calculate_below_ceiling'),
  );

  $form['gd_donate_calculate_above_ceiling'] = array(
      '#type' => 'textfield',
      '#title' => t('Calculate above the ceiling'),
      '#description' => t("Enter your own formula to calculate the tax deduction. Use the token [ceiling] and [user-amount]"),
      '#default_value' => variable_get('gd_donate_calculate_above_ceiling'),
  );

  $form['gd_donate_activ_monthly_free'] = array(
      '#type' => 'checkbox',
      '#title' => t('Free monthly amount donation'),
      '#description' => t("Check to activate the free amount for monthly donation"),
      '#default_value' => variable_get('gd_donate_activ_monthly_free'),
  );

  $form['gd_donate_activ_unique_free'] = array(
      '#type' => 'checkbox',
      '#title' => t('Free direct amount donation'),
      '#description' => t("Check to activate the free amount for direct donation"),
      '#default_value' => variable_get('gd_donate_activ_unique_free'),
  );

  $form['gd_donate_activ_calculator'] = array(
      '#type' => 'checkbox',
      '#title' => t('Calculator'),
      '#description' => t("Check to activate the calculator"),
      '#default_value' => variable_get('gd_donate_activ_calculator'),
  );
  return $form;
}

/**
 * Convert an array of options, to the format expected in textarea.
 *
 * @param array $options
 */
function gd_donate_admin_form_unprocess_options($options) {

  $output = '';
  foreach ($options as $key => $option) {
    $output .= $key . '|' . $option . "\n";
  }
  return $output;
}


/**
 * Element validate callback.
 */
function gd_donate_admin_form_ceiling_process($element, &$form_state) {
  $value = trim($element['#value']);
  if (!is_numeric($value)) {
    form_set_error($element['#name'], t('The amount must be numeric.'), FALSE);
  }
}

/**
 * Element validate callback. Transform text option into an array.
 */
function gd_donate_admin_form_options_process($element, &$form_state) {
  $values = trim($element['#value']);
  $values = explode("\n", $values);
  $array_values = array();
  foreach ($values as $value) {
    $string_parts = explode('|', $value);
    if (!empty($string_parts[0]) && isset($string_parts[1])) {
      if (!is_numeric($string_parts[0])) {
        form_set_error($element['#name'], t('The key must be numeric.'), FALSE);
      }
      else {
        $array_values[$string_parts[0]] = $string_parts[1];
      }
    }
  }
  form_set_value($element, $array_values, $form_state);
}