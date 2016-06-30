<?php

/**
 * Create the default accueil.
 */
function ilot_standard_profile_create_accueil() {
  // Create node
  $node = new stdClass();
  $node->type = 'accueil';
  node_object_prepare($node);
  $node->title = 'Un accueil, un toit, Un nouveau départ';
  $node->status = 1;
  $node->uid = 1;
  $node->field_accueil_edito = array(
    LANGUAGE_NONE => array(
      variable_get('ilot_standard_profile_edito_nid', array('target_id' => 1)),
    ),
  );
  node_save($node);
  variable_set('site_frontpage', 'node/' . $node->nid);
}

/**
 * Create the default edito.
 */
function ilot_standard_profile_create_edito() {
  // Create node
  $node = new stdClass();
  $node->type = 'edito';
  node_object_prepare($node);
  $node->title = 'Edito n°1';
  $node->status = 1;
  $node->uid = 1;
  $node->field_edito_corps = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "“Il ne saurait y avoir une fatalité du chômage mais il y a des compétences, des solidarités,des énergies à mobiliser pour réussir. Nous savons que des personnes auront toujours besoin d’être accueillies, écoutées, accompagnées dans une période particulièrement difficile de leur vie.”",
        'format' => 'full_html',
      ),
    ),
  );
  $node->field_edito_nom = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Jean Celier",
        'format' => NULL,
      ),
    ),
  );
  $node->field_edito_fonction = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Président de l'ILOT",
        'format' => NULL,
      ),
    ),
  );
  node_save($node);
  variable_set('ilot_standard_profile_edito_nid', array('target_id' => $node->nid));
}

/**
 * Create the default liste actu.
 */
function ilot_standard_profile_create_liste_actu() {
  // Create node
  $node = new stdClass();
  $node->type = 'liste_actualites';
  node_object_prepare($node);
  $node->title = 'Actualités';
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = 'Actus';
  $node->menu['description'] = '';
  $node->menu['plid'] = 0;
  $node->menu['weight'] = 30;
  $node->menu['options']['attributes']['class'] = "actualite";
  node_save($node);
}

/**
 * Create the default liste projet.
 */
function ilot_standard_profile_create_liste_projet() {
  // Create node
  $node = new stdClass();
  $node->type = 'liste_projets';
  node_object_prepare($node);
  $node->title = 'Projets';
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = 'Nos projets';
  $node->menu['description'] = '';
  $node->menu['plid'] = 0;
  $node->menu['weight'] = 10;
  $node->menu['options']['attributes']['class'] = "projet";
  node_save($node);
}

/**
 * Create the default liste témoignage.
 */
function ilot_standard_profile_create_liste_temoignage() {
  // Create node
  $node = new stdClass();
  $node->type = 'liste_temoignage';
  node_object_prepare($node);
  $node->title = 'Témoignages';
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = 'Témoignages';
  $node->menu['description'] = '';
  $node->menu['plid'] = 0;
  $node->menu['weight'] = 20;
  $node->menu['options']['attributes']['class'] = "temoignage";
  node_save($node);
}

/**
 * Create the default liste partenaire.
 */
function ilot_standard_profile_create_liste_partenaire() {
  // Create node
  $node = new stdClass();
  $node->type = 'liste_partenaire';
  node_object_prepare($node);
  $node->title = 'Partenaires';
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = 'Partenaire';
  $node->menu['description'] = '';
  $node->menu['plid'] = variable_get('ilot_standard_profile_install_assos_mlid', 1);
  $node->menu['weight'] = 10;
  $node->menu['options']['attributes']['class'] = "partenaire";
  node_save($node);
}

/**
 * Create the default liste rapport activite.
 */
function ilot_standard_profile_create_liste_rapport_activite() {
  // Create node
  $node = new stdClass();
  $node->type = 'liste_rapport_activite';
  node_object_prepare($node);
  $node->title = "Rapport d'activité";
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = "Rapport d'activité";
  $node->menu['description'] = '';
  $node->menu['plid'] = variable_get('ilot_standard_profile_install_assos_mlid', 1);
  $node->menu['weight'] = 10;
  $node->menu['options']['attributes']['class'] = "rapport-activite";
  node_save($node);
}

/**
 * Create the default association.
 */
