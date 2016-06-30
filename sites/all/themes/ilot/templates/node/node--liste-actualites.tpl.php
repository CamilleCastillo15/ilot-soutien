<div class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $views_liste_actu; ?>

</div><!-- /.node -->
<aside class="<?php print $classes; ?>">
<?php print render($content['archive_article']); ?>
</aside>
<div class="clearfix"></div>