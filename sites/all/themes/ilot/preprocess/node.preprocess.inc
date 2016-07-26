<?php function ilot_preprocess_node(&$var) {
        $theme_path = drupal_get_path('theme', 'ilot');
        switch($var["type"]) {     
            case "home" :                
                console.log("preprocess");
            break;
        }
    }
?>


