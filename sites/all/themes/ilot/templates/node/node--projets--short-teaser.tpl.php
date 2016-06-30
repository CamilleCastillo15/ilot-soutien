<div class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($content['field_projet_image_accroche']); ?>
  <h2>
      <?php print l($node->title, 'node/'.$node->nid, array('html' => TRUE)); ?>
  </h2>
  <?php if(!empty($node->field_projet_sous_titre)): ?>
    <h3>
        <?php print l(render($content['field_projet_sous_titre']), 'node/'.$node->nid, array('html' => TRUE)); ?>
    </h3>
  <?php endif; ?>
  <?php /*print l('voir plus', 'node/'.$node->nid, array('attributes' => array('class' => 'read-more'))); */?>

  <?php print l("lire la suite", 'node/'.$node->nid, array("html"=>true, 'attributes' => array('class' => array('readmore')))); ?>

</div><!-- /.node -->
