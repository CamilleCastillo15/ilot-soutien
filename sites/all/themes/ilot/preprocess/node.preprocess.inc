<?php function ilot_preprocess_node(&$var) {
        $theme_path = drupal_get_path('theme', 'ilot');
        switch($var["type"]) {     
            case "accueil" :                
                drupal_add_js($theme_path."/js/Swiper/dist/js/swiper.jquery.min.js");
            break;
        }
    }
?>




<?php
function ilot_preprocess_html(&$vars) {
  $viewport = array(
   '#tag' => 'meta',
   '#attributes' => array(
     'name' => 'viewport',
     'content' => 'width=device-width, initial-scale=1, maximum-scale=1',
   ),
  );
  drupal_add_html_head($viewport, 'viewport');
}
?>