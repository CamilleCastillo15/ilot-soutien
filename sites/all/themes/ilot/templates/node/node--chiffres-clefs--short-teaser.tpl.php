<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="vignette">
    <?php  print render($content['field_chiffres_clefs_image']); ?>
  </div>
  <div class="texte">
    <?php print $chiffres_clefs; ?>
    <?php  print render($content['field_chiffres_clefs_accroche']); ?>
    <?php //print l('voir plus', 'node/'.$node->nid, array('attributes' => array('class' => 'read-more'))); ?>
  </div>
</article><!-- /.node -->
