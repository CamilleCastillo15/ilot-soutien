<?php
/**
 * @file
 * ilot_accueil.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ilot_accueil_default_rules_configuration() {
  $items = array();
  $items['rules_ajout_actu_queue'] = entity_import('rules_config', '{ "rules_ajout_actu_queue" : {
      "LABEL" : "Ajouter a liste d\\u0027actualit\\u00e9",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Ilot" ],
      "REQUIRES" : [ "rules", "nodequeue", "nodequeue_rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "actualites" : "actualites" } }
          }
        }
      ],
      "DO" : [
        { "nodequeue_add_action" : { "node" : [ "node" ], "queue" : { "value" : { "1" : "1" } } } }
      ]
    }
  }');
  return $items;
}
