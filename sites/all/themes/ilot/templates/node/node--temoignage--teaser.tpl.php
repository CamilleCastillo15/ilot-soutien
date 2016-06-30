<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="vignette">
    <?php print l(render($content['field_temoignage_image']), 'node/'.$node->nid, array('html' => TRUE)); ?>
  </div>
  <div class="texte">
    <h2><?php print l($node->title, 'node/'.$node->nid, array('html' => TRUE)); ?></h2>
    <?php if(!empty($content['field_temoignage_sous_titre'])): ?>
      <h3><?php print l(render($content['field_temoignage_sous_titre']), 'node/'.$node->nid, array('html' => TRUE)); ?></h3>
    <?php endif; ?>
    <?php  if (isset($content['field_temoignage_accroche'])) : ?>
      <?php print render($content['field_temoignage_accroche']); ?>
    <?php endif;?>
    <?php print l('voir plus', 'node/'.$node->nid, array('attributes' => array('class' => 'read-more'))); ?>
  </div>
</article><!-- /.node -->
