<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php hide($content['print_links']); ?>
  <?php print render($content); ?>
  <?php print $views_accueil_chiffres;?>
  <section class="actualites">
    <?php print $views_accueil_actu; ?>
    <?php print l('Voir toutes les actus', 'actualités', array('attributes' => array('class' => 'actu read-more')));?>
  </section>
  <section class="mosaique">
    <?php print $views_accueil_mosaique_temoignage; ?>
    <?php print $views_accueil_mosaique_projet; ?>
    <a href="/faire-un-don" class="faire-un-don">Faire un don</a>
  </section>
</article><!-- /.node -->
<div class="clearfix"></div>