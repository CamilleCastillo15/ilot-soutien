<div class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <h1>ÉDITO</h1>
  <?php print render($content['field_edito_corps']); ?>
  <div class="signature">
    <?php print render($content['field_edito_nom']); ?>
    <?php print render($content['field_edito_fonction']); ?>
  </div>
</div><!-- /.node -->
<div class="clearfix"></div>