<?php


/**
 * Field handler to present the path to the node.
 */
class tweetbutton_handler_field_tweet extends views_handler_field_node {

  /**
   * query() override to not query this fake field.
   */
  function query() {
    $this->ensure_my_table();
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['layout'] = array('default' => 'none');
    $options['text'] = array('default' => '[node:title]');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['layout'] = array(
      '#type' => 'select',
      '#title' => t('Layout style'),
      '#default_value' => $this->options['layout'],
      '#description' => t('Set the layout for your tweet button'),
      '#options' => array('vertical' => 'Vertical Count', 'horizontal' => 'Horizontal Count', 'none' => 'No Count'),
    );
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Tweet Text'),
      '#default_value' => $this->options['text'],
      '#description' => t('Recommend a text for the tweet.'),
    );
    $form['tokens'] = array(
      '#token_types' => array('node'),
      '#theme' => 'token_tree',
    );
    
    // Remove irrelevant controls / settings.
    unset($form['empty']);
    unset($form['empty_zero']);
    unset($form['hide_empty']);
    unset($form['link_to_node']);
  }

  function render($values) {
    $nid = $values->nid;
    $node = node_load($nid);
    $url =  url("node/$nid", array('absolute' => TRUE));
    $tweet_button = theme_tweetbutton_display(array(
      'object' => $node,
      'options' => array(
        'url' => $url,
        'type' => $this->options['layout'],
        'text' => $this->options['text'],
      ),
    ));
    return $tweet_button;
  }
}
