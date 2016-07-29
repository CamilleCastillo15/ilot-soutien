<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php hide($content['print_links']); ?>
  <?php print render($content); ?>
  <?php print $views_accueil_chiffres;?>
  <section class="actualites">
    <h1 class="gros">actualités</h1>
    <?php print $views_accueil_actu; ?>
    <?php print l('Voir toutes les actus', 'actualités', array('attributes' => array('class' => 'actu readmore')));?>
  </section><section class="mosaique-new">
    <div class="bloc bloc-text dernier-projet">
        <div class="mosaique-text">denier projet</div>
        <div class="arrow east"></div>
    </div><div class="bloc bloc-img img-dernier-projet">
       <img src="sites/all/themes/ilot/images/img_test/samia-temoignage.png" />
    </div><!--
       --><div class="bloc bloc-img img-son-temoignage">
        <img src="sites/all/themes/ilot/images/img_test/bel-espoir.png" />
    </div><div class="bloc bloc-text son-temoignage">
        <div class="mosaique-text">son témoignage</div>
        <div class="arrow west"></div>
    </div><!--
       --><div class="bloc bloc-text espace-presse">
        <div class="mosaique-text">espace presse</div>
        <div class="arrow east"></div>
    </div><div class="bloc bloc-img img-espace-presse"><img src="sites/all/themes/ilot/images/img_test/samia-temoignage.png" /></div><!--
       --><div class="bloc bloc-img img-lot-media"><img src="sites/all/themes/ilot/images/img_test/bel-espoir.png" />
    </div><div class="bloc bloc-text ilot-medias">
        <div class="mosaique-text">l'îlot dans les médias</div>
        <div class="arrow west"></div>
    </div><div class="bloc don-confiance">
        Je fais un don en confiance
        <div class ="don-confiance-btn readmore">Voir plus</div>
    </div>
</section><br />
<div class="don-confiance">

    Je fais un don en confiance

    <div class="don-confiance-btn readmore">Voir plus</div>

</div>
</article><!-- /.node -->
<div class="clearfix"></div>

  <!-- <section class="mosaique">
    <?php //print $views_accueil_mosaique_temoignage; ?>
    <?php //print $views_accueil_mosaique_projet; ?>
      <a href="/faire-un-don" class="faire-un-don">Faire un don</a>
  </section> -->
