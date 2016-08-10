<?php
    $visuel_asso = variable_get("ilot_theme_actus_generales_visuel");
    $file = file_load($visuel_asso);
//    $img = file_create_url($file->uri);
    $img = image_style_url("header", $file->uri);
?>
<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
<div class="title">actualités</div>
</div>
    <div class="container-page full">

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>


        <?php

            for($i = 0; $i < count($view); $i++) {

               $node = $view[$i];
               $titre = field_view_field('node', $node, 'field_titre_presentation');
               $sous_titre = field_view_field('node', $node, 'field_sous_titre_presentation');

               $texte = field_view_field('node', $node, 'field_texte_presentation');
               $image = field_view_field('node', $node, 'field_image_presentation');

               $title_principal = $node->title;
               $nid = $node->nid;

        ?>

        <div class="liste-actus-generales-container gb">
            <div class="vignette"><?php print render($image) ?></div>
            <div class="texte"><h2><?php print render($title_principal) ?></h2>
              <h3><?php print render($titre) ?></h3>
              <div class='sous-titre'><?php print render($sous_titre) ?></div>
              <?php print render($texte) ?>
              <a href="" class="read-more">voir plus</a>
            </div>
        </div>

              <?php print l('Voir plus', '/node/'.$nid, array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>

        <?php } ?>

    </article>

</div>
