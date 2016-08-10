<div class="container-page">

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	
  
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
  ?>
  
  
  
      <h1><?php print $title; ?></h1>
      <?php print render($content['body']); ?>
      <?php print render($content['field_page_intro_legs']); ?>
      <?php print render($content['field_page_intro_donations']); ?>
      <?php print render($content['field_page_intro_assurances_vie']); ?>

</article>



</div>
