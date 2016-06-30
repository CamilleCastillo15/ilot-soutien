<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content <?php print render($content['field_projet_contenu_pres']['#items'][0]['value']); ?>"<?php print $content_attributes; ?>>
    <?php
      hide($content['field_projet_contenu_pres']);
      print render($content);
      ?>
  </div>
</div>