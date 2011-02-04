<?php
// $Id$

class wa_views_plugin_query_wa extends views_plugin_query {
  public $query_url = 'http://api.wolframalpha.com/v2/query?';
  public $where = array();

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

  function build(&$view) {
    $view->init_pager();

    // Let the pager modify the query to add limits.
//     $this->pager->query();

    $view->build_info['query'] = $this->query();
    $view->build_info['count_query'] = $this->query(TRUE);
  }

  function query($get_count = FALSE) {
    $query = array();
    $query['appid'] = $this->options['appid'];
    $query['format'] = 'html';
    $query = array_merge($query, $this->where);

    $ret = url($this->query_url, array('query' => $query));
    return $ret;
  }

  function execute(&$view) {
    $query = $view->build_info['query'];
    $start = microtime(TRUE);

    $request = drupal_http_request($query);
    dsm($request);
    $result = simplexml_load_string($request->data);
    if ($result) {
      $rows = $result->xpath('/');
      foreach ($rows as $pod) {
        $view->result[] = $pod;
      }
    }

    $end = microtime(TRUE);
    $view->execute_time = $end - $start;
  }

  function add_where($key, $value) {
    $this->where[$key] = $value; 
  }
}