function ilot_standard_profile_create_association() {
  // Create node
  $node = new stdClass();
  $node->type = 'association';
  node_object_prepare($node);
  $node->title = "L'association";
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = "L'association";
  $node->menu['description'] = '';
  $node->menu['plid'] = 0;
  $node->menu['weight'] = -10;
  $node->menu['options']['attributes']['class'] = "association";

  $node->field_association_phrase_1 = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "LA PÉRENNITÉ DES CENTRES DE L’ÎLOT DÉPEND DE LA GÉNÉROSITÉ DE NOS DONATEURS.",
      ),
    ),
  );
  $node->field_association_phrase_2 = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "PERMETTEZ-NOUS DE CONTINUER À LUTTER CONTRE L’EXCLUSION ET LA RÉCIDIVE !",
      ),
    ),
  );
  $node->field_association_phrase_bouton = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Je soutiens les actions hébergement de l'ilot",
      ),
    ),
  );

  node_save($node);
  $assos_mlid = $node->menu['mlid'];
  variable_set('ilot_standard_profile_install_assos_mlid', $assos_mlid);

  for ($i = 1; $i<4; $i++) {
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_association_contenu'));
    $field_collection_item->setHostEntity('node', $node);

    $field_collection_item->field_association_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "QUI SOMMES NOUS ?",
            ),
        ),
    );
    $field_collection_item->field_association_texte = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "<p><strong>L’Îlot est une association qui accueille des femmes et des hommes en grande difficulté, en particulier les sortants de prison et les personnes bénéficiant d’un aménagement de peine. Elle vient également en aide aux personnes sans domicile fixe. L’association met tout en œuvre pour leur permettre de reprendre pied dans la société afin d’éviter les situations de précarité sociale qui mènent à la récidive.</strong></p>
<p>L’Îlot se concentre sur l’hébergement et l’accompagnement des personnes dans leur démarche personnelle et volontaire visant à retrouver un statut de citoyen et de membre du corps social, par l’accès au logement et à l’emploi. L’accompagnement inclut des actions d’insertion par l’activité économique.</p></ul>",
                'format' => 'full_html',
            ),
        ),
    );
    $field_collection_item->field_association_presentation = array(
      LANGUAGE_NONE => array(
        array(
          'value' => "standard",
        ),
      ),
    );

    if($i == 2) {
      $field_collection_item->field_association_presentation = array(
        LANGUAGE_NONE => array(
          array(
            'value' => "vert",
          ),
        ),
      );
      $field_collection_item->field_association_titre = array(
          LANGUAGE_NONE => array(
              array(
                  'value' => "L'Ilot",
              ),
          ),
      );
      $field_collection_item->field_association_sous_titre = array(
          LANGUAGE_NONE => array(
              array(
                  'value' => 'En quelques chiffres',
              ),
          ),
      );
      $field_collection_item->field_association_texte = array(
          LANGUAGE_NONE => array(
              array(
                  'value' => "<p>Le rétablissement ou la reconstruction de la personne, la réinsertion sociale et professionnelle, sont des processus complémentaires et itératifs qui exigent du temps et de la persévérance.  Notre obligation permanente consiste à aider les résidants à atteindre les objectifs qu’ils se sont fixés, ou à les adapter si nécessaire.</p><ul><li>Se reconstruire</li><li>Se repositionner dans la société, dans ses droits et devoirs</li><li>Préparer son départ de la résidence</li></ul>",
                  'format' => 'full_html',
              ),
          ),
      );
    }
    elseif($i > 2) {
      $field_collection_item->field_association_presentation = array(
        LANGUAGE_NONE => array(
          array(
            'value' => "gris",
          ),
        ),
      );
      $field_collection_item->field_association_titre = array(
          LANGUAGE_NONE => array(
              array(
                  'value' => "Trois axes d'actions",
              ),
          ),
      );
      $field_collection_item->field_association_sous_titre = array(
          LANGUAGE_NONE => array(
              array(
                  'value' => 'Pour se reconstruire',
              ),
          ),
      );
      $field_collection_item->field_association_texte = array(
          LANGUAGE_NONE => array(
              array(
                  'value' => "<p>Le rétablissement ou la reconstruction de la personne, la réinsertion sociale et professionnelle, sont des processus complémentaires et itératifs qui exigent du temps et de la persévérance.  Notre obligation permanente consiste à aider les résidants à atteindre les objectifs qu’ils se sont fixés, ou à les adapter si nécessaire.</p><ul><li>Se reconstruire</li><li>Se repositionner dans la société, dans ses droits et devoirs</li><li>Préparer son départ de la résidence</li></ul>",
                  'format' => 'full_html',
              ),
          ),
      );
    }
    $field_collection_item->save();
  }
}

