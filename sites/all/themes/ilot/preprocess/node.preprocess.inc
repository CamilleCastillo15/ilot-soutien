<?php function ilot_preprocess_node(&$var) {
        $theme_path = drupal_get_path('theme', 'ilot');
        switch($var["type"]) {     
            case "accueil" :                
                drupal_add_js($theme_path."/js/Swiper/dist/js/swiper.jquery.min.js");
               
            break;
        }
    }
?>


