<article class="actus teaser node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="offres-speciales-header">
      <div class="vignette img-actu">
        <a href="<?php print url('node/' . $node->nid); ?>">
        <?php  print render($content['field_actualite_image_accroche']); ?>
        </a>
        <span class="auteur"><?php if(!empty($auteur)){print $auteur;} ?></span>
      </div>
      <div class="date">
            <?php print $actualites_date; ?>
         <div class="icone-set socials">
            <?php print render($content['print_links']);?>
            <?php print render($content['sharethis']);?>
         </div>
      </div>
      <div class="text-actus texte">
        <h1><?php print l($node->title, 'node/'.$node->nid, array('html' => TRUE)); ?></h1>
        <div class="text-detail">
            <?php  print render($content['field_actualite_accroche']); ?>
        </div>
        <div class="readmore">
            <?php print l('voir plus', 'node/'.$node->nid, array('html' => TRUE, 'attributes' => array('class' => array('read-more')))); ?>
        </div>
      </div>
  </div>
</article><!-- /.node -->
