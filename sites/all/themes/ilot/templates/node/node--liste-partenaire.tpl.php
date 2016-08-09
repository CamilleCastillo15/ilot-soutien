<?php
    $visuel_asso = variable_get("ilot_theme_partenaires_visuel");
    $file = file_load($visuel_asso);
//    $img = file_create_url($file->uri);
    $img = image_style_url("header", $file->uri);
?>
<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title">partenaires</div>
</div>
 <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <ul><li><a href="">Tous les partenaires</a></li></ul>
  <?php print render($content['block_filters']); ?>
  <div class="clearfix"></div>
  <?php print $views_liste_partenaire; ?>

</article><!-- /.node -->
<div class="clearfix"></div>
