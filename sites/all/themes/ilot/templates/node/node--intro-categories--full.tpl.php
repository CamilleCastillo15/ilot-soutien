<?php
    $visuel_asso = variable_get("ilot_theme_nous_soutenir_visuel");
    $file = file_load($visuel_asso);
//    $img = file_create_url($file->uri);
    $img = image_style_url("header", $file->uri);
?>

<div class="imagetitle">
    <div class="image">
        <img src="<?php print $img; ?>" alt="header" title="header" />
    </div>
    <div class="title"><?php print $title; ?></div>
</div>

 <div class="container-page">
    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
      ?>


        <div class="main-section-intro-categorie">
              <h1 class="main-title-cat"><?php print $title; ?></h1>
              <p class="accroche-intro-categorie"><?php print render($content['field_intro_categorie_accroche']); ?></p>
              <?php print render($content['body']); ?>
        </div>

       <!-- <div class="right-column-intro-categorie">

              <?php /*if(!empty($content['field_intro_categorie_photo'])):?>
              <?php print render($content['field_intro_categorie_photo']); ?>
              <h2>CONTACT</h2>
              <?php endif;?>


              <?php if(!empty($content['field_intro_categorie_contact'])):?>
              <p class="contact-intro-cat"><?php print render($content['field_intro_categorie_contact']); ?></p>
              <?php endif;?>

              <?php if(!empty($content['field_intro_categorie_telephone'])):?>
              <p class="tel"><?php print render($content['field_intro_categorie_telephone']); ?></p>
              <?php endif;?>

              <?php if(!empty($content['field_intro_categorie_email'])):?>
              <p class="email"><?php print render($content['field_intro_categorie_email']); ?></p>
              <?php endif;*/?>
        </div> -->

    </article>
</div>
<div class="clearfix"></div>
