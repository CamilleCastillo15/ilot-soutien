<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	
  
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
  ?>
  
      <?php print render($content['field_intro_categorie_photo']); ?>
      <h2><?php print $title; ?></h2>
      <?php print render($content['body']); ?>
      
    <?php print l('En savoir plus', 'node/'.$node->nid, array('attributes' => array('class' => array('read-more')))); ?>

</article>
