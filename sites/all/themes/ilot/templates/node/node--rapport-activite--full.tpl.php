<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <h1>Rapport</h1>
  <h2>d'activité <?php print render($content['field_rapport_activite_date'])?></h2>
  <?php
  hide($content['field_rapport_activite_fichier']);
  hide($content['print_links']);
  print render($content);
  ?>
  <?php foreach ($rapport_links as $rapport_link) : ?>
  <a href="<?php print $rapport_link; ?>">Télécharger le rapport d'activité <?php print render($content['field_rapport_activite_date'])?></a>
  <span>Format PDF</span>
  <?php endforeach; ?>
  </article><!-- /.node -->