<?php
/**
 * @file
 * ilot_image_style_configuration.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function ilot_image_style_configuration_filter_default_formats() {
  $formats = array();

  // Exported format: video link.
  $formats['video_link'] = array(
    'format' => 'video_link',
    'name' => 'video link',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'googtube' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'googtube_method' => 'embedded',
          'googtube_width' => 425,
          'googtube_height' => 344,
          'googtube_info_hw' => 1,
          'googtube_fs' => 1,
          'googtube_autoplay' => 0,
          'googtube_rel' => 0,
          'googtube_removed' => 1,
        ),
      ),
    ),
  );

  return $formats;
}
