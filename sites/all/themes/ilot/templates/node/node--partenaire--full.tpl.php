<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_partenaire_logo'])?>
  <h1><?php print $node->title; ?></h1>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
  <h2><?php print render($content['field_partenaire_sous_titre']); ?></h2>
  <?php print render($content['field_partenaire_lien']); ?>
</article><!-- /.node -->
<div class="clearfix"></div>