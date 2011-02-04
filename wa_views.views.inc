<?php
// $Id$



/**
 * Implements hook_views_data().
 */
function wa_views_views_data() {
  $data = array();
  $data['wolfram_alpha'] = array(
  );
  return $data;
}

/**
 * Implements hook_views_plugins().
 *
 */
function wa_views_views_plugins() {
  $plugins = array();
  $plugins['query']['wolfram_alpha'] = array(
    'title' => t('Wolfram Alpha'),
    'help' => t('Sends a request against wolfram alpha.'),
    'handler' => 'wa_views_plugin_query_wa',
  );
  return $plugins;
}
