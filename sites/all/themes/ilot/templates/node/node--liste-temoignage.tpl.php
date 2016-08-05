<div class="container-page full">
   <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <div class="liste-temoignages-container container-entreprises">
          <h1>Entreprises</h1>
          <?php print $views_liste_temoignage_entreprises; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-entreprises', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="liste-temoignages-container container-benevoles">
          <h1>Bénévoles</h1>
          <?php print $views_liste_temoignage_benevoles; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-benevoles', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="liste-temoignages-container container-donateurs">
          <h1>Donateurs</h1>
          <?php print $views_liste_temoignage_donateurs; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-donateurs', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="liste-temoignages-container container-partenaires">
          <h1>Partenaires</h1>
          <?php print $views_liste_temoignage_partenaires; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-partenaires', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="liste-temoignages-container container-partenaires">
          <h1>Personnes accueillies</h1>
          <?php print $views_liste_temoignage_residents; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-partenaires', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
      <div class="liste-temoignages-container container-partenaires">
          <h1>Salariés</h1>
          <?php print $views_liste_temoignage_salaries; ?>
          <?php print l('Lire d\'autres témoignages', '/temoignages-salaries', array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
      </div>
    </article><!-- /.node -->
</div>
<div class="clearfix"></div>
