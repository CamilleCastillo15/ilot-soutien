<?php
/**
 * @file
 * ilot_footer_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ilot_footer_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_-copyright-2013---ilot:<front>
  $menu_links['menu-footer-menu_-copyright-2013---ilot:<front>'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => '© Copyright 2013 - ILOT',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_-copyright-2013---ilot:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 0,
  );
  // Exported menu link: menu-footer-menu_mentions-lgales:node/73
  $menu_links['menu-footer-menu_mentions-lgales:node/73'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/73',
    'router_path' => 'node/%',
    'link_title' => 'Mentions légales',
    'options' => array(
      'identifier' => 'menu-footer-menu_mentions-lgales:node/73',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Mentions légales');
  t('© Copyright 2013 - ILOT');


  return $menu_links;
}
