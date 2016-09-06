<?php
    $lien = field_view_field("node",$node,'field_lien');
    $lien_render = render($lien);

    $image = field_view_field("node",$node,'field_image');
    $sous_titre = field_view_field("node",$node,'field_sous_titre');

    $date = field_view_field("node",$node,'field_date');
?>

 <article class="node-<?php print $node->nid; ?> <?php print render($content['field_type_de_medias']);?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($image)?>
  <h2><?php print $node->title; ?></h2>
  <?php //dpm($node); ?>
  <?php print render($sous_titre)?>
  <?php print render($date)?>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
<!--  <h3><?php //print render($content['field_partenaire_sous_titre']); ?></h3>-->

   <?php print l("<div class='read-more'>Accéder au site</div>", $lien_render, array("html"=>true, 'external' => TRUE,  'attributes' => array('class' => array( 'lien_partenaire'),'target'=>'_blank'))); ?>

</article><!-- /.node -->
