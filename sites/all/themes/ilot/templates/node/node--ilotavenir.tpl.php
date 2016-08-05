
<?php

    $fc_blocs_textes = field_get_items('node', $node, 'field_blocs_images_textes');

    if($fc_blocs_textes){
        $idti = array();
        foreach ($fc_blocs_textes as $fc_field) {
            $idti[] = $fc_field['value'];
        }
        $collectionsg =  field_collection_item_load_multiple($idti);
    }

//    dpm($collectionsg);

?>

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

            <?php print render($image) ?>
            <h1><?php print render($titre) ?></h1>
            <?php print render($texte) ?>

      <?php } ?>
    </article><!-- /.node -->
</div>

<div class="clearfix"></div>
