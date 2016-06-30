<?php
/**
 * @file
 * Enables modules and site configuration for a ilot_standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function ilot_standard_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = "L'ilot";
  $form['site_information']['site_mail']['#default_value'] = 'contact@ilotstandarddev.fr';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'admin@ilotstandarddev.fr';
  $form['admin_account']['account']['pass'] ['#after_build'][] = 'ilot_standard_form_install_configure_form_alter_process_pass';
}

function ilot_standard_form_install_configure_form_alter_process_pass(&$form, &$form_state) {
  $form['#attached'] = array('js' => array(drupal_get_path('profile', 'ilot_standard') . '/scripts/autofill.js'));
  return $form;
}
/**
 * Implements hook_install_tasks().
 */
function ilot_standard_install_tasks($install_state) {
  $task = array();
  $task['ilot_standard_profile_custom_install'] = array(
      'display_name' => st('Install ilot_standard custom module & features.'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  $task['ilot_standard_profile_create_content'] = array(
    'display_name' => st('Create ilot_standard default content.'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  $task['ilot_standard_profile_create_url_alias_task'] = array(
    'display_name' => st('Create ilot_standard Url Alias.'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  return $task;
}

/**
 * Install task callback function.
 * Enable custom modules & features, activate the master of the custom modules.
 */
function ilot_standard_profile_custom_install(&$install_state) {
  variable_set('file_public_path', 'sites/default/files/public');
  variable_set('file_private_path', 'sites/default/files/private');
  variable_set('file_temporary_path', 'sites/default/files/tmp');
  // Enable ilot_standard custom module, dependencies and features.
  variable_set('install_profile_modules', array('ilot_custom'));
  $batch = install_profile_modules($install_state);
  $batch['title'] = st('Install ilot_standard custom module & features.');
  return $batch;
}

/**
 * Install task callback function.
 */
function ilot_standard_profile_create_content(&$install_state) {
  variable_set('ilot_unique_content_types', array());
  variable_set('ilot_unique_content_type_nids', array());
  drupal_flush_all_caches();
  return ilot_standard_profile_create_content_batch();

}

function ilot_standard_profile_create_content_batch() {
  $operations = array(
      // Create default demo content
      //array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_auteur')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_type_partner')),
  		array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_type_temoignage')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_edito')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_accueil')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_actualites')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_association')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_liste_actu')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_liste_projet')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_liste_temoignage')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_liste_partenaire')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_liste_rapport_activite')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_projets')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_chiffres_clefs')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_temoignage')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_mission')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_valeur')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_partenaire')),
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_create_rapport_activite')),
      // Add another ..


      /**
       * Assign permissions to roles
       */
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_grant_permissions_by_role')),
      // Recreate URL alias :
      array('_ilot_standard_profile_create_content', array('ilot_standard_profile_remove_url_alias')),
  );

  $batch = array(
      'operations' => $operations,
      'title' => st('Create ilot_standard default content'),
      'error_message' => st('The content creation has encountered an error.'),
      'finished' => '_ilot_standard_profile_create_content_finished',
  );
  return $batch;
}

/**
 * 'Finished' callback for module installation batch.
 */
function _ilot_standard_profile_create_content_finished($success, $results, $operations) {
  entity_flush_caches();
  token_flush_caches();
  drupal_flush_all_caches();
}

/**
 * Batch callback for batch creation of content.
 */
function _ilot_standard_profile_create_content($function_name, &$context) {
  require_once(drupal_get_path('profile', 'ilot_standard') . '/ilot_standard.nodes.inc');
  require_once(drupal_get_path('profile', 'ilot_standard') . '/ilot_standard.terms.inc');
  require_once(drupal_get_path('profile', 'ilot_standard') . '/ilot_standard.user.inc');
  // Call the function
  $function_name();
  $context['results'][] = $function_name;
  $context['message'] = st('Done: %function.', array('%function' => $function_name));
}
/**
 * Function called at install after demo content creation,
 * to update URL alias.
 * @return boolean
 */
