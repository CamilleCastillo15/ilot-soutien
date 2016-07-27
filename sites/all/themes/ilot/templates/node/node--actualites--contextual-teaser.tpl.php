
  <div class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="vignette">
    <a href="<?php print url('node/' . $node->nid); ?>">
    <?php  print render($content['field_actualite_image_accroche']); ?>
    </a>
    <span class="auteur"><?php if(!empty($auteur)){print $auteur;} ?></span>
  </div>
  <div class="actu-short">
    <?php print $actualites_date; ?>
    <h2><?php print l($node->title, 'node/'.$node->nid, array('html' => TRUE)); ?></h2>
    <?php print l('voir plus', 'node/'.$node->nid, array('attributes' => array('class' => array('read-more')))); ?>
  </div>

</div><!-- /.node -->
