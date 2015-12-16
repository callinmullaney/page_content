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
    "title" : "Files",
    "plural" : "Files",
    "data" : {
      "icon" : "file",
      "path" : "admin\\/media\\/files",
      "usage_info" : 1,
      "title_label" : "",
      "auto_title" : 0,
      "auto_title_pattern" : "",
      "render_title" : 0,
      "allow_status" : 0,
      "instance_info" : 0,
      "purge" : 0,
      "no_multiple" : 0,
      "require_instance" : 0,
      "viewable" : 0,
      "pathauto" : 0
    },
    "rdf_mapping" : [],
    "public" : false
  }');
  $items['image'] = entity_import('asset_type', '{
    "type" : "image",
    "title" : "Image",
    "plural" : "Images",
    "data" : {
      "icon" : "photo",
      "path" : "admin\\/media\\/image",
      "usage_info" : 1,
      "instance_info" : 1,
      "widget" : {
        "assetWidgetPosition" : { "status" : 1 },
        "assetWidgetImageStyle" : {
          "status" : 1,
          "settings" : {
            "content_full" : "Full Width",
            "content_half" : "Half Width",
            "content_quarter" : "Quarter Width"
          }
        },
        "assetWidgetLink" : { "status" : 1 },
        "assetWidgetCaption" : { "status" : 1 }
      },
      "viewable" : 0,
      "pathauto" : 0,
      "title_label" : "",
      "auto_title" : 0,
      "auto_title_pattern" : "",
      "render_title" : 0,
      "allow_status" : 0,
      "purge" : 0,
      "no_multiple" : 0,
      "require_instance" : 0
    },
    "rdf_mapping" : [],
    "public" : true
  }');
  $items['slide'] = entity_import('asset_type', '{
    "type" : "slide",
    "title" : "Slide",
    "plural" : "Slides",
    "data" : {
      "icon" : "file-photo-o",
      "path" : "admin\\/manage\\/slides",
      "usage_info" : 1,
      "auto_title" : 0,
      "auto_title_pattern" : "",
      "render_title" : 0,
      "allow_status" : 0,
      "instance_info" : 0,
      "purge" : 0,
      "no_multiple" : 0,
      "require_instance" : 0,
      "title_label" : "",
      "viewable" : 0,
      "pathauto" : 0
    },
    "rdf_mapping" : [],
    "public" : false
  }');
  $items['video'] = entity_import('asset_type', '{
    "type" : "video",
    "title" : "Video",
    "plural" : "Videos",
    "data" : {
      "icon" : "video-camera",
      "path" : "admin\\/media\\/videos",
      "usage_info" : 1,
      "widget" : { "assetWidgetPlaceholder" : { "status" : 1 } },
      "auto_title" : 0,
      "auto_title_pattern" : "",
      "render_title" : 0,
      "allow_status" : 0,
      "instance_info" : 0,
      "purge" : 0,
      "no_multiple" : 0,
      "require_instance" : 0,
      "title_label" : "",
      "viewable" : 0,
      "pathauto" : 0
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
  if ($module == "linkit" && $api == "linkit_profiles") {
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
