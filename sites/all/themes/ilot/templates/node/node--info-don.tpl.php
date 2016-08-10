
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <h2><?php print $title; ?></h2>

  <?php print render($content['body']); ?>

  <?php print render($content['field_info_don_image']); ?>

  <a href="<?php print render($content['field_info_don_ra']); ?>" target="_blank">Rapport d'activité</a>

   </br></br>

  <a href="<?php print render($content['field_info_don_rf']); ?>" target="_blank">Rapport financier</a>

   </br> </br> </br>

</article><!-- /.node -->
<div class="clearfix"></div>