function ilot_standard_profile_remove_url_alias() {
  $query = db_query('TRUNCATE TABLE {url_alias}');
  $query->execute();
}

/**
 * Install task callback function.
 */
function ilot_standard_profile_create_url_alias_task(&$install_state) {
  drupal_flush_all_caches();
  return ilot_standard_profile_create_url_alias_batch();

}

function ilot_standard_profile_create_url_alias_batch() {
  $operations = array(
      array('ilot_standard_profile_create_url_alias', array('')),
  );

  $batch = array(
      'operations' => $operations,
      'title' => st('Create ilot_standard URL Alias'),
      'error_message' => st('The content creation has encountered an error.'),
      'finished' => '_ilot_standard_profile_create_url_alias_finished',
  );
  return $batch;
}

/**
 * 'Finished' callback for module installation batch.
 */
function _ilot_standard_profile_create_url_alias_finished($success, $results, $operations) {
  drupal_flush_all_caches();
}


/**
 * Function called at install after demo content creation,
 * to update URL alias.
 * @return boolean
 */
function ilot_standard_profile_create_url_alias($function_name, &$context) {
  $query = db_select('node', 'n');
  $query->addField('n', 'nid');
  $query->orderBy('n.nid');
  $query->addMetaData('entity', 'node');

  $query->range(0, 100);
  $nids = $query->execute()->fetchCol();

  pathauto_node_update_alias_multiple($nids, 'bulkupdate');
  $context['results'][] = $function_name;
  $context['message'] = st('Done: %function.', array('%function' => 'ilot_standard_profile_create_url_alias'));
}

