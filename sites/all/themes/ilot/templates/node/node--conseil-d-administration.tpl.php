
<?php

    $fc_blocs_images_textes_membres_bureau = field_get_items('node', $node, 'field_blocs_images_textes');

    if($fc_blocs_images_textes_membres_bureau){
        $idti = array();
        foreach ($fc_blocs_images_textes_membres_bureau as $fc_field) {
            $idti[] = $fc_field['value'];
        }
        $collectionsg =  field_collection_item_load_multiple($idti);
    }

    $fc_blocs_images_textes_conseil = field_get_items('node', $node, 'field_blocs_images_textes_consei');

    if($fc_blocs_images_textes_conseil){
        $idti_2 = array();
        foreach ($fc_blocs_images_textes_conseil as $fc_field) {
            $idti_2[] = $fc_field['value'];
        }
        $collectionsg_2 =  field_collection_item_load_multiple($idti_2);
    }

?>

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
    <div class="title">Notre Conseil d'administration</div>
</div>

<div class="container-page">

     <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

          <div class="icone-set">
            <?php print render($content['print_links']);?>
            <?php print render($content['sharethis']);?>
          </div>

          <h1>Les membres du bureau</h1>

          <?php
               for($i = 0; $i < count($idti); $i++) {
                   $collectionsg_3 = $collectionsg[$idti[$i]];
                   $img = field_view_field('field_collection_item', $collectionsg_3, 'field_image');
            ?>

            <div id="membres_bureau_<?php print $i ?>" class="img-membres-bureau img-admin"><?php print render($img) ?></div>

      <?php } ?>

    </article>

<!--    <div class="container_details_conseil">-->

        <div class="details_conseil top">

              <?php
                   for($i = 0; $i < count($idti); $i++) {
                       $collectionsg_5 = $collectionsg[$idti[$i]];
                       $titre = field_view_field('field_collection_item', $collectionsg_5, 'field_titre');
                       $texte = field_view_field('field_collection_item', $collectionsg_5, 'field_texte');
                ?>
                    <div id="membres_bureau_<?php print $i ?>_textes">
                        <h1><?php print render($titre) ?></h1>
                        <?php print render($texte) ?>
                    </div>

              <?php } ?>

         </div>

<!--     </div>-->

    <div class="clearfix"></div>

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

      <h1>Les autres membres du conseil d'administration</h1>

       <?php
           for($i = 0; $i < count($idti_2); $i++) {
               $collectionsg_4 = $collectionsg_2[$idti_2[$i]];
               $img = field_view_field('field_collection_item', $collectionsg_4, 'field_image');
        ?>

            <div id="membres_conseil_<?php print $i ?>"  class="img-conseil-admin img-admin bottom"><?php print render($img) ?></div>

      <?php } ?>

    </article><!-- /.node -->

    <!--    <div class="container_details_conseil">-->

    <div class="details_conseil bottom">

       <?php
           for($i = 0; $i < count($idti_2); $i++) {
               $collectionsg_6 = $collectionsg_2[$idti_2[$i]];
               $titre = field_view_field('field_collection_item', $collectionsg_6, 'field_titre');
               $texte = field_view_field('field_collection_item', $collectionsg_6, 'field_valeur_texte');
        ?>

            <div id="membres_conseil_<?php print $i ?>_textes">
                <h1><?php print render($titre) ?></h1>
                <?php print render($texte) ?>
            </div>

      <?php } ?>

    </div>

<!--    </div>-->

</div>
<!--<div class="details_conseil">-->

      <?php /*
           for($i = 0; $i < count($idti); $i++) {
               $collectionsg_5 = $collectionsg[$idti[$i]];
               $titre = field_view_field('field_collection_item', $collectionsg_5, 'field_titre');
               $texte = field_view_field('field_collection_item', $collectionsg_5, 'field_texte');
        ?>
            <div id="membres_bureau_<?php print $i ?>_textes">
                <h1><?php print render($titre) ?></h1>
                <?php print render($texte) ?>
            </div>

      <?php } ?>

       <?php
           for($i = 0; $i < count($idti_2); $i++) {
               $collectionsg_6 = $collectionsg_2[$idti_2[$i]];
               $titre = field_view_field('field_collection_item', $collectionsg_6, 'field_titre');
               $texte = field_view_field('field_collection_item', $collectionsg_6, 'field_valeur_texte');
        ?>

            <div id="membres_conseil_<?php print $i ?>_textes">
                <h1><?php print render($titre) ?></h1>
                <?php print render($texte) ?>
            </div>

      <?php } */?>

<!--</div>-->

<div class="clearfix"></div>
