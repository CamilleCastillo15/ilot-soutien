<article class="node-<?php print $node->nid; ?> <?php print render($content['field_partenaire_type_partner']);?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_partenaire_logo'])?>
  <h2><?php print $node->title; ?></h2>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
  <!--<h3><?php //print render($content['field_partenaire_sous_titre']); ?></h3>-->
  <?php
    $dlien = field_get_items("node",$node,'field_partenaire_lien');
  ?>
  <?php print l("<div class='read-more'>Accéder au site</div>", $dlien[0]["url"], array("html"=>true, 'external' => TRUE,  'attributes' => array('class' => array( 'lien_partenaire'),'target'=>'_blank'))); ?>
</article><!-- /.node -->
