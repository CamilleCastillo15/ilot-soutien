<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php
    hide($content['field_association_phrase_bouton']);
    print render($content);
  ?>
  <div class="icone-set">
    <?php print render($content['print_links']);?>
    <?php print render($content['sharethis']);?>
  </div>
  <?php if(!empty($content['field_association_phrase_bouton'])): ?>
    <a class="don" href="/faire-un-don"><span><?php print render($content['field_association_phrase_bouton'])?></span><span class="don-btn">Faire un don</span></a>
  <?php endif; ?>
  </article><!-- /.node -->
<aside class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<h1>Témoignages</h1>
<?php print $views_temoignages_contextuel; ?>
<div class="bandeau-don">
<span><?php print render($content['field_association_phrase_bouton'])?></span>
<a href="/faire-un-don">Faire un don</a>
</div>
</aside>
<div class="clearfix"></div>
