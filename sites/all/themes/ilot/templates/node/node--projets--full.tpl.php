 <div class="container-page">

  <article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <h1><?php print $node->title; ?></h1>
    <?php if(!empty($node->field_projet_sous_titre)): ?>
      <h2><?php print render($content['field_projet_sous_titre']); ?></h2>
    <?php endif;?>
    <div class="icone-set">
      <?php print render($content['print_links']);?>
      <?php print render($content['sharethis']);?>
    </div>
    
    
    <?php if(!empty($content['field_projet_accoche'])):?>
      <?php print render($content['field_projet_accoche']); ?>
      <?php print render($content['field_projet_bloc_texte']); ?>
    <?php endif; ?>
   
    <div class="info-projet">
      <div class="image-accroche"><?php print render($content['field_projet_image_accroche']);?></div>
      <div class="container-accroche">
        <?php print render($content['field_projet_info_titre']);?>
        <?php if(!empty($content['field_projet_info_sous_titre'])): ?>
          <?php print render($content['field_projet_info_sous_titre']);?>
        <?php endif; ?>
        <?php if(!empty($content['field_projet_liste_info'])): ?>
          <?php print render($content['field_projet_liste_info']);?>
        <?php endif; ?>
       </div>
    </div>
    <div class="clearfix"></div>
    <?php if (!empty($node->field_projet_temoignage_titre) || !empty($node->field_projet_temoin_sous_titre) || !empty($node->field_projet_temoin_citation)) : ?>
      <div class="temoignage b-gris">
        <?php print render($content['field_projet_temoignage_titre']);?>
        <?php print render($content['field_projet_temoin_sous_titre']);?>
        <?php print render($content['field_projet_temoin_citation']);?>
      </div>
    <?php endif; ?>
     <?php if(!empty($content['field_projet_info_primary_titre']) || !empty($content['field_projet_info_primary_texte']) ): ?>
      <div class="info-primaire">
        <?php print render($content['field_projet_info_primary_titre'])?>
        <?php print render($content['field_projet_info_primary_texte'])?>
      </div>
      <?php endif;?>
    <?php if(!empty($content['field_projet_contenu'])): ?>
      <?php print render($content['field_projet_contenu'])?>
      <?php endif;?>
    <?php if(!empty($content['field_projet_nom']) || !empty($content['field_projet_telephone']) || !empty($content['field_projet_mail'])):?>
      <div class="contact">
      <h2 class="sous-titre">Pour en savoir plus</h2>
      <h3 class="sous-titre">Sur ce projet et nous soutenir</h3>
      <h3 class="contact">Contacter</h3>
        <?php if(!empty($content['field_projet_nom'])): ?>
          <?php print render($content['field_projet_nom']);?>
        <?php endif;?>
        <?php if(!empty($content['field_projet_telephone'])): ?>
          <?php print render($content['field_projet_telephone']);?>
        <?php endif;?>
        <?php if(!empty($content['field_projet_mail'])): ?>
          <?php print render($content['field_projet_mail']);?>
        <?php endif;?>
      </div>
    <?php endif; ?>


     <div class="bandeau-je-fais-don small bloc">
            <img src="/sites/all/themes/ilot/images/logo_coeur_rouge.svg" />
            <div class="col-1">
                Je soutiens les<br />
                actions de l’Îlot
                  <?php print l("<div class='don-btn'>Faire un don</div>", "", array("html"=>true)); ?>
            </div>
          
        </div>

    <div class="nav-next-prev">
      <?php if(isset($prev)) :
        print l('projet précédent', 'node/'.$prev, array('attributes' => array('class' => 'prev read-more')));
        endif;
      ?>
      <?php if(isset($next)) :
        print l('projet suivant', 'node/'.$next, array('attributes' => array('class' => 'next read-more')));
        endif;
      ?>
    </div>

  </article><!-- /.node -->

  <aside class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $views_actu_contextuel; ?>

  <div class="bandeau-je-fais-don small">
      <img src="/sites/all/themes/ilot/images/logo_coeur_rouge.svg" />
      <div class="col-1">
          Je soutiens les<br />
          actions de l’Îlot
      </div>
      <?php print l("<div class='don-btn'>Faire un don</div>", "", array("html"=>true)); ?>
  </div>


  </aside>
  <div class="clearfix"></div>

</div>
