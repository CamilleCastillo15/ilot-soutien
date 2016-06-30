<?php

function commerce_french_donate_admin_form($form, &$form_state) {

  $form = system_settings_form($form);

  $regular_donation = !empty($form_state['values']['commerce_french_donate_activ_regular']) ? $form_state['values']['commerce_french_donate_activ_regular'] : variable_get('commerce_french_donate_activ_regular');
  $isf_donation = !empty($form_state['values']['commerce_french_donate_activ_isf']) ? $form_state['values']['commerce_french_donate_activ_isf'] : variable_get('commerce_french_donate_activ_isf');
  $mecenat_donation = !empty($form_state['values']['commerce_french_donate_activ_mecenat']) ? $form_state['values']['commerce_french_donate_activ_mecenat'] : variable_get('commerce_french_donate_activ_mecenat');

  $form['commerce_french_donate_monthly_options'] = array(
      '#type' => 'textarea',
      '#title' => t('Monthly donation options'),
      '#description' => t('List of options, one by line, key value separated by a pipe character'),
      '#default_value' => commerce_french_donate_admin_form_unprocess_options(variable_get('commerce_french_donate_monthly_options')),
      '#element_validate' => array('commerce_french_donate_admin_form_options_process'),
  );

  $form['commerce_french_donate_unique_options'] = array(
      '#type' => 'textarea',
      '#title' => t('Direct donation options'),
      '#description' => t('List of options, one by line, key value separated by a pipe character'),
      '#default_value' => commerce_french_donate_admin_form_unprocess_options(variable_get('commerce_french_donate_unique_options')),
      '#element_validate' => array('commerce_french_donate_admin_form_options_process'),
  );

  // Regular donation form
  $form['fieldset_regular_donation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Regular Donation type'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
    '#prefix' => '<div id="regular_activ_donation">',
    '#suffix' => '</div>',
  );

  $form['fieldset_regular_donation']['commerce_french_donate_activ_regular'] = array(
    '#type' => 'checkbox',
    '#title' => t('Activate regular donation choice'),
    '#description' => t("Check to activate the regular donation choice"),
    '#default_value' => $regular_donation,
    '#ajax' => array(
      'callback' => 'commerce_french_donate_regular_activ_refresh',
      'event' => 'change',
      'wrapper' => 'regular_activ_donation',
    ),
  );
  if ($regular_donation) {
    $form['fieldset_regular_donation']['commerce_french_donate_ceiling_regular'] = array(
      '#type' => 'textfield',
      '#title' => t('Ceiling for regular donation'),
      '#description' => t('The annual donation ceiling after wich tax deduction decrease for those who make a regular donation.'),
      '#default_value' => variable_get('commerce_french_donate_ceiling_regular'),
      '#element_validate' => array('commerce_french_donate_admin_form_ceiling_process'),
    );

    $form['fieldset_regular_donation']['commerce_french_donate_answer_regular'] = array(
      '#type' => 'textfield',
      '#title' => t('Answer below ceiling'),
      '#description' => t("The answer if the donation don't exceed the ceiling donation. Use the token [donation] and [user-amount]"),
      '#size' => '256',
      '#maxlength' => '512',
      '#default_value' => variable_get('commerce_french_donate_answer_regular'),
    );

    $form['fieldset_regular_donation']['commerce_french_donate_calculate_below_ceiling_regular'] = array(
      '#type' => 'textfield',
      '#title' => t('Calculate below the ceiling'),
      '#description' => t("Enter your own formula to calculate the tax deduction. Use the token [ceiling] and [user-amount]"),
      '#default_value' => variable_get('commerce_french_donate_calculate_below_ceiling_regular'),
    );

    $form['fieldset_regular_donation']['commerce_french_donate_calculate_above_ceiling_regular'] = array(
      '#type' => 'textfield',
      '#title' => t('Calculate above the ceiling'),
      '#description' => t("Enter your own formula to calculate the tax deduction. Use the token [ceiling] and [user-amount]"),
      '#default_value' => variable_get('commerce_french_donate_calculate_above_ceiling_regular'),
    );
    $form['fieldset_regular_donation']['commerce_french_donate_info_regular'] = array(
      '#type' => 'textfield',
      '#title' => t('Information for regular donation'),
      '#default_value' => variable_get('commerce_french_donate_info_regular'),
      '#maxlength' => '1024',
    );
  }
  // ISF donation form
  $form['fieldset_isf_donation'] = array(
      '#type' => 'fieldset',
      '#title' => t('ISF Donation type'),
      '#collapsed' => FALSE,
      '#collapsible' => FALSE,
      '#prefix' => '<div id="isf_activ_donation">',
      '#suffix' => '</div>',
  );

  $form['fieldset_isf_donation']['commerce_french_donate_activ_isf'] = array(
      '#type' => 'checkbox',
      '#title' => t('Activate ISF donation choice'),
      '#description' => t("Check to activate the ISF donation choice"),
      '#default_value' => $isf_donation,
      '#ajax' => array(
        'callback' => 'commerce_french_donate_isf_activ_refresh',
        'event' => 'change',
        'wrapper' => 'isf_activ_donation',
      ),
  );

  if ($isf_donation) {
    $form['fieldset_isf_donation']['commerce_french_donate_ceiling_isf'] = array(
      '#type' => 'textfield',
      '#title' => t('Ceiling for ISF donation'),
      '#description' => t('The annual donation ceiling after wich tax deduction decrease for those who make a ISF donation.'),
      '#default_value' => variable_get('commerce_french_donate_ceiling_isf'),
      '#element_validate' => array('commerce_french_donate_admin_form_ceiling_process'),
    );

    $form['fieldset_isf_donation']['commerce_french_donate_answer_isf'] = array(
      '#type' => 'textfield',
      '#title' => t('Answer'),
      '#description' => t("The answer if the donation don't exceed the ceiling donation. Use the token [donation] and [user-amount]"),
      '#size' => '256',
      '#maxlength' => '512',
      '#default_value' => variable_get('commerce_french_donate_answer_isf'),
    );

    $form['fieldset_isf_donation']['commerce_french_donate_calculate_below_ceiling_isf'] = array(
      '#type' => 'textfield',
      '#title' => t('Calculate below the ceiling'),
      '#description' => t("Enter your own formula to calculate the tax deduction. Use the token [ceiling] and [user-amount]"),
      '#default_value' => variable_get('commerce_french_donate_calculate_below_ceiling_isf'),
    );

    $form['fieldset_isf_donation']['commerce_french_donate_calculate_above_ceiling_isf'] = array(
      '#type' => 'textfield',
      '#title' => t('Calculate above the ceiling'),
      '#description' => t("Enter your own formula to calculate the tax deduction. Use the token [ceiling] and [user-amount]"),
      '#default_value' => variable_get('commerce_french_donate_calculate_above_ceiling_isf'),
    );
    $form['fieldset_isf_donation']['commerce_french_donate_info_isf'] = array(
      '#type' => 'textfield',
      '#title' => t('Information for ISF donation'),
      '#maxlength' => '1024',
      '#default_value' => variable_get('commerce_french_donate_info_isf'),
    );
    $form['fieldset_isf_donation']['commerce_french_donate_isf_unique_options'] = array(
      '#type' => 'textarea',
      '#title' => t('Direct donation ISF options'),
      '#description' => t('List of options, one by line, key value separated by a pipe character'),
      '#default_value' => commerce_french_donate_admin_form_unprocess_options(variable_get('commerce_french_donate_isf_unique_options')),
      '#element_validate' => array('commerce_french_donate_admin_form_options_process'),
    );
  }

  $form['commerce_french_donate_activ_monthly_free'] = array(
    '#type' => 'checkbox',
    '#title' => t('Free monthly amount donation'),
    '#description' => t("Check to activate the free amount for monthly donation"),
    '#default_value' => variable_get('commerce_french_donate_activ_monthly_free'),
  );

  $form['commerce_french_donate_activ_unique_free'] = array(
    '#type' => 'checkbox',
    '#title' => t('Free direct amount donation'),
    '#description' => t("Check to activate the free amount for direct donation"),
    '#default_value' => variable_get('commerce_french_donate_activ_unique_free'),
  );

  $form['commerce_french_donate_activ_calculator'] = array(
    '#type' => 'checkbox',
    '#title' => t('Calculator'),
    '#description' => t("Check to activate the calculator"),
    '#default_value' => variable_get('commerce_french_donate_activ_calculator'),
  );
  return $form;
}

