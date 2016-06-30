<?php

/**
 * init a default user.
 */
function ilot_standard_init_user() {
	//This will generate a random password, you could set your own here
  $password = user_password(8);

  //set up the user fields
  $fields = array(
    'name' => 'user_name',
    'mail' => 'user_name@example.com',
    'pass' => $password,
    'status' => 1,
    'init' => 'user_name@example.com',
    'roles' => array(
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    ),
  );

}