<?php

class views_handler_field_tweetbutton extends views_handler_field {
  
  function construct() {
    parent::construct();
  }

  function option_definition() {
    
    $options['label'] = array('default' => $this->definition['title'], 'translatable' => TRUE);
    $options['tweetbutton_button'] = array('default' => 'vertical');
    $options['tweetbutton_text']   = array('default' => variable_get('tweetbutton_tweet_text','')); 
    return $options;
  }
  
  function allow_advanced_render() {
    return FALSE;
  }

  function query() {
    $this->ensure_my_table();    
    $this->add_additional_fields();
  }
  
  function options_form(&$form, &$form_state) {
    $form['label'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => isset($this->options['label']) ? $this->options['label'] : '',
      '#description' => t('The label for this field that will be displayed to end users if the style requires it.'),
    );

    $form['exclude'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude from display'),
      '#default_value' => $this->options['exclude'],
      '#description' => t('Check this box to not display this field, but still load it in the view.  Use this option to not show a grouping field in each record, or when doing advanced theming.'),
    );
    
    $form['tweetbutton_text'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Tweet Text'),
      '#default_value' => $this->options['tweetbutton_text'],
      '#description'   => t('This is the text that people will include in their Tweet when they share from your website. If left blank page title will be used. NOTE: Twitter will generate short url.'),
    );
  
    $form['tweetbutton'] = array(
      '#type'          => 'fieldset',
      '#title'         => t('Available Tokens'),
      '#collapsible'   => TRUE,
      '#collapsed'     => TRUE,
    );

    $form['tweetbutton']['tokens'] = array(
      '#value'  => theme('token_help', $this->options['entity_type']),
    );
    
    $form['tweetbutton_button'] = array(
      '#type' => 'select',
      '#options' => array(
        'vertical' => t('Vertical Count'),
        'horizontal' => t('Horizontal Count'),
        'none'   => t('No count'),
      ),
      '#title' => t('Tweetbutton type'),
      '#default_value' => $this->options['tweetbutton_button'],
    );
  }
}

class views_handler_field_tweetbutton_node extends views_handler_field_tweetbutton {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['entity_type'] = array('default' => 'node');
    return $options;
  }
  
  function render($values) {
    $nid = $values->{$this->aliases['nid']};

    $options['type']        = $this->options['tweetbutton_button'];
    $options['text']        = $this->options['tweetbutton_text'];
    $options['entity_type'] = $this->options['entity_type'];
    $options['url']         = url('node/' . $nid, array('absolute' => TRUE));
    
    $output = theme('tweetbutton_display', node_load($nid), $options);
    return $output;
  }
}

class views_handler_field_tweetbutton_user extends views_handler_field_tweetbutton {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['entity_type'] = array('default' => 'user');
    return $options;
  }
  
  function render($values) {
    $uid = $values->{$this->aliases['uid']};
    $options['type']        = $this->options['tweetbutton_button'];
    $options['text']        = $this->options['tweetbutton_text'];
    $options['entity_type'] = $this->options['entity_type'];
    $options['url']         = url('user/' . $uid, array('absolute' => TRUE));

    $output = theme('tweetbutton_display', user_load($uid), $options);
    return $output;
  }
}

class views_handler_field_tweetbutton_taxonomy extends views_handler_field_tweetbutton {
  
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = 'tid';
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['entity_type'] = array('default' => 'taxonomy');
    return $options;
  }
  
  function render($values) {
    $tid = $values->{$this->aliases['tid']};
    $options['type']        = $this->options['tweetbutton_button'];
    $options['text']        = $this->options['tweetbutton_text'];
    $options['entity_type'] = $this->options['entity_type'];
    $options['url']         = url('taxonomy/term/' . $tid, array('absolute' => TRUE));

    $output = theme('tweetbutton_display', taxonomy_get_term($tid), $options);
    return $output;
  }
}