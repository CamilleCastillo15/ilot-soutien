
<?php

    $fc_blocs_textes = field_get_items('node', $node, 'field_blocs_images_textes');
    $title_principal = $node->title;

    if($fc_blocs_textes){
        $idti = array();
        foreach ($fc_blocs_textes as $fc_field) {
            $idti[] = $fc_field['value'];
        }
        $collectionsg =  field_collection_item_load_multiple($idti);
    }

   $visuel_asso = variable_get("ilot_theme_etablissements_visuel");
   $file = file_load($visuel_asso);
   $img = image_style_url("header", $file->uri);

?>

<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title"><?php print render($title_principal);?></div>
</div>

<div class="container-page">
    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

      <div class="icone-set">
        <?php print render($content['print_links']);?>
        <?php print render($content['sharethis']);?>
      </div>

      <?php
           for($i = 0; $i < count($idti); $i++) {
               $collectionsg_2 = $collectionsg[$idti[$i]];
               $titre = field_view_field('field_collection_item', $collectionsg_2, 'field_titre');

               $texte = field_view_field('field_collection_item', $collectionsg_2, 'field_texte');
               $image = field_view_field('field_collection_item', $collectionsg_2, 'field_image');
        ?>
        <div class="bloc i-<?php print $i; ?>">

            <?php print render($image) ?>
        <h1><?php print render($titre) ?></h1>
            <?php print render($texte) ?>

            </div>

      <?php } ?>

      <?php

        $fc_bloc_contact = field_get_items('node', $node, 'field_contact');

        if($fc_bloc_contact){
        $idti_2 = array();
        foreach ($fc_bloc_contact as $fc_field) {
            $idti_2[] = $fc_field['value'];
                }
                $collectionsg_3 =  field_collection_item_load_multiple($idti_2);
            }

           for($j = 0; $j < count($idti_2); $j++) {
               $collectionsg_4 = $collectionsg_3[$idti_2[$j]];

               $adresse = field_view_field('field_collection_item', $collectionsg_4, 'field_adresse');
               $tel = field_view_field('field_collection_item', $collectionsg_4, 'field_telephone');
               $mail = field_view_field('field_collection_item', $collectionsg_4, 'field_mail');

        ?>

        <div class="bloc-contact vert ?>">

            <h1>Contact</h1>

            <?php print render($adresse) ?>
            <?php print render($tel) ?>
            <?php print render($mail) ?>

            </div>

      <?php } ?>


    </article><!-- /.node -->
</div>

<div class="clearfix"></div>