/**
 * Create the default mission.
 */
function ilot_standard_profile_create_mission() {
  // Create node
  $node = new stdClass();
  $node->type = 'mission';
  node_object_prepare($node);
  $node->title = 'Nos missions';
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = 'Nos missions';
  $node->menu['description'] = '';
  $node->menu['plid'] = variable_get('ilot_standard_profile_install_assos_mlid', 1);
  $node->menu['weight'] = 10;
  $node->menu['options']['attributes']['class'] = "mission";


  $node->field_mission_introduction = array(
      LANGUAGE_NONE => array(
          array(
            'value' => "<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam elementum libero a lorem rutrum, a dictum nisl sagittis. Nam eleifend eleifend nulla, ac mollis velit bibendum eu. Quisque mattis ligula aliquam, tempor quam vel, malesuada augue. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Pellentesque pulvinar, diam ac mattis ullamcorper, urna nulla tincidunt diam, vitae pulvinar risus lectus eu ipsum. Fusce eleifend dolor ac lorem facilisis auctor. Etiam ut venenatis ante.<p>",
            'format' => "full html",
          ),
      ),
  );

  node_save($node);

  for ($i = 1; $i<4; $i++) {
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_mission_missions'));
    $field_collection_item->setHostEntity('node', $node);

    $field_collection_item->field_mission_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "Ateliers",
            ),
        ),
    );
    $field_collection_item->field_mission_sous_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "d'insertion",
            ),
        ),
    );
    $field_collection_item->field_mission_texte = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "<p>La Résidence Chemin Vert, à Paris accueille jusqu’à 60 hommes sortant de détention ou ayant un passé carcéral. Notre action s’établit selon trois axes :</p> <ul> <li><span style='color:#28bca4'>Se reconstruire</span></li> <li><span style='color:#28bca4'>Se repositionner dans la société, dans ses droits et devoirs</span></li> <li><span style='color:#28bca4'>Préparer son départ de la résidence</span></li> </ul> <p>6 chambres sont dédiées à l’hébergement de détenus placés sous surveillance électronique dans le cadre d’une convention passée avec l’administration pénitentiaire, 6 studios pour des hommes en fin de parcours d’insertion.*</p> <p><strong>Coût annuel moyen d’un résident&nbsp; en CHRS :</strong> <span style='color:#28bca4'>22000 euros</span></p>",
                'format' => 'full_html',
            ),
        ),
    );
    $field_collection_item->save();

    // BLOC
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_missions_blocs'));
    $field_collection_item->setHostEntity('node', $node);

    $field_collection_item->field_missions_bloc_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "Ateliers d'insertion",

            ),
        ),
    );
    $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
    $file = ilot_standard_profile_import_image($image_source_folder . '/missionsbloc.png' , 'images/blocs');
    $field_collection_item->field_missions_bloc_image = array(LANGUAGE_NONE => array($file));

    $field_collection_item->field_missions_bloc_sous_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "La mécanique",
            ),
        ),
    );
    $field_collection_item->field_missions_bloc_lien = array(
        LANGUAGE_NONE => array(
            array(
                'url' => "http://monsite.com",
            ),
        ),
    );
    $field_collection_item->save();
  }
}

/**
 * Create the default valeur.
 */
