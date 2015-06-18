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
  $items['downloadable'] = entity_import('asset_type', '{
    "type" : "downloadable",
    "name" : "Downloadable",
    "plural" : "Downloadables",
    "data" : {
      "path" : "admin\\/media\\/downloadable",
      "instance_info" : 1,
      "icon" : "download",
      "widget" : { "assetWidgetCaption" : { "status" : 1 } }
    },
    "rdf_mapping" : [],
    "public" : true
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
