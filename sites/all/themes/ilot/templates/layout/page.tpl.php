<?php
/**
 * @file
 * Zen theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
$light = FALSE;
if (!empty($_GET['checkout']) && $_GET['checkout'] == 'light') {
	$light = TRUE;
}
  $theme = base_path() . drupal_get_path("theme",$GLOBALS['theme']) ;

?>

<div id="page" <?php if ($light) : print 'class="checkout-light"'; endif; ?>>
    <?php if (!$light) : ?>

    <div id="l-header" >
        <?php print render($page['navigation']);?>
         <div class="container-logo-bandeau-don">

             <div class="logo-wrapper">
                 <a href="/"><img class="logo" src="/sites/all/themes/ilot/images/ilot_degrade.svg" /></a>
             </div>

             <div class="bandeau-don">
               <div class="center-texte-don">
                    <div class="text-bandeau-don">
                        <span class="premier">Un accueil, un toit,</span>
                        <span> Un nouveau départ</span>
                    </div>

               </div>
                <a href="/faire-un-don">
                    <img src="/sites/all/themes/ilot/images/logo_coeur_blanc.svg" />
                    <div class="col-1">
                        Je fais<br />
                        un don
                    </div>
                </a>
            </div>
         </div>

          <div class="menu-header">
              <?php print render($page['header']);?>
              <div class="clear"></div>
          </div>
          <div class="vocation-mobile">
          <h1>NOTRE VOCATION</h1>
          <p>L'Îlot accueille, héberge et accompagne vers la réinsertion des personnes en grande détresse, en particulier lorsqu'elles sortent de prison. L'association accompagne ces personnes dans leur démarche personnelle et volontaire pour retrouver une place dans la société, notamment par l'accès au logement et à l'emploi.</p>
        </div><!-- /.node -->
        <div class="clearfix"></div>

    </div><!-- /#navigation -->

    <?php endif; ?>

    <div id="main">
        <div id="content" class="column l-content" role="main">
          <?php print render($page['highlighted']); ?>
          <?php print $breadcrumb; ?>
          <a id="main-content"></a>
          <?php print $messages; ?>
          <?php print render($tabs); ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
          <?php
          if (arg(0) == 'checkout' && (!arg(2))) : ?>

            <p class="block-legal-checkout">En application de la loi "Informatique et Libertés" du 6 janvier 1978, vous disposez d'un droit d'accès, de rectification et de suppression des informations vous concernant, <a href="/contact">en nous contactant</a>.</p>

            <?php if (false): ?>
            <div class="block-logo-confiance">
            <img src="/<?php print drupal_get_path('theme', 'ilot') . '/images/comite-charte.png' ; ?>">
            <p>L'association l'Îlot est reconnue d'utilité publique depuis 1988 et agréée par le Comité de la Charte du don en confiance, organisme d'agrément et de contrôle des organisations faisant appel aux dons.</p>
            </div>
            <?php endif; ?>
          <?php endif; ?>
          <?php print $feed_icons; ?>
          <div class="clearfix"></div>
        </div><!-- /#content -->

        <?php
          // Render the sidebars to see if there's anything in them.
          $sidebar_first  = render($page['sidebar_first']);
          $sidebar_second = render($page['sidebar_second']);
        ?>

        <?php if ($sidebar_first || $sidebar_second): ?>
          <aside class="sidebars">
            <?php print $sidebar_first; ?>
            <?php print $sidebar_second; ?>
          </aside><!-- /.sidebars -->
        <?php endif; ?>

      </div><!-- /#main -->
      <div class="l-shield"></div>
      <div class="l-off h text-presentation">
            <a href="/">
                <img class="logo" src="<?php print $theme ?>/images/ilot_vert.svg" alt="logo" title="logo" />
            </a>
            <?php print render($page['header']); ?>
            <?php print render($page['navigation']);?>
            <div class="reseaux">
               <a href="https://twitter.com/IlotAsso?lang=fr" class="twitter-lien" target="_blank">
                    <div class="twitter-img">
                    </div>
               </a>
               <a href="https://www.linkedin.com/company/3787026?trk=tyah&trkInfo=clickedVertical%3Acompany%2CclickedEntityId%3A3787026%2Cidx%3A2-1-3%2CtarId%3A1460643706927%2Ctas%3Al%27ilot%20" class="linkedin-lien" target="_blank">
                    <div class="facebook-img">
                    </div>
                </a>
            </div>
       </div>
    <?php if (!$light) : ?>
      <?php print render($page['footer']); ?>
    <?php endif; ?>
</div><!-- /#page -->
<?php if (!$light) : ?>
<?php print render($page['bottom']); ?>
<?php endif; ?>
<div class="burger h">
    <svg id="Calque_1" data-name="Calque 1" viewBox="0 0 55.4 55.4">
        <circle class="cls-1" cx="27.7" cy="27.7" r="27.7"/>
        <path class="cls-2" id="burger_3"
            d="M31,33H2.7a1.06,1.06,0,0,0,0,2H31a0.85,0.85,0,0,0,.7-1C31.7,33.4,31.5,33,31,33Z"
            transform="translate(10.8 5.7)"/>
        <path class="cls-2" id="burger_2"
            d="M2.7,11H31a0.85,0.85,0,0,0,.7-1c0-.6-0.2-1-0.7-1H2.7A0.85,0.85,0,0,0,2,10,0.85,0.85,0,0,0,2.7,11Z" transform="translate(10.8 5.7)"/>
        <path class="cls-2" id="burger_1"
            d="M31,21H2.7A0.85,0.85,0,0,0,2,22a0.85,0.85,0,0,0,.7,1H31a0.85,0.85,0,0,0,.7-1C31.7,21.4,31.5,21,31,21Z" transform="translate(10.8 5.7)"/>
    </svg>
</div>
