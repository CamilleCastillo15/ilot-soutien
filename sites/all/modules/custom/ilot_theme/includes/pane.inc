<?php

/**
 * checkout_pane_info settings form callback.
 */
function checkout_pane_info_don_checkout_form($form, &$form_state, $checkout_pane, $order) {
  $form['#attributes'] = array (
    'class' => array('checkout_pane_info'),
  );
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  foreach ($order_wrapper->commerce_line_items as $delta => $line_item_wrapper) {
    $line_item = $line_item_wrapper->value();
    if ($line_item->type == 'commerce_french_donate') {
      $mensualite = $line_item->field_french_donate_mensualite[LANGUAGE_NONE][0]['value'];
      $amount = commerce_currency_amount_to_decimal($line_item->commerce_unit_price[LANGUAGE_NONE][0]['amount'], commerce_default_currency());
      $donation_type = $line_item_wrapper->field_cf_donate_type_don->value();
      break;
    }
  }

  if ($donation_type == 'don_normal') {
    if (!is_null(variable_get('ilot_markup_pane_info_don', NULL))) {
      $data = variable_get('ilot_markup_pane_info_don', commerce_checkout_completion_message_default());
      $message_normal = $data['value'];
    }
    else {
      $message_normal = '';
    }
    $form['checkout_info_don'] = array(
      '#markup' => $message_normal,
    );
  }
  else {
   
    if (!is_null(variable_get('ilot_markup_pane_info_don_isf', NULL))) {
      $data = variable_get('ilot_markup_pane_info_don_isf', commerce_checkout_completion_message_default());
      $message_isf = $data['value'];
    }
    else {
      $message_isf = '';
    }
    $form['checkout_info_isf'] = array(
      '#markup' => $message_isf,
    );
  }

  $node_don_info = views_embed_view('view_don_info');

  $form['checkout_information'] = array(
      '#markup' => $node_don_info
  );

  $menu_don = menu_block_view('menu-menu-don');

  if (isset($menu_don['content'])) {
    $form['checkout_autre_soutien'] = array(
      '#prefix' => "<h2>Nous soutenir autrement</h2>",
      'content' => $menu_don['content'],
    );
  }

  $form['checkout_savoir_plus_title'] = array(
      '#markup' => '<br/><a href="/contact"></a>'
  );

  $node_don_savoir_plus = views_embed_view('view_savoir_plus_don');

  $form['checkout_savoir_plus_content'] = array(
      '#markup' => $node_don_savoir_plus
  );

  return $form;
}

function checkout_pane_info_don_settings_form($checkout_pane) {
  $form = array();

  // Find our default message and text format values.
  if (!is_null(variable_get('ilot_markup_pane_info_don', NULL))) {
    $data = variable_get('ilot_markup_pane_info_don', commerce_checkout_completion_message_default());

    $message_normal = $data['value'];
    $text_format_normal = $data['format'];
  }
  else {
    $message_normal = '';

    if (filter_format_load('full_html')) {
      $text_format_normal = 'full_html';
    }
    else {
      $text_format_normal = filter_fallback_format();
    }
  }
  // Find our default message and text format values.
  if (!is_null(variable_get('ilot_markup_pane_info_don_isf', NULL))) {
    $data = variable_get('ilot_markup_pane_info_don_isf', commerce_checkout_completion_message_default());

    $message_isf = $data['value'];
    $text_format_isf = $data['format'];
  }
  else {
    $message_isf = '';

    if (filter_format_load('full_html')) {
      $text_format_isf = 'full_html';
    }
    else {
      $text_format_isf = filter_fallback_format();
    }
  }
  $form['ilot_markup_pane_info_don'] = array(
    '#title' => t("Texte d'information - Don en ligne normal"),
    '#type' => 'text_format',
    '#default_value' => $message_normal,
    '#format' => $text_format_normal,
  );
  $form['ilot_markup_pane_info_don_isf'] = array(
    '#title' => t("Texte d'information - Don en ligne ISF"),
    '#type' => 'text_format',
    '#default_value' => $message_isf,
    '#format' => $text_format_isf,
  );

  return $form;
}

function checkout_pane_don_confiance_checkout_form() {
  $form['checkout_pane_confiance'] = array(
    '#markup' => "<img src='/sites/all/themes/ilot/images/don_en_confiance.png'><p>Association agree par le comite de la charte plateforme <span>100% securisee</span></p>",
    '#attributes' => array(
        'class' => array('checkout_pane_confiance'),
    ),
  );
  return $form;
}

function checkout_pane_don_secure_checkout_form() {
  $form['checkout_pane_secure'] = array(
    '#markup' => "<img src='/sites/all/themes/ilot/images/secure_donation.png'><p>Votre don en toute sécurité</p>",
    '#attributes' => array(
      'class' => array('checkout_pane_secure'),
    ),
  );
  return $form;
}