<?php
/**
 * @file
 * gt_calendar.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function gt_calendar_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gt_calendar_importer';
  $feeds_importer->config = array(
    'name' => 'GT Calendar (Feeds Importer)',
    'description' => 'Configuration maps data from a Mercury events Feed URL to the correct data fields in an Event on this site.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'concat(value,value/../../../@id)',
          'xpathparser:1' => 'value/../../../title',
          'xpathparser:2' => 'value',
          'xpathparser:3' => 'value2',
          'xpathparser:5' => 'value/../../../event_audience/term',
          'xpathparser:6' => 'value/../../../body',
          'xpathparser:7' => 'value/../../../event_terms/term',
          'xpathparser:8' => 'value/../../../contact',
          'xpathparser:10' => 'value/../../../fee',
          'xpathparser:13' => 'value/../../../location',
          'xpathparser:14' => 'value/../../../email',
          'xpathparser:16' => 'value/../../../url',
          'xpathparser:17' => 'value/../../../primary_group',
          'xpathparser:18' => 'value/../../../sidebar',
          'xpathparser:19' => 'value/../../../sticky',
          'xpathparser:20' => 'value/../../../summary',
          'xpathparser:21' => 'value/../../../sentence',
          'xpathparser:26' => 'concat(value,value/../../../@id)',
          'xpathparser:27' => 'concat(\'http://hg.gatech.edu/sites/default/files/imagecache/200xX_scale/\',value/../../../hg_media/item[type=\'image\']/image_name)',
          'xpathparser:28' => 'value/../../../hg_media/item[type=\'image\']/title',
          'xpathparser:29' => 'value/../../../@id',
          'xpathparser:30' => 'value/../../../files/file/full_path',
          'xpathparser:31' => 'value/../../../files/file/description',
          'xpathparser:33' => 'value/../../../related/link/title',
          'xpathparser:34' => 'value/../../../related/link/url',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:10' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:26' => 0,
          'xpathparser:27' => 0,
          'xpathparser:28' => 0,
          'xpathparser:29' => 0,
          'xpathparser:30' => 0,
          'xpathparser:31' => 0,
          'xpathparser:33' => 0,
          'xpathparser:34' => 0,
        ),
        'context' => '//nodes/node/gmt_times/item',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:10' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:26' => 0,
            'xpathparser:27' => 0,
            'xpathparser:28' => 0,
            'xpathparser:29' => 0,
            'xpathparser:30' => 0,
            'xpathparser:31' => 0,
            'xpathparser:33' => 0,
            'xpathparser:34' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_event_time:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_event_time:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_event_audience',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_event_body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_event_category',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_event_contact',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_event_fee',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_event_location',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_event_location_email',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_event_location_url:url',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_event_group_primary',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          13 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_event_sidebar',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:19',
            'target' => 'sticky',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_event_summary',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_event_summary_sentence',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_event_import_guid',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_event_image_url:url',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:28',
            'target' => 'field_event_image_url:title',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:29',
            'target' => 'field_event_nodeid',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'xpathparser:30',
            'target' => 'field_event_attachment_url:url',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'xpathparser:31',
            'target' => 'field_event_attachment_url:title',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'xpathparser:33',
            'target' => 'field_event_url_related:title',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'xpathparser:34',
            'target' => 'field_event_url_related:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'text_editor_basic',
        'skip_hash_check' => 0,
        'bundle' => 'event',
      ),
    ),
    'content_type' => 'gt_calendar_feed',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['gt_calendar_importer'] = $feeds_importer;

  return $export;
}
