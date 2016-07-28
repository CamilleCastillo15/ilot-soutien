<?php

//    $base = base_path();
//
    $newsletter_text = variable_get("ilot_theme_newsletter_text");

//    dpm($newsletter_text);

//    $file = file_load($visuel_offre);
//    $img = image_style_url("header", $file->uri);

?>

<div class="bloc-newsletter">

    <h1>Newsletter</h1>
    <?php print $newsletter_text['value'];?>

    <div class="newsletter-form">
    <?php $form = node_load(271);
          $view = node_view($form);
          print render($view); ?>
    </div>
    <div class="clear"></div>

</div>
