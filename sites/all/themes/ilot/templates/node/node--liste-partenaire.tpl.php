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
    <div class="title">nos partenaires</div>
</div>
<div class="container-page">
   <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <ul class="block-filters"><li><a href="nos-partenaires">Tous les partenaires</a></li>
          <li><?php print render($content['block_filters']['#items']['0']); ?></li>
          <li><?php print render($content['block_filters']['#items']['1']); ?></li>
          <li><?php print render($content['block_filters']['#items']['2']); ?></li>
      </ul>
      <div class="clearfix"></div>
      <?php print $views_liste_partenaire; ?>

    </article><!-- /.node -->
        <aside class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
        <h1>Témoignages</h1>
        <?php print $views_temoignages_contextuel; ?>
        <div class="bandeau-je-fais-don">
            <img src="/sites/all/themes/ilot/images/logo_coeur_rouge.svg" />
            <div class="col-1">
                Je fais<br />
                un don
            </div>
            <?php print l("<div class='don-btn'>Accéder au formulaire</div>", "", array("html"=>true)); ?>
        </div>
    </aside>
</div>
<div class="clearfix"></div>
