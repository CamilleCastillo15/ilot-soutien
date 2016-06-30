<?php
/**
 * @file
 */

function commerce_gd_dashboard_export_bilan_comptable($form, &$form_state) {
  $form = array();
  $timestamp = mktime(0, 0, 0, 10, 1, 2013);
  $date = new DateObject($timestamp, null, 'U');
  $interval = new DateInterval('P1M');
  $last_year = new DateObject('-1 year');

  $periods = array();
  $periods_default = array();
  while(true) {
    $periods[$date->format('Y-m')] = date_format_date($date, 'custom', 'F Y');
    if ($last_year->getTimestamp() <= $date->getTimestamp()) {
      $periods_default[] = $date->format('Y-m');
    }
    $date->add($interval);
    if($date->getTimestamp() > date('U')) {
      break;
    }
  }

  $form['periods'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => $periods,
    '#default_value' => $periods_default,
    '#title' => "Mois à inclure dans l'export",
    '#required' => TRUE,
  );
  $form['format'] = array(
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => array(
      'xls' => 'Excel (Meilleur rendu et lisibité)',
      'html' => 'Voir dans le navigateur (HTML)',
    ),
    '#default_value' => array('xls' => 'Excel'),
    '#title' => "Format de l'export",
    '#required' => TRUE,
  );
  $form['submit_action'] = array(
    '#type' => 'submit',
    '#value' => "Lancer l'export",
  );
  $form['#submit'] = array('commerce_gd_dashboard_export_bilan_comptable_submit');
  return $form;
}

function commerce_gd_dashboard_export_bilan_comptable_submit(&$form, &$form_state) {
  $periods = $form_state['values']['periods'];
  $format = $form_state['values']['format'];

  $periods_arg = array();
  foreach ($periods as $period) {
    if ($period) {
      $periods_arg[] = $period;
    }
  }
  commerce_gd_dashboard_export_bilan_comptable_batch($periods_arg, $format);
}
/**
 * Menu callback of 'admin/commerce/exports/bilan-comptable'.
 *
 * Select all the datas by periods and deliver an XLS file.
 */
function commerce_gd_dashboard_export_bilan_comptable_batch($periods, $format) {

  $operations = array();
  // For each PERIODS (month)
  foreach ($periods as $period) {
    $operations[] = array('_commerce_gd_dashboard_export_create_export_orders', array($period));
  }
  $batch = array(
    'operations' => $operations,
    'title' => t("Creation de l'export comptable"),
    'error_message' => t("La création de l'export comptable à rencontré une erreur."),
    'finished' => 'commerce_gd_dashboard_export_write_bilan_comptable_' . $format,
    'init_message' => t("La création de l'export comptable commence."),
    'progress_message' => t('@current sur @total.'),
    'file' => drupal_get_path('module', 'commerce_gd_dashboard') . '/commerce_gd_dashboard.export.inc',
  );
  batch_set($batch);
}

