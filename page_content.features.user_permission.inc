<?php
/**
 * @file
 * page_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function page_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any file asset'.
  $permissions['view any file asset'] = array(
    'name' => 'view any file asset',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'asset',
  );

  // Exported permission: 'view any image asset'.
  $permissions['view any image asset'] = array(
    'name' => 'view any image asset',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'asset',
  );

  // Exported permission: 'view any slide asset'.
  $permissions['view any slide asset'] = array(
    'name' => 'view any slide asset',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'asset',
  );

  // Exported permission: 'view any video asset'.
  $permissions['view any video asset'] = array(
    'name' => 'view any video asset',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'asset',
  );

  return $permissions;
}
