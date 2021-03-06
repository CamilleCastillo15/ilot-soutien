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
    <article >
        <?php
            for($i = 0; $i < count($views); $i++) {

               $node = $views[$i];
               dpm($node);
               dpm($views[$i]);

               $type = field_view_field('node', $node, 'field_type_actualite');
//               $type = field_view_field('node', $node[''.$i.''], 'field_type_actualite');
//               print render($type);
               $date = field_view_field('node', $node[''.$i.''], 'field_actualite_date');
//                print render($date);

               $title = $node[''.$i.'']->title;
               dpm($title);

               $title_principal = $node->title;
              $title_principal = $node[''.$i.'']->title;
               $texte = field_view_field('node', $node[''.$i.''], 'field_actualite_accroche');
               $texte_trimmed = field_view_field("node",$node[''.$i.''],'field_actualite_accroche',array(
                  'label' => 'hidden',
                  'type' => 'text_summary_or_trimmed',
                  'settings'=>array('trim_length' => 100),
               ));

               $texte_summary = render($texte_trimmed)."...";

               $texte_render = render($texte);
               $texte_render_substr = substr($texte_render, 0, 250)."...";
               $image = field_view_field('node', $node[''.$i.''], 'field_actualite_image_accroche');

               $nid = $node->nid;


        ?>

        <div class="liste-actus-generales-container gb">
            <div class="vignette"><?php print render($image) ?></div>
            <div class="texte">
                <h1><?php print render($type) ?></h1>
                <div class='sous-titre'><?php print render($title_principal) ?></div><br />
                 <div class='date'><?php print render($date) ?></div><br />
                <?php print $texte_summary;  ?>
                <?php print l('Voir plus', '/node/'.$nid, array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
            </div>
        </div>

       <?php } ?>
    </article>

</div>
