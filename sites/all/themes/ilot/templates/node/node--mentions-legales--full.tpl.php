<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <h1><?php print $node->title; ?></h1>
  <?php
    print render($content);
  ?>
</article><!-- /.node -->