function _commerce_gd_dashboard_export_create_export_orders($period, &$context) {
  $date = date_create_from_format('Y-m', $period);
  $timestamp = $date->format('U');
  $month_m = $date->format('m');
  $year_y = $date->format('Y');
  $date = new DateObject($timestamp);
  $format = date_format_date($date, 'custom', 'F Y');

  if (!isset($context['results']['#values'])) {
    // The values to add in the XLS.
    //  Array's of rows keyed by month.
    $values = $context['results']['#values'] = array();
  }
  else {
    $values = $context['results']['#values'];
  }

  $tax_rates = array();


  if (!isset($values)) {
    $values = array();
  }
  if (!isset($values[$format])) {
    $values[$format] = array();
    $values[$format]['orders'] = array();
    $values[$format]['num'] = '';
    $values[$format]['moyenne'] = '';
  }

  /**
   * Get ORDERS
   */
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'commerce_order');
  $query->propertyCondition('status', array('checkout_complete', 'pending', 'processing', 'completed'));

  $first_minute = mktime(0, 0, 0, $month_m, 1, $year_y);
  $last_minute = mktime(23, 59, 0, $month_m, date('t', $first_minute), $year_y);

  $query->propertyCondition('created', array($first_minute, $last_minute), 'BETWEEN');

  $entities = $query->execute();
  $orders = !empty($entities['commerce_order']) ? $entities['commerce_order']: array();

  $num_commande = 0;
  if (!empty($orders)) {
    $total = 0;
    foreach($orders as $order_id => $order_result) {
      $order = commerce_order_load($order_id);
      $num_commande++;
      $wrapper = entity_metadata_wrapper('commerce_order', $order);
      // commerce customer profile.
      $cc_profile = $wrapper->commerce_customer_billing->value();

      if (empty($cc_profile)) {
      	continue;
      }
      $cc_profile_wrapper = entity_metadata_wrapper('commerce_customer_profile', $cc_profile);

      // fields
      $line_items = $wrapper->commerce_line_items->value();
      $line_item = reset($line_items);



      $values[$format]['orders'][$order->order_id] = array();
      $values[$format]['orders'][$order->order_id]['A'] = $order->order_id;
      $values[$format]['orders'][$order->order_id]['B'] = $line_item->line_item_label;
      $values[$format]['orders'][$order->order_id]['C'] = format_date($order->created, 'long');

      $values[$format]['orders'][$order->order_id]['D'] = $wrapper->commerce_order_total->amount->value();
      // Some calc
      $total += $wrapper->commerce_order_total->amount->value();

      // Retrieve address, and country translated with addressfield_render_address().
      $cc_profile_view = entity_view('commerce_customer_profile', array($cc_profile));
      $address_view = reset($cc_profile_view['commerce_customer_profile']);
      $address_view = $address_view['commerce_customer_address'];
      $address = addressfield_render_address($address_view[0]);
      // Set address field values
      $values[$format]['orders'][$order->order_id]['E'] = $address['#address']['last_name'];
      $values[$format]['orders'][$order->order_id]['F'] = $address['#address']['first_name'];
      $values[$format]['orders'][$order->order_id]['G'] = $address['#address']['thoroughfare'] . ' ' . $address['#address']['premise'] . ' ' . $address['#address']['sub_premise'] . ' ' . $address['#address']['administrative_area'];
      $values[$format]['orders'][$order->order_id]['H'] = $address['#address']['postal_code'];
      $values[$format]['orders'][$order->order_id]['I'] = $address['#address']['locality'];
      $values[$format]['orders'][$order->order_id]['J'] = $address['country']['#children'];

      $values[$format]['orders'][$order->order_id]['K'] = $cc_profile_wrapper->field_billing_telephone->value() ? $cc_profile_wrapper->field_billing_telephone->value() : 'nc';
      $values[$format]['orders'][$order->order_id]['L'] = $cc_profile_wrapper->field_billing_email->value();
      $values[$format]['orders'][$order->order_id]['M'] = $cc_profile_wrapper->field_condition_privacy->value() == TRUE ? 'NON' : 'OUI';


    }
  }
  $values[$format]['num'] = $num_commande;
  $values[$format]['moyenne'] = $total / $num_commande;
  $context['message'] = t('Terminé : %message', array('%message' => 'Export commandes pour le mois de ' . $format . ''));
  $context['results']['#values'] = $values;
}



/**
 * Batch 'finished' callback
 *
 * Render the XLS file using PHPExcel.
 *
 */
