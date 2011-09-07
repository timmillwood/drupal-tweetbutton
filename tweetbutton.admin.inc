<?php



function tweetbutton_admin_settings() {
	$form = array();
  
  $form['button'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose your button. Customize it'),
  );
  
  $form['button']['tweetbutton_button'] = array(
    '#type' => 'select',
    '#options' => array(
      'vertical' => t('Vertical Count'),
      'horizontal' => t('Horizontal Count'),
      'none'   => t('No count'),
    ),
    '#default_value' => variable_get('tweetbutton_button', 'vertical'),
    '#id' => 'tweetbutton-button',
  );
  
  
  $form['button']['tweetbutton_tweet_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Tweet Text'),
    '#default_value' => variable_get('tweetbutton_tweet_text'),
  );

  $form['button']['tokens'] = array(
    '#token_types' => array('node'),
    '#theme' => 'token_tree',
  );  

  $form['button']['tweetbutton_language'] = array(
    '#title' => t('Language'),
    '#description' => t('This is the language that the button will render in on your website. People will see the Tweet dialog in their selected language for Twitter.com.'),
    '#type' => 'select',
    '#options' => array(
      'en'   => t('English'),
      'fr'   => t('French'),
      'de'   => t('German'),
      'es'   => t('Spanish'),
      'ja'   => t('Japanese'),
      'auto' => t('Automatic'),
    ),
    '#default_value' => variable_get('tweetbutton_language'),
  );
  
  $form['follow'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recommend people to follow'),
  );
  
  $form['follow']['tweetbutton_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter account to follow'),
    '#description' => t('This user will be @mentioned in the suggested'),
    '#default_value' => variable_get('tweetbutton_account'),
    '#id' => 'tweetbutton-account',
  );
  
  $form['follow']['tweetbutton_rel_account_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Related Account'),
    '#default_value' => variable_get('tweetbutton_rel_account_name'),
  );
  
  $form['follow']['tweetbutton_rel_account_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Related Account Description'),
    '#default_value' => variable_get('tweetbutton_rel_account_description'),
  );

  return system_settings_form($form);
}

function tweetbutton_node_settings() {
	$form = array();
  
  $node_types = node_type_get_types();
  foreach($node_types as $node_type) {
    $types[$node_type->type] = $node_type->name;
  }
  
  $form['tweetbutton_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Types'),
    '#options' => $types,
    '#default_value' => variable_get('tweetbutton_node_types', array('article')),
  );
  
  $options = array();
  $entity_info = entity_get_info('node');
  $view_modes = $entity_info['view modes'];
  foreach($view_modes as $name => $info) {
    $options[$name] = $info['label'];
  }
  
  $options['links'] = t('Node links');
  
  $form['tweetbutton_node_location'] = array(
    '#type'    => 'checkboxes',
    '#title'   => t('Locations'),
    '#options' => $options,
    '#default_value' => variable_get('tweetbutton_node_location', array('full')),
  );
  
  
  $form['tweetbutton_node_weight'] = array(
    '#type'          => 'weight',
    '#title'         => t('Weight'),
    '#default_value' => variable_get('tweetbutton_node_weight', -5),
    '#description'   => t('Heavier weight will sink button to bottom on node view'),
  );
  
  return system_settings_form($form);
}