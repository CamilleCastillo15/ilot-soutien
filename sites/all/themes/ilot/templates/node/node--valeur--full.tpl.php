<?php
    $visuel_asso = variable_get("ilot_theme_valeurs_visuel");
    $file = file_load($visuel_asso);
    $img = image_style_url("header", $file->uri);
?>

<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title">Nos valeurs</div>
</div>

<div class="container-page">
    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <div class="icone-set">
        <?php print render($content['print_links']);?>
        <?php print render($content['sharethis']);?>
      </div>
      <?php
        print render($content);
      ?>
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