function commerce_gd_dashboard_export_write_bilan_comptable_xls($success, $results, $operations) {
  if ($success) {
    _commerce_gd_dashboard_export_write_bilan_comptable_xls_output($results['#values']);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}
/**
 * Batch 'finished' callback
 *
 * Render the XLS file using PHPExcel.
 *
 */
function commerce_gd_dashboard_export_write_bilan_comptable_html($success, $results, $operations) {
  if ($success) {
    _commerce_gd_dashboard_export_write_bilan_comptable_xls_output($results['#values'], 'html');
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}

function _commerce_gd_dashboard_export_write_bilan_comptable_xls_output($values, $format = 'xls') {
  $path = drupal_get_path('module', 'commerce_gd_dashboard');

  if (!isset($filename)) {
    $filename = 'bilan-comptable-drupal.xlsx';
  }
  // include xls generatator class
  require_once './' . $path . '/libs/PHPExcel.php';
  $objPHPExcel = new PHPExcel();

  $sheets = array();


  $WorkSheet = new PHPExcel_Worksheet($objPHPExcel, 'Export comptable');
  $objPHPExcel->addSheet($WorkSheet, 0);
  $objPHPExcel->setActiveSheetIndex(0);
  _commerce_gd_dashboard_export_write_bilan_comptable_xls_create_domain_sheet($objPHPExcel, $values);

  $objPHPExcel->setActiveSheetIndex(0);

  if ($format == 'html') {
    // With Excel2007 Writer we have formatting problem on open office. dont know for ms office.
    $objWriter = new PHPExcel_Writer_HTML($objPHPExcel);
    $objWriter->writeAllSheets();
    // This is for Excel2007 Writer only :
    // $objWriter->setOffice2003Compatibility(TRUE);

    // We'll be outputting an excel file
    header('Content-type: text/html');

    // Filename
    header('Content-Disposition: inline;');

    // Write file to the browser
    $objWriter->save('php://output');

    drupal_page_footer();
    exit();
  }
  else
  if ($format == 'xls') {
    // With Excel2007 Writer we have formatting problem on open office. dont know for ms office.
    $objWriter = new PHPExcel_Writer_Excel2007($objPHPExcel);
    // This is for Excel2007 Writer only :
    // $objWriter->setOffice2003Compatibility(TRUE);

    // We'll be outputting an excel file
    header('Content-type: application/vnd.ms-excel');

    // Filename
    header('Content-Disposition: attachment; filename="' . $filename . '"');

    // Write file to the browser
    $objWriter->save('php://output');

    drupal_page_footer();
    exit();
  }
}

function _commerce_gd_dashboard_export_write_bilan_comptable_xls_create_domain_sheet($objPHPExcel, $dated_values) {
  // Create a new worksheet called by domain.
  $i = 1;

  foreach ($dated_values as $date => $values) {
    $n_cells = 0;
    $header = array(
      array(
        $date,
        NULL,
        'Nombre de commande',
        $values['num'],
        'Don moyen',
        $values['moyenne'] / 100,
      ),
      array(
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
      ),
      array(
        'Numéro de don',
        'Type de don',
        'Date',
        'Don',
        'Nom',
        'Prénom',
        'Adresse',
        'Code postal',
        'Ville',
        'Pays',
        'Téléphone',
        'Email',
        'Autorise la diffusion de ses données',
        NULL,
      ),
    );
    $objPHPExcel->getActiveSheet()->fromArray(
      $header,
      NULL,
      'A' . $i
    );
    // Month style
    $styleArray = array(
      'font' => array(
        'bold' => true,
        'size' => '18'
      ),
    );
    $objPHPExcel->getActiveSheet()->getStyle('A' . $i)->applyFromArray($styleArray);

    $objPHPExcel->getActiveSheet()->getStyle('F' . $i)
    ->getNumberFormat()
    ->setFormatCode(PHPExcel_Style_NumberFormat::FORMAT_CURRENCY_EUR_SIMPLE);

    // Month style
    $styleArray = array(
      'font' => array(
        'bold' => true,
        'size' => '16'
      ),
    );
    $type_i = $i + 1;
    $objPHPExcel->getActiveSheet()->getStyle('A' . $type_i)->applyFromArray($styleArray);
    $objPHPExcel->getActiveSheet()->getStyle('H' . $type_i)->applyFromArray($styleArray);
    $styleArrayHeader = array(
      'font' => array(
        'bold' => true,
      ),
    );

    // Header style
    foreach(range('A','M') as $columnID) {
      $head_i = $i + 2;
      $objPHPExcel->getActiveSheet()->getStyle($columnID . $head_i)->applyFromArray($styleArrayHeader);
      $objPHPExcel->getActiveSheet()->getColumnDimension($columnID)
      ->setAutoSize(true);
    }
    $n_cells += 3;

    if (!empty($values['orders'])) {
      $count_orders = count($values['orders']);
      $order_i = $i + $n_cells;
      foreach ($values['orders'] as $order_id => $infos) {
        $objPHPExcel->getActiveSheet()
        ->setCellValue('A' . $order_i, $infos['A']);
        $objPHPExcel->getActiveSheet()->getStyle('A' . $order_i);


      $objPHPExcel->getActiveSheet()
      ->setCellValue('B' . $order_i, $infos['B']);

      $objPHPExcel->getActiveSheet()
      ->setCellValue('C' . $order_i, $infos['C']);


      $objPHPExcel->getActiveSheet()
      ->setCellValue('D' . $order_i, $infos['D'] / 100);


        $objPHPExcel->getActiveSheet()
        ->setCellValue('E' . $order_i, $infos['E']);
        $objPHPExcel->getActiveSheet()
        ->setCellValue('F' . $order_i, $infos['F']);
        $objPHPExcel->getActiveSheet()
        ->setCellValue('G' . $order_i, $infos['G']);
        $objPHPExcel->getActiveSheet()
        ->setCellValue('H' . $order_i, $infos['H']);
        $objPHPExcel->getActiveSheet()
        ->setCellValue('I' . $order_i, $infos['I']);
        $objPHPExcel->getActiveSheet()
        ->setCellValue('J' . $order_i, $infos['J']);


        $objPHPExcel->getActiveSheet()
        ->setCellValueExplicit('K' . $order_i, $infos['K'], PHPExcel_Cell_DataType::TYPE_STRING);

        $objPHPExcel->getActiveSheet()
        ->setCellValue('L' . $order_i, $infos['L']);

        $objPHPExcel->getActiveSheet()
        ->setCellValue('M' . $order_i, $infos['M']);

        $objPHPExcel->getActiveSheet()->getStyle('D' . $order_i)
        ->getNumberFormat()
        ->setFormatCode(PHPExcel_Style_NumberFormat::FORMAT_CURRENCY_EUR_SIMPLE);

        $order_i++;
      }$order_i-=1;
    }
   if (!empty($order_i)) {
     $n_cells += $order_i;
   }
   // margin cells between each month
   $n_cells += 3;
   $i = $n_cells;
  }

}