function ilot_standard_profile_create_valeur() {
  // Create node
  $node = new stdClass();
  $node->type = 'valeur';
  node_object_prepare($node);
  $node->title = 'Nos valeurs';
  $node->status = 1;
  $node->uid = 1;
  $node->menu['enabled'] = 1; // 1 to enable providing a link in main menu
  $node->menu['menu_name'] = 'main-menu';
  $node->menu['link_title'] = 'Nos valeurs';
  $node->menu['description'] = '';
  $node->menu['plid'] = variable_get('ilot_standard_profile_install_assos_mlid', 1);
  $node->menu['weight'] = 10;
  $node->menu['options']['attributes']['class'] = "valeur";

  node_save($node);

  for ($i = 1; $i<4; $i++) {
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_valeur_valeurs'));
    $field_collection_item->setHostEntity('node', $node);

    $field_collection_item->field_valeur_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "Foyers de vie et de stabilisation",
            ),
        ),
    );
    $field_collection_item->field_valeur_sous_titre = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "POUR HOMME, ACCUEIL DE JOUR",
            ),
        ),
    );
    $field_collection_item->field_valeur_texte = array(
        LANGUAGE_NONE => array(
            array(
                'value' => "<p>La Résidence Chemin Vert, à Paris accueille jusqu’à 60 hommes sortant de détention ou ayant un passé carcéral. Notre action s’établit selon trois axes :</p> <ul> <li><span style='color:#28bca4'>Se reconstruire</span></li> <li><span style='color:#28bca4'>Se repositionner dans la société, dans ses droits et devoirs</span></li> <li><span style='color:#28bca4'>Préparer son départ de la résidence</span></li> </ul> <p>6 chambres sont dédiées à l’hébergement de détenus placés sous surveillance électronique dans le cadre d’une convention passée avec l’administration pénitentiaire, 6 studios pour des hommes en fin de parcours d’insertion.*</p> <p><strong>Coût annuel moyen d’un résident&nbsp; en CHRS :</strong> <span style='color:#28bca4'>22000 euros</span></p>",
                'format' => 'full_html',
            ),
        ),
    );
    $field_collection_item->save();
  }
}

/**
 * Create actualites.
 */
function ilot_standard_profile_create_actualites() {
  for ($i = 1; $i<10; $i++) {
    $node = ilot_standard_profile_init_actualite();
    $node->title .= ' n°' . $i;
    $date = date('U');
    $timestamp = $i%2 ? $date - $i*1000000 : $date - $i*-100000;
    $date_actu = date('Y-m-d', $timestamp);
    $node->field_actualite_date[LANGUAGE_NONE][0]['value'] = $date_actu . 'T00:00:00';
    $node->created = $node->changed = $node->published_at = $timestamp;
    node_save($node);
    $queue = nodequeue_load_queue_by_name('accueil_actu_queue');
    $subqueue = nodequeue_load_subqueue($queue->qid);
    nodequeue_subqueue_add($queue, $subqueue, $node->nid);
  }
}

/**
 * Create temoignages.
 */
function ilot_standard_profile_create_temoignage() {
  for ($i = 1; $i<10; $i++) {
    $node = ilot_standard_profile_init_temoignage();
    $node->title .= ' n°' . $i;
    $date = date('U');
    $timestamp = $i%2 ? $date - $i*1000000 : $date - $i*-100000;
    $node->created = $node->changed = $node->published_at = $timestamp;
    node_save($node);
  }
}

/**
 * Create projets.
 */
function ilot_standard_profile_create_projets() {
  for ($i = 1; $i<10; $i++) {
    $node = ilot_standard_profile_init_projet();
    $node->title .= ' n°' . $i;
    $date = date('U');
    $timestamp = $i%2 ? $date - $i*1000000 : $date - $i*-100000;
    $node->created = $node->changed = $node->published_at = $timestamp;
    node_save($node);

  $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_projet_contenu'));
  $field_collection_item->setHostEntity('node', $node);

  $field_collection_item->field_projet_contenu_titre = array(
      LANGUAGE_NONE => array(
          array(
              'value' => 'Mon projet ',
          ),
      ),
  );
  $field_collection_item->field_projet_contenu_sous_titre = array(
      LANGUAGE_NONE => array(
          array(
              'value' => 'permettra',
          ),
      ),
  );
  $field_collection_item->field_projet_contenu_texte = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "<p>L’Îlot est en train de créer, à l’emplacement de la Passerelle, un lieu d’accueil unique pour le jour et pour la nuit. Nous voulons qu’il soit non seulement un point de repère sécurisant pour les personnes en situation d’exclusion, mais aussi un lieu qui rende possible un meilleur accompagnement personnalisé vers la socialisation. L'ancienne passerelle a été rasée et est à ce jour en cours de reconstruction. Elle sera remplacée par un bâtiment dont le rez-de-chaussée sera consacré à l’accueil en journée : le restaurant social, l’accueil médical, les locaux d’activité. Les étages seront distribués en chambres individuelles. Les travaux ont débuté en 2010. Les personnes accueillies sont provisoirement hébergées dans des locaux à proximité.</p>",
        'format' => 'full_html',
      ),
    ),
  );
  $field_collection_item->save();
  }
}

/**
 * Create chiffres clefs.
 */
