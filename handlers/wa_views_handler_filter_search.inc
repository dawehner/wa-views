<?php
// $Id$

class wa_views_handler_filter_search extends views_handler_filter {
  function query() {
    $this->query->add_where('input', $this->value);
  }
}