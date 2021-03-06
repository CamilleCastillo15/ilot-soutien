<?php
    $visuel_asso = variable_get("ilot_theme_don_visuel");
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

      <h1><?php print $node->title; ?></h1>
      <div class="icone-set">
        <?php print render($content['print_links']);?>
        <?php print render($content['sharethis']);?>
      </div>

      <?php if(!empty($content['field_page_simple_contact'])):?>
       <div class="right-column-intro-categorie column-intro-categorie">

             <h1>Contact</h1>
              <?php print render($content['field_page_simple_contact']); ?>
        </div>
        <?php endif;?>

       <?php if(!empty($content['field_page_simple_contact'])):?>
       <div class="left-column-intro-categorie column-intro-categorie">
       <?php endif;?>

          <?php print render($content['field_page_simple_contenu']); ?>

       <?php if(!empty($content['field_page_simple_contact'])):?>
       </div>
       <?php endif;?>

    </article>

</div>