function ilot_standard_profile_grant_permissions_by_role() {
  // Anonymous user
  user_role_change_permissions(1,
  array(
  'access comments' => TRUE,
  'post comments' => TRUE,
  'access site-wide contact form' => TRUE,
  'search content' => TRUE,
  'subscribe to newsletters' => TRUE,
  'access checkout' => TRUE,
  )
  );
  // Authenticated user
  user_role_change_permissions(2,
  array(
  'access comments' => TRUE,
  'post comments' => TRUE,
  'access site-wide contact form' => TRUE,
  'search content' => TRUE,
  'subscribe to newsletters' => TRUE,
  'access checkout' => TRUE,
  )
  );

  // Create a role for site editors.
  $admin_role = new stdClass();
  $admin_role->name = 'Editor';
  $admin_role->weight = 2;
  user_role_save($admin_role);
  // Editor
  user_role_change_permissions($admin_role->rid,
  array(
  'access administration menu' => TRUE,
  'flush caches' => TRUE,
  'administer comments' => TRUE,
  'skip comment approval' => TRUE,
  'edit own comments' => TRUE,
  'access site-wide contact form' => TRUE,
  'access contextual links' => TRUE,
  'use text format full_html' => TRUE,
  'administer menu' => TRUE,
  'bypass node access' => TRUE,
  'administer nodes' => TRUE,
  'access content overview' => TRUE,
  'create url aliases' => TRUE,
  'send newsletter' => TRUE,
  'subscribe to newsletters' => TRUE,
  'access administration pages' => TRUE,
  'view the administration theme' => TRUE,
  'administer taxonomy' => TRUE,
  'access user profiles' => TRUE,
  'administer shortcuts' => TRUE,
  )
  );
  // Create user
  $user = ilot_standard_init_user();
  $user["name"] = "Editeur";
  $user["pass"] = 'editeur';
  $user["mail"] = 'editeur@ilotdev.fr';
  $user["init"] = 'editeur@ilotdev.fr';
  $user["status"] = 1;
  $user["roles"][$admin_role->rid] = $admin_role->name;
  //the first parameter is left blank so a new user is created
  $account = user_save('', $user);

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'Logisticien';
  $admin_role->weight = 3;
  user_role_save($admin_role);
  // Logisticien
  user_role_change_permissions($admin_role->rid,
  array(
  'access administration menu' => TRUE,
  'flush caches' => TRUE,
  'access site-wide contact form' => TRUE,
  'access contextual links' => TRUE,
  'use text format full_html' => TRUE,
  'administer menu' => TRUE,
  'create url aliases' => TRUE,
  'access administration pages' => TRUE,
  'view the administration theme' => TRUE,
  'administer taxonomy' => TRUE,
  'access user profiles' => TRUE,
  'create commerce_order entities' => TRUE,
  'view any commerce_order entity' => TRUE,
  'edit any commerce_order entity' => TRUE,
  'view payments' => TRUE,
  'administer commerce_customer_profile entities' => TRUE,
  'administer line items' => TRUE,
  )
  );
  // Create user
  $user = ilot_standard_init_user();
  $user["name"] = "Logisticien";
  $user["pass"] = 'logisticien';
  $user["mail"] = 'logisticien@ilotdev.fr';
  $user["init"] = 'logisticien@ilotdev.fr';
  $user["status"] = 1;
  $user["roles"][$admin_role->rid] = $admin_role->name;
  //the first parameter is left blank so a new user is created
  $account = user_save('', $user);

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'Gerant';
  $admin_role->weight = 4;
  user_role_save($admin_role);
  // Gerant
  user_role_change_permissions($admin_role->rid,
  array(
  'access administration menu' => TRUE,
  'flush caches' => TRUE,
  'access site-wide contact form' => TRUE,
  'access contextual links' => TRUE,
  'use text format full_html' => TRUE,
  'administer menu' => TRUE,
  'create url aliases' => TRUE,
  'access administration pages' => TRUE,
  'view the administration theme' => TRUE,
  'administer taxonomy' => TRUE,
  'access user profiles' => TRUE,
  'create commerce_order entities' => TRUE,
  'view any commerce_order entity' => TRUE,
  'edit any commerce_order entity' => TRUE,
  'administer payments' => TRUE,
  'administer shortcuts' => TRUE,
  'administer commerce_customer_profile entities' => TRUE,
  'administer line items' => TRUE,
  )
  );
  // Create user
  $user = ilot_standard_init_user();
  $user["name"] = "Gerant";
  $user["pass"] = 'gerant';
  $user["status"] = 1;
  $user["roles"][$admin_role->rid] = $admin_role->name;
  //the first parameter is left blank so a new user is created
  $account = user_save('', $user);

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'Administrateur';
  $admin_role->weight = 5;
  user_role_save($admin_role);
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);
  // Create user
  $user = ilot_standard_init_user();
  $user["name"] = "Administrateur";
  $user["pass"] = 'administrateur';
  $user["status"] = 1;
  $user["roles"][$admin_role->rid] = $admin_role->name;
  //the first parameter is left blank so a new user is created
  $account = user_save('', $user);

  return TRUE;
}

/**
 * Import an image in the drupal filesystem.
 *
 * @param $url
 * @param $destination
 * @return array|boolean
 */
function ilot_standard_profile_import_image($url, $destination) {
  $image_path = file_build_uri($destination);
  if (file_prepare_directory($image_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    if (file_exists($url)) {
      // Create managed File object and associate with Image field.
      $file = (object) array(
          'uid' => 1,
          'uri' => $url,
          'filemime' => file_get_mimetype($url),
          'status' => 1,
      );
      // save the file to the public files directory.
      $file = file_copy($file, $image_path);
      // Increment usage count
      file_usage_add($file, 'node', 'image', $file->fid);
      return (array)$file;
    }
    else {
      drupal_set_message(t('File @file does not exists', array('@file' => $url)), 'error');
      return FALSE;
    }
  }
  else {
    drupal_set_message(t('Error to create the image directory'), 'error');
    return FALSE;
  }
}