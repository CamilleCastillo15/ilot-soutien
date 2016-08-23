<?php

//    $base = base_path();
//
    $contact_text = variable_get("ilot_theme_contact_text");
    $contact_img = variable_get("ilot_theme_contact_img");
    $contact_icone = variable_get("ilot_theme_contact_icone");

    $file = file_load($contact_img);
    $img = file_create_url($file->uri);

    $file_icone = file_load($contact_icone);
    $img_icone = file_create_url($file_icone ->uri);

?>

<div class="bloc-contact">

    <img src='<?php print $img ?>' alt='Contact' class='contact-img' />

    <div class="contact-text"><h1>Contact</h1><?php print $contact_text['value'];?></div>
    <!--  <img src='<?php print $img_icone ?>' alt='Téléphone' class='contact-icone' />-->
    <div class="contact-btn readmore">Contactez - nous !</div>
    <div class="clear"></div>

</div>
