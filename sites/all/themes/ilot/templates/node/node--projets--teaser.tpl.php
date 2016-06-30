<article class="bloc-grille-base actus node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="vignette">
    <?php  print l(render($content['field_projet_image_accroche']), 'node/' . $node->nid, array('html' => TRUE)); ?>
  </div>
  <div class="texte">
    <h2><?php print l($node->title, 'node/' . $node->nid, array('html' => TRUE)); ?></h2>
    <?php if(!empty($node->field_projet_sous_titre)): ?>
      <h3><?php  print l(render($content['field_projet_sous_titre']), 'node/' . $node->nid, array('html' => TRUE)); ?></h3>
    <?php endif;?>
    <?php print render($content['field_projet_accoche']); ?>

      <?php print l("lire la suite", 'node/'.$node->nid, array("html"=>true, 'attributes' => array('class' => array('readmore')))); ?>

  </div>
</article><!-- /.node -->
