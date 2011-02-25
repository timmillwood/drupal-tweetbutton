<?php

function tweetbutton_views_data() {
  $data = array();
  
  $data['node']['tweetbutton'] = array(
    'field' => array(
      'title' => t('Tweet button'),
      'help' => t('Provide a tweet button field.'),
      'handler' => 'views_handler_field_tweetbutton_node',
    ),
  );
  
  $data['users']['tweetbutton'] = array(
    'field' => array(
      'title' => t('Tweet button'),
      'help' => t('Provide a tweet button field.'),
      'handler' => 'views_handler_field_tweetbutton_user',
    ),
  );
  
  $data['term_data']['tweetbutton'] = array(
    'field' => array(
      'title' => t('Tweet button'),
      'help' => t('Provide a tweet button field.'),
      'handler' => 'views_handler_field_tweetbutton_taxonomy',
    ),
  );
  
  return $data;
}