/**
 * Ajax callback for regular activation
 */
function commerce_french_donate_regular_activ_refresh($form, $form_state) {
  return $form['fieldset_regular_donation'];
}

/**
 * Ajax callback for isf activation
 */
function commerce_french_donate_isf_activ_refresh($form, $form_state) {
  return $form['fieldset_isf_donation'];
}

/**
 * Ajax callback for regular activation
 */
function commerce_french_donate_mecenat_activ_refresh($form, $form_state) {
  return $form['fieldset_mecenat_donation'];
}

/**
 * Convert an array of options, to the format expected in textarea.
 *
 * @param array $options
 * The options array you are going to iterate
 */
function commerce_french_donate_admin_form_unprocess_options($options) {

  $output = '';
  foreach ($options as $key => $option) {
    $output .= $key . '|' . $option . "\n";
  }
  return $output;
}


/**
 * Element validate callback.
 */
function commerce_french_donate_admin_form_ceiling_process($element, &$form_state) {
  $value = trim($element['#value']);
  if (!empty($value) && !is_numeric($value)) {
    form_set_error($element['#name'], t('The amount must be numeric.'));
  }
}

/**
 * Element validate callback. Transform text option into an array.
 */
function commerce_french_donate_admin_form_options_process($element, &$form_state) {
  $values = trim($element['#value']);
  $values = explode("\n", $values);
  $array_values = array();
  foreach ($values as $value) {
    $string_parts = explode('|', $value);
    if (!empty($string_parts[0]) && isset($string_parts[1])) {
      if (!is_numeric($string_parts[0])) {
        form_set_error($element['#name'], t('The key must be numeric.'));
      }
      else {
        $array_values[$string_parts[0]] = $string_parts[1];
      }
    }
  }
  form_set_value($element, $array_values, $form_state);
}
