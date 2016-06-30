<?php

/**
 * @file
 * Hooks provided by the GD Donate module.
 */

/**
 * Implements hook_gd_donate_ajax_donation_type_refresh_alter().
 *
 * Alter the gd_donate_ajax_donation_type_refresh function to add ajax_command
 * affecting other content.
 *
 * @param &$commands
 *   The commands array to alter in order to add ajax_command
 * @param $context
 *   An array with $form and $form_state
 */
function hook_theme_gd_donate_ajax_donation_type_refresh_alter(&$commands, $context) {
  //Check if there is values in the form_state array.
  $values = $context['form_state']['values'];
  if (empty($values)) {
    $donation_type = 'don_normal';
  }
  elseif (isset($values['gd_donate'])) {
    $donation_type = $values['gd_donate']['donation_type'] ? $values['gd_donate']['donation_type'] : 'don_normal';
  }
  else {
    $donation_type = $values['donation_type'] ? $values['donation_type'] : 'don_normal';
  }
  //Add ajax_command_invoke to $commands to hide/show other pane content.
  if ($donation_type == 'don_normal') {
    $commands[] = ajax_command_invoke('#selector', 'show');
    $commands[] = ajax_command_invoke('#selector2', 'hide');
  }
  else {
    $commands[] = ajax_command_invoke('#selector', 'hide');
    $commands[] = ajax_command_invoke('#selector2', 'show');
  }
}
