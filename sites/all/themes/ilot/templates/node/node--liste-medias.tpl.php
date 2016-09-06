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
    <div class="title">l'ilôt dans les médias</div>
</div>
<div class="container-page">
   <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <ul class="block-filters"><li><a href="ilot-dans-les-medias">Tous les médias</a></li>
          <li><?php print render($content['block_filters']['#items']['0']); ?></li>
          <li><?php print render($content['block_filters']['#items']['1']); ?></li>
          <li><?php print render($content['block_filters']['#items']['2']); ?></li>
          <li><?php print render($content['block_filters']['#items']['3']); ?></li>
      </ul>
      <div class="clearfix"></div>
      <?php print $views_liste_medias; ?>

    </article><!-- /.node -->
</div>
<div class="clearfix"></div>
