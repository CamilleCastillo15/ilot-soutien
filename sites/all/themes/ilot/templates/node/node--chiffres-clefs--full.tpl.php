<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php
    print $chiffres_clefs;
  ?>
  <?php
    hide($content['field_chiffres_clefs_chiffre']);
    print render($content);
  ?>
</article><!-- /.node -->
<div class="clearfix"></div>