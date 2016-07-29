<?php

//    $base = base_path();
//
    $contact_text = variable_get("ilot_theme_contact_text");
    $contact_img = variable_get("ilot_theme_contact_img");
    $contact_icone = variable_get("ilot_theme_contact_icone");

    $file = file_load($newsletter_img);
    $img = image_style_url("header", $file->uri);

        $file = file_load($newsletter_img);
    $img = image_style_url("header", $file->uri);

?>

<div class="bloc-contact">

    <h1>Contact</h1>
    <?php print $contact_text['value'];?>

    <div class="contact-btn readmore">Contactez - nous !</div>
    <div class="clear"></div>

</div>
