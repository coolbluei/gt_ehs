<?php

/**
 * @file
 * Default theme implementation to display a Mercury item.
 *
 * Available variables:
 * - $node: The guts of the Mercury item
 * - $fields: An array of flags indicating which fields should be used. If a flag is
 *   not present, the associated field is not to be used.
 *
 * @todo: Break out node parts into individual variables.
 */
?>

<div class="hg-item-wrapper clearfix">

  <div class="hg-item-body">

  <!-- BODY MATERIAL FOLLOWS -->

  <!-- News specific body material -->
  <?php if ($node['type'] == 'news'): ?>
    <?php if (in_array('Subtitle', $fields)) : ?>
      <h2 class="hg-item-news-subtitle"><?php print $node['subtitle']; ?></h2>
    <?php endif; ?>
    <?php if (count(array_intersect(array('Dateline', 'Location'), $fields)) > 0) : ?>
      <p class="hg-item-news-dateline"><em>
      <?php if (in_array('Dateline', $fields)) { print format_date(strtotime($node['dateline']), 'custom', 'M j, Y'); } ?>
      <?php if (in_array('Dateline', $fields) && in_array('Location', $fields) && $node['location'] != '') : ?> | <?php endif; ?>
      <?php if (in_array('Location', $fields) && $node['location'] != '') : ?> <strong><?php print $node['location']; ?></strong><?php endif; ?>
      </em></p>
    <?php endif; ?>
  <?php endif; ?>

  <!-- External news specific stuff -->
  <?php if ($node['type'] == 'hgTechInTheNews'): ?>

    <h2 class="hg-item-external-title"><a href="<?php print $node['article_url']; ?>"><?php print $node['article_url']; ?></a></h2>
    <h3 class="hg-item-external-publication"><em><?php print $node['publication']; ?></em> &mdash; <?php print format_date(strtotime($node['dateline']), 'custom', 'M j, Y'); ?></h3>

  <?php endif; ?>

  <?php print $node['body']; ?>

  </div>


  <!-- SIDEBAR MATERIAL FOLLOWS -->

  <!-- Event specific sidebar material -->
  <?php if ($node['type'] == 'event'): ?>
    <div class="hg-sidebar">
      <h4 class="hg-sidebar-header">Event Details</h4>
      <div class="hg-sidebar-content">
        <div class="hg-event-time">
          <?php $times_count = count($node['times']); ?>
          <p class="hg-event-detail-label"><?php print format_plural($times_count, 'Date', 'Dates'); ?>/<?php print format_plural($times_count, 'Time', 'Times'); ?>:</p>
          <ul class="hg-event-detail-content">
            <?php for ($i = 0; $i < $times_count; $i++) : ?>
              <li>
                <?php print date('l, F j, Y', strtotime($node['times'][$i]['startdate'])) . '<br />'; ?>
                <?php if (date('His', strtotime($node['times'][$i]['startdate'])) != '000000') { print date(' g:i a', strtotime($node['times'][$i]['startdate'])); } ?>
                <?php
                if (date('Ymd', strtotime($node['times'][$i]['startdate'])) != date('Ymd', strtotime($node['times'][$i]['stopdate']))) {
                  print ' - ' . date('l, F j, Y', strtotime($node['times'][$i]['stopdate'])) . '<br />';
                  if (date('His', strtotime($node['times'][$i]['stopdate'])) != '000000') { print date(' g:i a', strtotime($node['times'][$i]['stopdate'])); }
                } else {
                  if (date('His', strtotime($node['times'][$i]['stopdate'])) != '000000' && (date('His', strtotime($node['times'][$i]['startdate'])) != date('His', strtotime($node['times'][$i]['stopdate'])))) { print date(' - g:i a', strtotime($node['times'][$i]['stopdate'])); }
                }
                ?>
              </li>
            <?php endfor; ?>
          </ul>
        </div>

        <?php if (in_array('Location', $fields) && isset($node['location']) && $node['location'] != ''): ?>
          <div class="hg-event-location"><span class="hg-event-detail-label">Location:</span> <span class="hg-event-detail-content"><?php print $node['location']; ?></span></div>
        <?php endif; ?>
        <?php if (in_array('Location phone', $fields) && isset($node['locationphone']) && $node['locationphone'] != ''): ?>
          <div class="hg-event-phone"><span class="hg-event-detail-label">Phone:</span> <span class="hg-event-detail-content"><?php print $node['locationphone']; ?></span></div>
        <?php endif; ?>
        <?php if (in_array('Location email', $fields) && isset($node['locationemail']) && $node['locationemail'] != ''): ?>
          <div class="hg-event-email"><span class="hg-event-detail-label">Email:</span> <span class="hg-event-detail-content"><?php print $node['locationemail']; ?></span></div>
        <?php endif; ?>
        <?php if (in_array('Location URL', $fields) && isset($node['locationurl']) && $node['locationurl'] != ''): ?>
          <div class="hg-event-url"><span class="hg-event-detail-label">URL:</span> <span class="hg-event-detail-content"><a href="<?php print $node['locationurl']; ?>"><?php print $node['location'] ? $node['location'] : $node['locationurl']; ?></a></span></div>
        <?php endif; ?>
        <?php if (in_array('Fee', $fields) && isset($node['fee']) && $node['fee'] != ''): ?>
          <div class="hg-event-fee"><span class="hg-event-detail-label">Fee(s):</span> <span class="hg-event-detail-content"><?php print $node['fee']; ?></span></div>
        <?php endif; ?>
        <?php if (in_array('Extras', $fields) && !empty($node['extras']) && $node['extras'][0]['extratype'] != ''): ?>
          <div class="hg-event-extras"><span class="hg-event-detail-label">Extra(s):</span>
              <span class="hg-event-detail-content">
                <?php
                $extras = array_map(function($item) { return $item['extratype']; }, $node['extras']);
                print implode(', ', $extras);
                ?>
              </span>
          </div>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>

  <!-- Media -->
  <?php if (in_array('Media', $fields) && isset($node['media'][0]) && ($node['media'][0]['nodeid'] != '' || count($node['media']) > 1)) { print $media; } ?>

  <!-- Contact -->
  <?php if (in_array('Contact', $fields) && $node['contact']) : ?>
    <div class="hg-sidebar">
      <h4 class="hg-sidebar-header">For More Information Contact</h4>
      <div class="hg-sidebar-content">
        <?php print $node['contact']; ?>
      </div>
    </div>
  <?php endif; ?>

  <!-- Related files -->
  <?php if (in_array('Related files', $fields) && $node['files']) : ?>
    <div class="hg-sidebar">
      <h4 class="hg-sidebar-header">Related Files</h4>
      <ul class="hg-related-files-list">
        <?php foreach ($node['files'] as $file) : ?>
          <?php $file['description'] != '' ? $file_name = $file['description'] : $file_name = $file['filename']; ?>
          <li class="hg-related-files-file"><a href="<?php print base_path(); ?>hg/file/<?php print $file['fid']; ?>"><?php print $file_name; ?></a></li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>

  <!-- Related links -->
  <?php if (in_array('Related links', $fields) && $node['links']) : ?>
    <div class="hg-sidebar">
      <h4 class="hg-sidebar-header">Related Links</h4>
      <div class="hg-sidebar-content">
        <ul class="hg-related-links-list">
          <?php foreach ($node['links'] as $link) : ?>
            <li class="hg-related-links-link"><a href="<?php print $link['linkurl']; ?>"><?php print $link['linktitle']; ?></a></li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>
  <?php endif; ?>
  <!-- End general stuff -->

</div>