function ilot_standard_profile_create_chiffres_clefs() {
  for ($i = 1; $i<4; $i++) {
    $node = ilot_standard_profile_init_chiffres_clefs();
    $node->title .= ' n°' . $i;
    $node->field_chiffres_clefs_chiffre = array(
      LANGUAGE_NONE => array(
        array(
          'value' => $i*10000 . " | Personnes",
        ),
      ),
    );
    $date = date('U');
    $timestamp = $i%2 ? $date - $i*1000000 : $date - $i*-100000;
    $node->created = $node->changed = $node->published_at = $timestamp;
    $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
    $file = ilot_standard_profile_import_image($image_source_folder . '/chiffres'.$i.'.jpg' , 'images/chiffres_clefs');
    $node->field_chiffres_clefs_image = array(LANGUAGE_NONE => array($file));
    node_save($node);
  }
}

/**
 * Create partenaire.
 */
function ilot_standard_profile_create_partenaire() {
  $terms = variable_get('ilot_standard_profile_type_partner_tids', array());
  $e = 0;
  for ($i = 1; $i<25; $i++) {

    $node = ilot_standard_profile_init_partenaire();
    $node->field_partenaire_type_partner = array(
    	LANGUAGE_NONE => array(
    	  0 => $terms[$e],
    	),
    );
    $node->title .= ' n°' . $i;
    node_save($node);
    if ($i==5 || $i==10) {
    	$e++;
    }
  }
}

/**
 * Create rapport d'activité.
 */
function ilot_standard_profile_create_rapport_activite() {
  for ($i = 1; $i<4; $i++) {
    $node = ilot_standard_profile_init_rapport_activite();
    $node->title .= ' n°' . $i;
    $node->field_rapport_activite_date = array(
      LANGUAGE_NONE => array(
        array(
          'value' => '201'.$i,
        ),
      ),
    );
    node_save($node);
  }
}

/**
 * Init the default projet.
 */
function ilot_standard_profile_init_projet() {
  // Create node
  $node = new stdClass();
  $node->type = 'projets';
  node_object_prepare($node);
  $node->title = 'Projet insertion';
  $node->status = 1;
  $node->uid = 1;
  $node->field_projet_liste_info = array(
    LANGUAGE_NONE => array(
      array(
        'value' => '<p>Personnes en grande précarité : sortants de prison, remise de peine</p> <p>Y places d’accueil de jour et de nuit</p> <p>Un cadre de vie sécurisant</p> <p>L’accompagnement social vers la reinsertion</p>',
        'format' => 'full_html',
      ),
    ),
  );
  $node->field_projet_accoche = array(
    LANGUAGE_NONE => array(
      array(
        'value' => 'L’Îlot figure au premier rang des acteurs amiénois de l’accueil et de prise en charge des personnes sans domicile, sans ressources ou avec de très faibles ressources. La Balise sociale, anciennement située rue des Augustins, offrait un accueil hommes-femmes en journée et une restauration gratuite le midi ; la Passerelle, dans un autre quartier de la ville, proposait aux hommes un hébergement de nuit avec les repas du soir et du matin.',
        'format' => NULL,
      ),
    ),
  );
  $node->field_projet_sous_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => 'L”ACCUEIL SANS CONDITION À AMIENS, JOUR & NUIT',
      ),
    ),
  );
  $node->field_projet_nom = array(
    LANGUAGE_NONE => array(
      array(
        'value' => 'Domique Grenadine',
      ),
    ),
  );
  $node->field_projet_telephone = array(
    LANGUAGE_NONE => array(
      array(
        'value' => '05 46 79 15 48',
      ),
    ),
  );
  $node->field_projet_mail = array(
    LANGUAGE_NONE => array(
      array(
        'value' => 'dominique@mail.com',
      ),
    ),
  );
  $node->field_projet_info_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Établissement",
      ),
    ),
  );
  $node->field_projet_info_sous_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "ouvert 24h/24",
      ),
    ),
  );

  $node->field_projet_temoignage_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Témoignages",
      ),
    ),
  );
  $node->field_projet_temoin_sous_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Ludovic - Ancien de L'Ilot / Hébergement",
      ),
    ),
  );
  $node->field_projet_temoin_citation = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "« Et puis ici, on a un toit, on sait où dormir le soir, on peut se laver, manger. On a beaucoup de soutien avec les éducateurs. »",
        'format' => NULL,
      ),
    ),
  );
  $node->field_projet_info_primary_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Accueil & Accompagnements",
      ),
    ),
  );
  $node->field_projet_info_primary_texte = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "<p>Passerelle pourra accueillir Y personnes 365 jours par an, jour et nuit.</p>",
        'format' => 'full_html',
      ),
    ),
  );
  $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
  $file = ilot_standard_profile_import_image($image_source_folder . '/projet.jpg' , 'images/projet');
  $node->field_projet_image_accroche = array(LANGUAGE_NONE => array($file));

  return $node;
}

