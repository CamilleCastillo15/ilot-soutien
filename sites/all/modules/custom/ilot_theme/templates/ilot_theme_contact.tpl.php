<?php

//    $base = base_path();
//
    $contact_text = variable_get("ilot_theme_contact_text");

//    dpm($newsletter_text);

//    $file = file_load($visuel_offre);
//    $img = image_style_url("header", $file->uri);

?>

<div class="bloc-contact">

    <h1>Contact</h1>
    <?php print $contact_text['value'];?>

    <div class="contact-btn">Envoyez - nous !</div>
    <div class="clear"></div>

</div>
