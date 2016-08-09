<div class="container-page full">

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
       <h1>hébergements</h1>

        <?php

            for($i = 0; $i < count($view); $i++) {

               $node = $view[$i];
               $titre = field_view_field('node', $node, 'field_titre_presentation');
               $sous_titre = field_view_field('node', $node, 'field_sous_titre_presentation');

               $texte = field_view_field('node', $node, 'field_texte_presentation');
               $image = field_view_field('node', $node, 'field_image_presentation');

               $title_principal = $node->title;

        ?>
        <div class="liste-etablissements-container gb">
            <div class="vignette"><?php print render($image) ?></div>
            <div class="texte"><h2><?php print render($title_principal) ?></h2>
              <h3><?php print render($titre) ?></h3>
              <div class='sous-titre'><?php print render($sous_titre) ?></div>
              <?php print render($texte) ?>
              <a href="" class="read-more">voir plus</a>
            </div>
        </div>

              <?php //} ?>

        <?php } ?>

    </article>

    <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
       <h1>Chantiers d'insertion</h1>

        <?php

            for($j = 0; $j < count($view_2); $j++) {

               $node = $view_2[$j];
               $titre = field_view_field('node', $node, 'field_titre_presentation');
               $sous_titre = field_view_field('node', $node, 'field_sous_titre_presentation');
               $texte = field_view_field('node', $node, 'field_texte_presentation');
               $image = field_view_field('node', $node, 'field_image_presentation');

               $title_principal = $node->title;

        ?>
              <div class="liste-etablissements-container gb">
                    <div class="vignette"><?php print render($image) ?></div>
                    <div class="texte"><h2><?php print render($title_principal) ?></h2>
                      <h3><?php print render($titre) ?></h3>
                      <div class='sous-titre'><?php print render($sous_titre) ?></div>
                      <?php print render($texte) ?>
                      <a href="" class="read-more">voir plus</a>
                    </div>
                </div>

              <?php //} ?>

        <?php } ?>

    </article>

</div>