/**
 * Init the default actualite.
 */
function ilot_standard_profile_init_actualite() {
  // Create node
  $node = new stdClass();
  $node->type = 'actualites';
  node_object_prepare($node);
  $titles = array(
  	'Donner a ceux qui ont le plus besoin la possIbilité de se reconstruire',
    'Préparer la sortie par le travail',
    'Redonner un statut social À ceux qui l’ont perdu',
    'Un enjeu pour notre société future',
  );
  $node->title = $titles[mt_rand(0, 3)];
  $node->status = 1;
  $node->uid = 1;
  $node->field_actualite_corps = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "<p>Car c’est désormais à l’aune de sa capacité d’assurer à chacun les conditions qui lui permettront de « se&nbsp;réaliser », de « remonter sur le cheval » quand, par malheur, il en est tombé, que la République parviendra à recréer du lien social, à faire partager de nouveaux projets collectifs. Au rebours des politiques « d’assistance » qui aboutissent trop souvent à maintenir les bénéficiaires dans la dépendance, il faut ici promouvoir des mesures d’équité propres à donner aux individus les moyens de forger leur pleine autonomie. Les aspirations privées sont, en effet, devenues la première source des enjeux publics, qu’il s’agisse d’éduca¬tion, de santé, de formation professionnelle, de justice ou de réinsertion. Ce renversement, qui est en soi une bonne nouvelle puisqu’il concrétise enfin la vocation des démocraties à se mettre au service des citoyens, a, comme j’ai eu l’occasion de le montrer ailleurs, des racines profondes dans notre histoire : la « déconstruc¬tion » des idéaux traditionnels (patriotiques, révolutionnaires, spirituels), qui s’est opérée dans notre culture et dans nos moeurs au long des deux derniers siècles, a été détournée à son profit (c’est le cas de le dire) par le capitalisme mondialisé, lequel avait besoin de ce recul des « grands récits » collectifs pour imposer le triomphe du renouvellement incessant des valeurs de la mode et de la consommation ; or, au sein de ce « monde de la technique », « la croissance pour la croissance » n’a plus d’autre but qu’elle-même, à l’exclusion de toute autre finalité humaine supérieure, si bien qu’il ne reste que les attentes et les sentiments individuels pour reconstruire des visées communes, des idéaux partagés</p>",
        'format' => 'full_html',
      ),
    ),
  );
  $node->field_actualite_video = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "http://www.youtube.com/watch?v=B-dbncuq5zo",
        'format' => 'video_link',
      ),
    ),
  );
  $node->field_actualite_accroche = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "C’est un enjeu pour notre société future que de se préoccuper de l’avenir des personnes qui sortent de prison. ",
      ),
    ),
  );
  $node->field_actualite_date = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "2013-08-01T00:00:00",
      ),
    ),
  );
  $node->field_actualite_auteur_nom = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Luc | Ferry",
      ),
    ),
  );
  $node->field_actualite_auteur_fonction = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Ancien Ministre Philosophe",
      ),
    ),
  );
  $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
  $file = ilot_standard_profile_import_image($image_source_folder . '/accroche_actu.jpg' , 'images/actualite');
  $node->field_actualite_image_accroche = array(LANGUAGE_NONE => array($file));

  return $node;
}

/**
 * Init the default temoignage.
 */
