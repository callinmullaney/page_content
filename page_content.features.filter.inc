<?php
/**
 * @file
 * page_content.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function page_content_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(
      'filter_url' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'transliteration' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'no_known_transliteration' => '?',
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  return $formats;
}
