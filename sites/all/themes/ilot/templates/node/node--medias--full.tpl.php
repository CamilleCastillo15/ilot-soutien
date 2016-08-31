<article class="node-<?php print $node->nid; ?> <?php print render($content['field_type_de_medias']);?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_image'])?>
  <h1><?php print $node->title; ?></h1>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
  <h2><?php print render($content['field_sous_titre']); ?></h2>
  <a href="<?php print render($content['field_lien']); ?>" target="_blank"><div class="read-more"></div></a>
</article><!-- /.node -->
<div class="clearfix"></div>
