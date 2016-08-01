<?php

//    $base = base_path();
//
    $newsletter_text = variable_get("ilot_theme_newsletter_text");
    $newsletter_img = variable_get("ilot_theme_newsletter_img");

//    dpm($newsletter_text);

    $file = file_load($newsletter_img);
    $img = file_create_url($file->uri);

?>

<div class="bloc-newsletter">

   <img src='<?php print $img ?>' alt='Newsletter' class='newsletter-title' />

    <div class="col-1">

        <h1>Newsletter</h1>
        <?php print $newsletter_text['value'];?>

    </div>

    <div class="newsletter-form">
    <?php $form = node_load(272);
          $view = node_view($form);
          print render($view); ?>
    </div>
    <div class="clear"></div>

</div>
