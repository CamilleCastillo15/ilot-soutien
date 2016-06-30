<?php

class EditoAuthorTaxonomyTermItemInlineEntityFormController extends TaxonomyTermInlineEntityFormController {

  public function defaultFields($bundles) {

      $fields = parent::defaultFields($bundles);

      // Add the function linked to the author.
      $fields['field_auteur_fonction'] = array(
          'type' => 'field',
          'label' => t('Function'),
          'formatter' => 'textfield',
          'settings' => array(),
          'visible' => TRUE,
          'weight' => 3,
      );
      return $fields;
  }

  public function entityForm($entity_form, &$form_state) {
    $entity_form = parent::entityForm($entity_form, $form_state);
    $term = $entity_form['#entity'];

    $entity_form['name']['#default_value'] = isset($term->name_value) ? $term->name_value : $term->name;
    $entity_form['name']['#description'] = t('Add a | charactere between the firstname and lastname. Ex : Ernest | Hemingway');
    unset($entity_form['description']);
    return $entity_form;
  }
}