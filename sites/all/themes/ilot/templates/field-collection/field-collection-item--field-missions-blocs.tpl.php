<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
 <?php $link_options = array('html' => TRUE); ?>
 <?php  print l(render($content['field_missions_bloc_image']), $link_url, $link_options); ?>
 <h3><?php  print l(render($content['field_missions_bloc_titre']), $link_url, $link_options); ?></h3>
 <h4><?php  print l(render($content['field_missions_bloc_sous_titre']), $link_url, $link_options); ?></h4>
</div>