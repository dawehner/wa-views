<?php
// $Id$

class wa_views_handler_filter_search extends views_handler_filter {
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => t('Search key'),
      '#default_value' => $this->value,
    );
  }

  function query() {
    $this->query->add_where('input', $this->value[0]);
  }
}