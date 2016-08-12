<?php
    $visuel_asso = variable_get("ilot_theme_asso_visuel");
    $file = file_load($visuel_asso);
//    $img = file_create_url($file->uri);
    $img = image_style_url("header", $file->uri);
?>
<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title"><?php print $node->title; ?></div>
</div>

<div class="container-page">
    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="icone-set">
        <?php print render($content['print_links']);?>
        <?php print render($content['sharethis']);?>
      </div>
      <?php
        print render($content['field_mission_missions']);
      ?>


    </article>
    <aside class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($content['field_missions_blocs']); ?>
    </aside>
</div>
<div class="clearfix"></div>
