<?php
// $Id$

class wa_views_plugin_query_wa extends views_plugin_query {
  var $query_url = 'http://api.wolframalpha.com/v2/query?';

  function option_definition() {
    $options = parent::option_definition();

    $options['appid'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['appid'] = array(
      '#type' => 'textfield',
      '#title' => t('Appid'),
      '#description' => t('Type in the appid which woflramalpha gave you'),
      '#default_value' => $this->options['appid'],
    );
  }

  function query($get_count = FALSE) {
    $query = array();
    $query['appid'] = $this->options['appid'];
    $query = array_merge($this->where, $query);

    return url($query_url, array('query' => $query));
  }

  function execute(&$view) {
    $query = $this->build_info['query'];
    $start = microtime(TRUE);

    $result = simplexml_load_file($query);

    foreach ($result as $pod) {
      $view->result[] = (object) (array) $pod;
    }

    $end = microtime(TRUE);
    $view->execute_time = $end - $start;
  }
  
  function add_where($key, $value) {
    $this->where[$key] = $value; 
  }
}