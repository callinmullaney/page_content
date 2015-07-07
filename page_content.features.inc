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
      "icon" : "photo",
      "widget" : {
        "assetWidgetLink" : { "status" : 1 },
        "assetWidgetCaption" : { "status" : 1 }
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
      "icon" : "file-picture-o"
    },
    "rdf_mapping" : [],
    "public" : false
  }');
  $items['video'] = entity_import('asset_type', '{
    "type" : "video",
    "name" : "Video",
    "plural" : "Videos",
    "data" : { "path" : "admin\\/media\\/videos", "icon" : "video-camera" },
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
