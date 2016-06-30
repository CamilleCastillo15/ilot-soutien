<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_chiffres_clefs_image']); ?>
  <div class="bloc-texte">
    <span class="chiffres-clefs"><?php print $chiffres_clefs; ?></span>
    <?php print render($content['field_chiffres_clefs_accroche']); ?>
    <?php //print l('En lire plus', 'chiffres-clefs')?>
  </div>
</article><!-- /.node -->
