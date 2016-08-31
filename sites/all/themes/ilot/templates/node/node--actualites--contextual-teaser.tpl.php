<?php /*

   $title_principal = $node->title;

   $visuel = variable_get("ilot_theme_temoignages_visuel");
   $file = file_load($visuel);
   $img = image_style_url("header", $file->uri);

?>

<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title"><?php print render($title_principal);?></div>
</div>  ?>

<?php /* <div class="container-page"> */ ?>
 <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="vignette">
    <?php print l(render($content['field_actualite_image_accroche']), 'node/'.$node->nid, array('html' => TRUE)); ?>
  </div>
  <div class="texte">
    <h3><?php print l($node->title, 'node/'.$node->nid, array('html' => TRUE)); ?></h3>
    <?php if(!empty($content['title'])): ?>
      <h4><?php print l(render($content['title']), 'node/'.$node->nid, array('html' => TRUE)); ?></h4>
    <?php endif; ?>
    <?php  if (isset($content['field_actualite_accroche'])) : ?>
      <?php print render($content['field_actualite_accroche']); ?>
    <?php endif;?>
  </div>

     <div class="clearfix"></div>
     <?php print l('voir plus', 'node/'.$node->nid, array('attributes' => array('class' => 'read-more'))); ?>

</article><!-- /.node -->
<?php /* </div> */ ?>
