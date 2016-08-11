<?php
    $visuel_asso = variable_get("ilot_theme_etablissements_visuel");
    $file = file_load($visuel_asso);
//    $img = file_create_url($file->uri);
    $img = image_style_url("header", $file->uri);
?>
<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title">établissements</div>
</div>

<div class="container-page full">

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

       <h1>hébergements</h1>

        <?php

            for($i = 0; $i < count($view); $i++) {

               $node = $view[$i];
               $titre = field_view_field('node', $node, 'field_titre_presentation');
               $sous_titre = field_view_field('node', $node, 'field_sous_titre_presentation');

               $texte = field_view_field('node', $node, 'field_texte_presentation');

               $texte_trimmed = field_view_field("node",$node,'field_texte_presentation',array(
                  'label' => 'hidden',
                  'type' => 'text_summary_or_trimmed',
                  'settings'=>array('trim_length' => 300),
               ));

               $texte_summary = render($texte_trimmed)."...";

               $texte_render = render($texte);
               $texte_render_substr = substr($texte_render, 0, 250)."...";

               $image = field_view_field('node', $node, 'field_actualite_image_accroche');

               $image = field_view_field('node', $node, 'field_image_presentation');

               $title_principal = $node->title;
               $nid = $node->nid;

        ?>

        <div class="liste-etablissements-container gb">
            <div class="vignette"><?php print render($image) ?></div>
            <div class="texte"><h2><?php print render($title_principal) ?></h2>
              <h3><?php print render($titre) ?></h3>
              <div class='sous-titre'><?php print render($sous_titre) ?></div>
              <?php print render($texte_summary) ?>
              <?php print l('Voir plus', '/node/'.$nid, array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
            </div>
        </div>

        <?php } ?>

    </article>

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
       <h1>Chantiers d'insertion</h1>

        <?php

            for($j = 0; $j < count($view_2); $j++) {
               $node = $view_2[$j];
               $titre = field_view_field('node', $node, 'field_titre_presentation');
               $sous_titre = field_view_field('node', $node, 'field_sous_titre_presentation');
               $texte = field_view_field('node', $node, 'field_texte_presentation');

               $texte_trimmed = field_view_field("node",$node,'field_texte_presentation',array(
                  'label' => 'hidden',
                  'type' => 'text_summary_or_trimmed',
                  'settings'=>array('trim_length' => 300),
               ));

               $texte_summary = render($texte_trimmed)."...";

               $image = field_view_field('node', $node, 'field_image_presentation');
               $title_principal = $node->title;

        ?>

              <div class="liste-etablissements-container gb">
                    <div class="vignette"><?php print render($image) ?></div>
                    <div class="texte"><h2><?php print render($title_principal) ?></h2>
                      <h3><?php print render($titre) ?></h3>
                      <div class='sous-titre'><?php print render($sous_titre) ?></div>
                      <?php print render($texte_summary) ?>
                      <?php print l('Voir plus', '/node/'.$nid, array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
                    </div>
                </div>

        <?php } ?>

    </article>

</div>
