<?php $classe = render($content['field_association_presentation']['#items'][0]['value']); ?>
<div class="<?php print $classes; ?> <?php print $classe; ?> clearfix"<?php print $attributes; ?>>
  <?php if ($classe == 'gris') : ?>
  <?php $path = drupal_get_path('theme', 'ilot'); ?>
    <img src="/<?php print $path . '/images/trombone.png'; ?>" />
  <?php endif; ?>
  <div class="content <?php print render($content['field_association_presentation']['#items'][0]['value']); ?>"<?php print $content_attributes; ?>>
    <?php
      hide($content['field_association_presentation']);
      print render($content);
      ?>
  </div>
</div>