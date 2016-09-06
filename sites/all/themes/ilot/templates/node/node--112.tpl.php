
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
    <div class="title"><?php print $node->title; ?></div>
</div>

<div class="container-page">

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

          <?php
            // We hide the comments and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
          ?>

          <h1>
              <?php print $title; ?>
          </h1>

          <div class="right-column-intro-categorie column-intro-categorie">
              <?php if(!empty($content['field_intro_categorie_contact'])):?>
                  <h1>CONTACT</h1>
                  <p class="contact-intro-cat"><?php print render($content['field_intro_categorie_contact']); ?></p>
              <?php endif;?>
              <?php if(!empty($content['field_intro_categorie_telephone'])):?>
                  <p class="tel"><?php print render($content['field_intro_categorie_telephone']); ?></p>
              <?php endif;?>
              <?php if(!empty($content['field_intro_categorie_email'])):?>
                  <p class="email"><?php print render($content['field_intro_categorie_email']); ?></p>
              <?php endif;?>
           </div>

           <div class="left-column-intro-categorie column-intro-categorie">
              <?php print render($content['body']); ?>
           </div>

           <div class="clearfix"></div>

              <?php print render($content['field_page_intro_legs']); ?>
              <?php print render($content['field_page_intro_donations']); ?>
              <?php print render($content['field_page_intro_assurances_vie']); ?>
    </article>
</div>
