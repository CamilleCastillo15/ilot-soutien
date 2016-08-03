<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php
    hide($content['field_association_phrase_bouton']);
    print render($content);/*
  ?>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
  <?php if(!empty($content['field_association_phrase_bouton'])): ?>
    <a class="don" href="/faire-un-don"><span><?php print render($content['field_association_phrase_bouton'])?></span><span class="don-btn">Faire un don</span></a>
  <?php endif; */?>
  </article><!-- /.node -->
<aside class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<h1>Témoignages</h1>
<?php print $views_temoignages_contextuel; ?>
<div class="bandeau-je-fais-don">
    <img src="/sites/all/themes/ilot/images/logo_coeur_rouge.svg" />
    <div class="col-1">
        Je fais<br />
        un don
    </div>
    <?php print l("<div class='don-btn readmore'>Accéder au formulaire</div>", "", array("html"=>true)); ?>
</div>
</aside>
<div class="clearfix"></div>
