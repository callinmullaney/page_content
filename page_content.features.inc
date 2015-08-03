<?php
/**
 * @file
 * page_content.features.inc
 */

/**
 * Implements hook_default_asset_type().
 */
function page_content_default_asset_type() {
  $items = array();
  $items['file'] = entity_import('asset_type', '{
    "type" : "file",
    "name" : "File",
    "plural" : "Files",
    "data" : { "path" : "admin\\/media\\/files", "usage_info" : 1, "icon" : "file" },
    "rdf_mapping" : [],
    "public" : false
  }');
  $items['image'] = entity_import('asset_type', '{
    "type" : "image",
    "name" : "Image",
    "plural" : "Images",
    "data" : {
      "path" : "admin\\/media\\/image",
      "usage_info" : 1,
      "instance_info" : 1,
      "icon" : "photo",
      "widget" : {
        "assetWidgetImageStyle" : {
          "status" : 1,
          "settings" : {
            "content_full" : "Full",
            "content_medium" : "Medium",
            "content_small" : "Small"
          }
        },
        "assetWidgetPosition" : { "status" : 1 },
        "assetWidgetCaption" : { "status" : 1 },
        "assetWidgetLink" : { "status" : 1 }
      }
    },
    "rdf_mapping" : [],
    "public" : true
  }');
  $items['slide'] = entity_import('asset_type', '{
    "type" : "slide",
    "name" : "Slide",
    "plural" : "Slides",
    "data" : {
      "path" : "admin\\/manage\\/slides",
      "auto_title" : 1,
      "usage_info" : 1,
      "icon" : "file-picture-o"
    },
    "rdf_mapping" : [],
    "public" : false
  }');
  $items['video'] = entity_import('asset_type', '{
    "type" : "video",
    "name" : "Video",
    "plural" : "Videos",
    "data" : {
      "path" : "admin\\/media\\/videos",
      "usage_info" : 1,
      "icon" : "video-camera",
      "widget" : { "assetWidgetPlaceholder" : { "status" : 1 } }
    },
    "rdf_mapping" : [],
    "public" : false
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function page_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function page_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function page_content_image_default_styles() {
  $styles = array();

  // Exported image style: content_full.
  $styles['content_full'] = array(
    'label' => 'CONTENT | Full',
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 970,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_medium.
  $styles['content_medium'] = array(
    'label' => 'CONTENT | Medium',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_small.
  $styles['content_small'] = array(
    'label' => 'CONTENT | Small',
    'effects' => array(
      12 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 225,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function page_content_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
