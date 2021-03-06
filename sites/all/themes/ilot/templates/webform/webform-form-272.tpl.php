<?php

    /**
     * @file
     * Customize the display of a complete webform.
     *
     * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
     * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
     * all webforms on your site.
     *
     * Available variables:
     * - $form: The complete form array.
     * - $nid: The node ID of the Webform.
     *
     * The $form array contains two main pieces:
     * - $form['submitted']: The main content of the user-created form.
     * - $form['details']: Internal information stored by Webform.
     *
     * If a preview is enabled, these keys will be available on the preview page:
     * - $form['preview_message']: The preview message renderable.
     * - $form['preview']: A renderable representing the entire submission preview.
     */

?>

<div class="email">

   <?php
    print drupal_render($form['submitted']['email']);
   ?>

 </div>

<div class="newsletter-btn read-more">

    <?php
        print drupal_render($form['actions']);
//        dpm($form);
    ?>

</div>

  <?php

      // Always print out the entire $form. This renders the remaining pieces of the
      // form that haven't yet been rendered above (buttons, hidden elements, etc).
      print drupal_render_children($form);

  ?>
