<?php
/**
 * Implements hook_menu_block_blocks().
 */
function ilot_theme_menu_block_blocks() {
  // The array key is the block delta used by menu block.
  return array(
      'custom-1' => array(
          'menu_name'   => 'main-menu',
          'parent_mlid' => 0,
          'title_link'  => 0,
          'admin_title' => 'Menu ilot',
          'level'       => 1,
          'follow'      => 0,
          'depth'       => 2,
          'expanded'    => 1,
          'sort'        => 0,
      ),
      'custom-2' => array(
          'menu_name'   => 'menu-footer-menu',
          'parent_mlid' => 0,
          'title_link'  => 0,
          'admin_title' => 'Footer Menu',
          'level'       => 1,
          'follow'      => 0,
          'depth'       => 0,
          'expanded'    => 0,
          'sort'        => 0,
      ),
  );
}
/**
 * Implements hook_block_info
 */
function ilot_theme_block_info() {
  $blocks = array();
//
//  $blocks['image-logo'] = array(
//		'info' => t('Logo Ilot'),
//		'weight' => 1,
//		'visibility' => BLOCK_VISIBILITY_NOTLISTED,
//		'cache' => DRUPAL_CACHE_GLOBAL,
//  );
//
//  $blocks['bandeau-don'] = array(
//      'info' => t('Bandeau don'),
//      'weight' => 10,
//      'visibility' => BLOCK_VISIBILITY_NOTLISTED,
//      'cache' => DRUPAL_CACHE_GLOBAL,
//  );

  $blocks['social-share'] = array(
      'info' => t('Social-share'),
      'weight' => 10,
      'visibility' => BLOCK_VISIBILITY_NOTLISTED,
      'cache' => DRUPAL_CACHE_GLOBAL,
  );
    $blocks['newsletter'] = array(
    'info' => t('Bloc newsletter'), //The name that will appear in the block list.
    'cache' => DRUPAL_CACHE_PER_ROLE, //Default
  );
      $blocks['contact'] = array(
    'info' => t('Bloc contact'), //The name that will appear in the block list.
    'cache' => DRUPAL_CACHE_PER_ROLE, //Default
  );
  return $blocks;
}

/**
 * Implement hook_block_view().
 *
 */
function ilot_theme_block_view($delta = '') {
  //The $delta parameter tells us which block is being reqested.
  $block = array();
  switch ($delta) {
//    case 'image-logo':
//      $block['subject'] = '';
//      $block['content'] = array(
//	      '#markup' => '<div class="logo-wrapper"><a href="/"><span>Ilot</span><img class="logo" src="/sites/all/themes/ilot/images/ilot_degrade.svg" /></a></div>',
//	    );
//      break;
//    case 'bandeau-don':
//      $block['subject'] = '';
//      $block['content'] = array(
//	      '#markup' => '<div class="bandeau-don"><span class="premier">Un accueil, un toit,</span><span> Un nouveau départ</span><a href="/faire-un-don">Faire un don</a></div>',
//	    );
//      break;
    case 'social-share':
      $block['subject'] = '';
      $block['content'] = array(
          '#theme' => 'item_list',
          '#items' => ilot_theme_social_share_links(),
        );
      break;
      case 'newsletter':
      $block['subject'] = 'newsletter';
      $block['content'] = array(
          '#theme' => 'newsletter'
        );
      break;
      case 'contact':
      $block['subject'] = 'contact';
      $block['content'] = array(
          '#theme' => 'contact'
        );
      break;
  }
  return $block;
}

function ilot_theme_social_share_links() {
  $siteUrl = urlencode(url('', array('absolute'=>true)));
  $links = array();
  $links[] = l('Facebook','https://www.facebook.com/sharer/sharer.php?u='.$siteUrl, array('attributes' => array('class' => 'facebook', 'target'=>'_blank')));
  $links[] = l('Twitter', 'https://twitter.com/home?status='.$siteUrl, array('attributes' => array('class' => 'twitter', 'target'=>'_blank')));
  return $links;
}

function ilot_theme_theme($existing, $type, $theme, $path){
  $themez = drupal_get_path("theme",$GLOBALS['theme']);
  $bodyaddress = variable_get('ilot_theme_newsletter_text');
  return array( 
    'newsletter' => array(
      'template' => 'templates/ilot_theme_newsletter',
//      'variables' => array('view' => NULL),
//      'variables'=> array('ilot_theme' => $themez, 'body' => check_markup($bodyaddress["value"],$bodyaddress["format"]) )
    ),
      'contact' => array(
      'template' => 'templates/ilot_theme_contact',
//      'variables' => array('view' => NULL),
//      'variables'=> array('ilot_theme' => $themez, 'body' => check_markup($bodyaddress["value"],$bodyaddress["format"]) )
    )
  );
}