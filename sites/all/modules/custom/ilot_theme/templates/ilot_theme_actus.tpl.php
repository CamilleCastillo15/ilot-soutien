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
    <div class="title">actus</div>
</div>

<div class="container-page full">
    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
        <?php
            for($i = 0; $i < count($view); $i++) {

               $node = $view[$i];
//               $titre = field_view_field('node', $node, 'field_actualite_auteur_nom');

               $type = field_view_field('node', $node, 'field_type_actualite');

               $title_principal = $node->title;
               $texte = field_view_field('node', $node, 'field_actualite_accroche');

               $texte_trimmed = field_view_field("node",$node,'field_actualite_accroche',array(
                  'label' => 'hidden',
                  'type' => 'text_summary_or_trimmed',
                  'settings'=>array('trim_length' => 100),
               ));

               $texte_summary = render($texte_trimmed)."...";

               $texte_render = render($texte);
               $texte_render_substr = substr($texte_render, 0, 250)."...";
               $image = field_view_field('node', $node, 'field_actualite_image_accroche');

               $nid = $node->nid;

        ?>

        <div class="liste-actus-generales-container gb">
            <div class="vignette"><?php print render($image) ?></div>
            <div class="texte">
                <h2><?php print render($type) ?></h2>
                <div class='sous-titre'><?php print render($title_principal) ?></div>
                <?php print $texte_summary;  ?>
                <?php print l('Voir plus', '/node/'.$nid, array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
            </div>
        </div>

        <?php } ?>

    </article>

</div>
