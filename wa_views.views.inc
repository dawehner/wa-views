<?php
// $Id$



/**
 * Implements hook_views_data().
 */
function wa_views_views_data() {
  $data = array();
  $data['wolfram_alpha'] = array(
  );
  $data['wolfram_alpha']['table']['group'] = t('Wolfram Alpha');
  // Try whether it's flexible enough.
  $data['wolfram_alpha']['table']['base'] = array(
    'field' => 'id',
    'query class' => 'wolfram_alpha',
    'title' => t('wa'),
    'help' => t('wa'),
  );
  $data['wolfram_alpha']['search'] = array(
    'title' => t('wa: Filter key'),
    'help' => '',
    'filter' => array(
      'handler' => 'wa_views_handler_filter_search',
    ),
  );
  $data['wolfram_alpha']['markup'] = array(
    'title' => t('wa: markup'),
    'help' => '',
    'field' => array(
      'handler' => 'wa_views_handler_field_value',
    ),
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
