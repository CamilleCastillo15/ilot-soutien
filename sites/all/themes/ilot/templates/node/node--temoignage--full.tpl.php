<?php

   $title_principal = $node->title;

   $visuel = variable_get("ilot_theme_temoignages_visuel");
   $file = file_load($visuel);
   $img = image_style_url("header", $file->uri);

?>

<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title"><?php print render($title_principal);?></div>
</div>

   <div class="container-page">
    <article class="full-temoignage node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <div class="bloc">
          <div class="vignette">
            <?php print render($content['field_temoignage_image']); ?>
          </div>
          <div class="texte">
              <h2><?php print $node->title; ?></h2>
              <?php if(!empty($content['field_temoignage_sous_titre'])): ?>
              <h3><?php print render($content['field_temoignage_sous_titre']); ?></h3>
              <?php endif; ?>
           </div>
           <div class="icone-set">
            <?php print render($content['print_links']);?>
            <?php print render($content['sharethis']);?>
           </div>
       </div>

      <?php print render($content['field_temoignage_accroche']); ?>
      <?php print render($content['field_temoignage_corps']); ?>
      <?php print render($content['field_temoignage_annee_txt']); ?>
      <div class="nav-next-prev">
        <?php if (isset($prev)) :
          print l('témoignage précédent', 'node/'.$prev, array('attributes' => array('class' => 'prev read-more')));
          endif;
        ?>
        <?php if (isset($next)) :
          print l('témoignage suivant', 'node/'.$next, array('attributes' => array('class' => 'next read-more')));
          endif;
        ?>
      </div>
    </article>
</div>
