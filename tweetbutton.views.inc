<?php
// $Id$

function tweetbutton_views_data() {
  $data = array();
  
  $data['node']['tweetbutton'] = array(
    'field' => array(
      'title' => t('Tweet button'),
      'help' => t('Provide a tweet button field.'),
      'handler' => 'views_handler_field_tweetbutton',
    ),
  );

  return $data;
}
