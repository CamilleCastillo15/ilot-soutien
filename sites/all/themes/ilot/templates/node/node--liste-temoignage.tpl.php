<?php
    $visuel_asso = variable_get("ilot_theme_temoignages_visuel");
    $file = file_load($visuel_asso);
//    $img = file_create_url($file->uri);
    $img = image_style_url("header", $file->uri);
?>
<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title">témoignages</div>
</div>
  <div class="container-page full">
   <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <div class="gb container-entreprises">
          <h1>Entreprises</h1>
          <?php print $views_liste_temoignage_entreprises; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-d-entreprises', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="gb container-benevoles">
          <h1>Bénévoles</h1>
          <?php print $views_liste_temoignage_benevoles; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-benevoles', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="gb container-donateurs">
          <h1>Donateurs</h1>
          <?php print $views_liste_temoignage_donateurs; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-donateurs', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="gb container-partenaires">
          <h1>Partenaires</h1>
          <?php print $views_liste_temoignage_partenaires; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-partenaires', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="gb container-residents">
          <h1>Personnes accueillies</h1>
          <?php print $views_liste_temoignage_residents; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-residants', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="gb container-partenaires">
          <h1>Salariés</h1>
          <?php print $views_liste_temoignage_salaries; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-salaries', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
    </article><!-- /.node -->
</div>
<div class="clearfix"></div>
