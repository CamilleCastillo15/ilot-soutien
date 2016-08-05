<article class="actus teaser node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

      <div class="vignette">
        <a href="<?php print url('node/' . $node->nid); ?>">
          <?php  print render($content['field_actualite_image_accroche']); ?>
        </a>
      </div>
      <div class="date">
         <?php print $actualites_date; ?>
         <div class="icone-set socials">
            <?php print render($content['print_links']);?>
            <?php print render($content['sharethis']);?>
         </div>
      </div>
      <div class="texte">
        <h1><?php print l($node->title, 'node/'.$node->nid, array('html' => TRUE)); ?></h1>
        <div class="text-detail">
            <?php  /*

                $accroche = field_view_field("node",$node,'field_actualite_accroche',array(
                  'label'=>'hidden',
                  'type' => 'text_summary_or_trimmed',
                  'settings'=>array('trim_length' => 50),
            ));

            print render($accroche);*/
            print render($content['field_actualite_accroche']);?>

        </div>
   <?php print l("lire la suite", 'node/'.$node->nid, array("html"=>true, 'attributes' => array('class' => array('readmore')))); ?>
      </div>
     
    
</article><!-- /.node -->
