<?php
// $Id$

/**
 * @TODO
 *   Build a generic field handler.
 */
class wa_views_handler_field_markup extends views_handler_field {
  /**
   * Do nothing in the query.
   */
  function query() { }
  function render($values) {
    // It's html so trust it???
    return (string) $values->markup;
  }
}