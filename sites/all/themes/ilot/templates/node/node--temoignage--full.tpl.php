<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_temoignage_image']); ?>
  <h1><?php print $node->title; ?></h1>
  <?php if(!empty($content['field_temoignage_sous_titre'])): ?>
  <h2><?php print render($content['field_temoignage_sous_titre']); ?></h2>
  <?php endif; ?>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
  <?php print render($content['field_temoignage_accroche']); ?>
  <?php print render($content['field_temoignage_corps']); ?>
  <?php print render($content['field_temoignage_annee_txt']); ?>
  <div class="nav-next-prev">
    <?php if (isset($prev)) :
      print l('témoignage précédent', 'node/'.$prev, array('attributes' => array('class' => 'prev read-more')));
      endif;
    ?>
    <?php if (isset($next)) :
      print l('témoignage suivant', 'node/'.$next, array('attributes' => array('class' => 'next read-more')));
      endif;
    ?>
  </div>
</article><!-- /.node -->
<div class="clearfix"></div>
