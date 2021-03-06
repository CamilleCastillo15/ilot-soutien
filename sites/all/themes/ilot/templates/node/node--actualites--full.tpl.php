<?php /*
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
</div> */ ?>

 <div class="container-page">
  <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="vignette">
      <?php  print render($content['field_actualite_image_accroche']); ?>
    </div>
    <div class="texte">
      <div class="auteur"><?php if(!empty($auteur)){print $auteur;} ?></div>
      <h1><?php print $node->title; ?></h1>
    </div>
    <?php print $actualites_date; ?>
    <div class="icone-set">
      <?php print render($content['print_links']);?>
      <?php print render($content['sharethis']);?>
    </div>
    <div class="corps">
      <?php  print render($content['field_actualite_accroche']); ?>
      <?php  print render($content['field_actualite_corps']); ?>
      <?php if (isset($content['field_actualite_video'])): ?>
        <h2>Intervention</h2>
        <?php print render($content['field_actualite_video']); ?>
      <?php endif; ?>
       <div class="auteur"><?php if(!empty($auteur)){print $auteur;} ?></div>
      <?php if (isset($content['field_actualite_auteur_fonction'])): ?>
        <?php print render($content['field_actualite_auteur_fonction']); ?>
      <?php endif; ?>
    </div>
    <div class="nav-next-prev">
      <?php if(isset($prev)) :
        print l('actualité précédente', 'node/'.$prev, array('attributes' => array('class' => 'prev read-more')));
        endif;
      ?>
      <?php if(isset($next)) :
        print l('actualité suivante', 'node/'.$next, array('attributes' => array('class' => 'next read-more')));
        endif;
      ?>
    </div>
  </article><!-- /.node -->
</div>
<div class="clearfix"></div>
