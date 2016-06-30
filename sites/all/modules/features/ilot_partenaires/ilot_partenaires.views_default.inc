<?php
/**
 * @file
 * ilot_partenaires.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ilot_partenaires_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'liste_partenaire';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'liste_partenaire';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '<<';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '<';
  $handler->display->display_options['pager']['options']['tags']['next'] = '>';
  $handler->display->display_options['pager']['options']['tags']['last'] = '>>';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Contenu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Contenu: Type de partenaire (field_partenaire_type_partner) */
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['id'] = 'field_partenaire_type_partner_tid';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['table'] = 'field_data_field_partenaire_type_partner';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['field'] = 'field_partenaire_type_partner_tid';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_partenaire_type_partner_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Contenu: Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenu: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partenaire' => 'partenaire',
  );
  $translatables['liste_partenaire'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Réinitialiser'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<<'),
    t('<'),
    t('>'),
    t('>>'),
    t('Tout'),
  );
  $export['liste_partenaire'] = $view;

  return $export;
}
