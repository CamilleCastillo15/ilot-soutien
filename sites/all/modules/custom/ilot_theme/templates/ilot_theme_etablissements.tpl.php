<div class="ilot-etablissements">

    <div class="c-block-domaine">
        <?php

            for($i = 0; $i < count($view); $i++) {

                $node = $view[$i];
                dpm($node);

                $title = field_view_field("node",$node,'field_titre_de_la_case_study');
                $description = field_view_field("node",$node,'field_texte_case_study');
                $image = field_get_items("node",$node,'field_image_case_study');

            ?>

        <?php } ?>

    </div>

</div>