function ilot_standard_profile_init_temoignage() {
  // Create node
  $node = new stdClass();
  $node->type = 'temoignage';
  node_object_prepare($node);
  $node->title = 'Roland, 27 ans';
  $node->status = 1;
  $node->uid = 1;
  $node->field_temoignage_corps = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "<p>J’ai fait sept ans de prison. Je suis sorti l’année dernière en liberté conditionnelle parentale parce que j’ai des enfants. Quand je vois ce qu’ont vécu les autres jeunes pendant que j’étais enfermé, je suis en colère: j’ai perdu beaucoup de temps. J’ai 29 ans et je ne les ai pas vraiment parce qu’il y a plein de choses que je n’ai pas vécues.</p>",
        'format' => 'full_html',
      ),
    ),
  );
  $node->field_temoignage_accroche = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Le mitard, je n’arrive toujours pas en parler tellement c’est dégradant. Je ne veux pas y repenser. Je veux oublier.",
      ),
    ),
  );
  $node->field_temoignage_annee = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "1356994800",
      ),
    ),
  );
  $node->field_temoignage_sous_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "résident de l’ilot depuis 2012 parle de sa réinsertion",
      ),
    ),
  );
  $node->field_temoignage_type = array(
    LANGUAGE_NONE => array(
      array(
        'tid' => variable_get('ilot_standard_profile_type_temoignage_tid'),
      ),
    ),
  );
  $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
  $file = ilot_standard_profile_import_image($image_source_folder . '/temoignage.jpg' , 'images/temoignage');
  $node->field_temoignage_image = array(LANGUAGE_NONE => array($file));

  return $node;
}

/**
 * Init the default chiffres clefs.
 */
function ilot_standard_profile_init_chiffres_clefs() {
  // Create node
  $node = new stdClass();
  $node->type = 'chiffres_clefs';
  node_object_prepare($node);
  $node->title = 'Chiffres Clefs';
  $node->status = 1;
  $node->uid = 1;
  $node->field_chiffres_clefs_accroche = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "Sortent de prison chaque année. La prévention de la récidive est importante",
      ),
    ),
  );
  $node->field_chiffres_clefs_descriptif = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "<p>Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?</p>",
        'format' => 'full_html',
      ),
    ),
  );

  return $node;
}

/**
 * Init the default partenaire.
 */
function ilot_standard_profile_init_partenaire() {
  // Create node
  $node = new stdClass();
  $node->type = 'partenaire';
  node_object_prepare($node);
  $node->title = "LA DIRECTION DÉPARTEMENTALE ET INTerdépartementale l'Hébergement et du Logement (DRIHL)";
  $node->status = 1;
  $node->uid = 1;
  $node->field_partenaire_lien = array(
    LANGUAGE_NONE => array(
      array(
        'url' => "http://monsite.com",
      ),
    ),
  );
  $node->field_partenaire_sous_titre = array(
    LANGUAGE_NONE => array(
      array(
        'value' => "De paris et du val de marne",
      ),
    ),
  );

  $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
  $file = ilot_standard_profile_import_image($image_source_folder . '/partenaire.jpg' , 'images/partenaire');
  $node->field_partenaire_logo = array(LANGUAGE_NONE => array($file));

  return $node;
}

/**
 * Init the default rapport d'activité.
 */
function ilot_standard_profile_init_rapport_activite() {
  // Create node
  $node = new stdClass();
  $node->type = 'rapport_activite';
  node_object_prepare($node);
  $node->title = "Rapport d'activité";
  $node->status = 1;
  $node->uid = 1;
  $node->field_rapport_activite_texte = array(
      LANGUAGE_NONE => array(
          array(
            'value' => "En 2011, il s’agit d’abord d’une transition au sens littéral du terme : logés dans des locaux temporaires et exigus, les équipes des Augustins et de la Passerelle sont réellement en transit, attendant de pouvoir emménager dans leurs nouveaux locaux à l’automne 2012. Mais tous les autres établissements sont également dans une phase de transition, vers un nouveau mode de fonctionnement : qu’il s’agisse des ateliers de l’Îlot, des établissements de Chemin Vert, du Val-de-Marne ou de Thuillier, sans parler bien sûr de la Passerelle et des Augustins, chaque équipe travaille sur son projet d’établissement, ses objectifs, ses méthodes. Ce travail, entamé en 2011, se poursuivra pendant l’année 2012.",
            'format' => 'full_html',
          ),
      ),
  );

  $image_source_folder = drupal_get_path('profile', 'ilot_standard') . '/images';
  $file = ilot_standard_profile_import_image($image_source_folder . '/rapport_activite.pdf' , 'rapport-activite');
  $file['display'] = 1;
  $file2 = ilot_standard_profile_import_image($image_source_folder . '/rapport_activite.pdf' , 'rapport-activite');
  $file2['display'] = 1;
  $node->field_rapport_activite_fichier = array(LANGUAGE_NONE => array($file, $file2));

  return $node;
}
