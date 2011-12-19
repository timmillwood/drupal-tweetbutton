<?php


/**
 * Implements of hook_views_data_alter().
 */
function tweetbutton_views_data() {
  $data = array();

  $data['tweetbutton']['table']['group'] = t('tweet button');

  $data['tweetbutton']['table']['join'] = array(
    '#global' => array(),
  );

  $data['tweetbutton']['tweetbutton'] = array(
    'group' => t('tweet button'),
    'field' => array(
      'title' => t('Tweet Button'),
      'help' => t('Tweet button for this node.'),
      'handler' => 'tweetbutton_handler_field_tweet',
    ),
  );

  return $data;
}


/**
 * Implements of hook_views_handlers().
 */
function tweetbutton_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'tweetbutton'),
    ),
    'handlers' => array(
      'tweetbutton_handler_field_tweet' => array(
        'parent' => 'views_handler_field_node',
      ),
    ),
  );
}
