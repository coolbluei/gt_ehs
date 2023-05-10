<?php

/**
 * @file
 * Default theme implementation to display a single Mercury feed.
 *
 * Available variables:
 *
 * - $classes: A string representation of HTML classes. "hg-feed" is included
 *   automatically; other classes are user-generated via the feed form.
 * - $feeds: An array of feed items. This is probably a dumb variable name and should
 *   be changed to "$items" or "$things" or even "$stuff" or something like that.
 * - $fields: An array of flags indicating which fields should be used. If a flag is
 *   not present, the associated field is not to be used.
 * - $page: A flag indicating whether the feed should be paged or not.
 * - $maximum: Show this many items per page, duh.
 * - $offset: Start with this item, duh.
 * - $total: The total number of items in the feed. You are thick, aren't you?
 * - $is_block: Is this feed being displayed in a block or a node? Find out with this!
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 *
 */
?>
<div class="hg-feed-wrapper <?php print $classes; ?>">
  <ul class="hg-feed hg-feed-list">
    <?php foreach ($feeds as $feed) : ?>
      <li class="hg-feed-item hg-feed-item-<?php print $feed['type'] == 'empty' ? 'empty' : $feed['nid']; ?> clearfix">

        <?php if ($feed['type'] == 'news') : ?>

          <div class="hg-feed-news-thumbnail">
            <a href="/<?php print drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) ? drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) : 'hg/item/' . $feed['nid']; ?>">
              <?php
              // if media exists (checking first item in hg_media array)
              if (in_array('Thumbnail image', $fields['feed_fields_news']) && !empty($feed['hg_media']) && $feed['hg_media'][0]['nid'] != '') {
                // if image...
                if ($feed['hg_media'][0]['type'] == 'image') {
                  print '<img src="' . $base_path . 'hg/image/' . $feed['hg_media'][0]['nid'] . '/200xX_scale" alt="' . $feed['hg_media'][0]['title'] . '">';
                } // end if image
                // if video...
                if ($feed['hg_media'][0]['type'] == 'video') {
                  // if a video thumbnail was uploaded...
                  if ($feed['hg_media'][0]['video_thumb_fid'] != '') {
                    print '<img src="' . $base_path . 'hg/file/' . $feed['hg_media'][0]['video_thumb_fid'] . '/200xX_scale" alt="' . $feed['hg_media'][0]['title'] . '">';
                    // else if it's a youtube clip, use the youtube thumbnail
                  } else {
                    if ($feed['hg_media'][0]['youtube_id'] != '') {
                      print '<img src="http://img.youtube.com/vi/' . $feed['hg_media'][0]['youtube_id'] . '/0.jpg" alt="' . $feed['hg_media'][0]['title'] . '" width="80" />';
                    }
                  } // end if video thumbnail or youtube
                } // end if video
              } // end if media exists
              ?>
            </a>
          </div>

          <h3 class="hg-feed-news-title">
            <a href="/<?php print drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) ? drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) : 'hg/item/' . $feed['nid']; ?>">
              <?php print $feed['title']; ?>
            </a>
          </h3>

          <?php if (in_array('Subtitle', $fields['feed_fields_news'])) { print '<h4 class="hg-feed-news-subtitle">' . $feed['subtitle'] . '</h4>'; } ?>
          <?php if (in_array('Dateline', $fields['feed_fields_news'])) { print '<p class="hg-feed-news-dateline">' . date('F j, Y', strtotime($feed['dateline'])) . '</p>'; } ?>
          <?php if (in_array('Summary sentence', $fields['feed_fields_news'])) { print '<p class="hg-feed-news-summary-sentence">' . $feed['sentence'] . '</p>'; } ?>
          <?php if (in_array('Summary', $fields['feed_fields_news'])) { print '<div class="hg-feed-news-summary">' . $feed['summary'] . '</div>'; } ?>

        <?php elseif ($feed['type'] == 'event') : ?>
          <div class="hg-feed-event">
            <?php
            $last_time_index = (count($feed['times']) -1);
            $start_date = $feed['times'][0]['startdate'];
            $stop_date = $feed['times'][$last_time_index]['stopdate'];
            ?>
            <?php if (date('Ym', strtotime($start_date)) == date('Ym', strtotime($stop_date))) : ?>
              <span class="hg-feed-event-month"><?php print date('M', strtotime($start_date)); ?></span>
              <?php if (date('d', strtotime($start_date)) == date('d', strtotime($stop_date))) : ?>
                <span class="hg-feed-event-day"><?php print date('j', strtotime($start_date)); ?></span>
              <?php else : ?>
                <span class="hg-feed-event-day multi-day"><?php print date('j', strtotime($start_date)); ?>-<?php print date('j', strtotime($stop_date)); ?></span>
              <?php endif; ?>
            <?php else : ?>
              <span class="hg-feed-event-multi-date">
              <?php print date('M j', strtotime($start_date)); ?> <em>to</em> <?php print date('M j', strtotime($stop_date)); ?>
            </span>
            <?php endif; ?>
          </div>
          <h3 class="hg-feed-event-title"><a href="/<?php print drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) ? drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) : 'hg/item/' . $feed['nid']; ?>"><?php print $feed['title']; ?></a></h3>
          <?php if (count(array_intersect(array('Location', 'Location phone', 'Location URL', 'Location email'), $fields['feed_fields_events'])) > 0) : ?>
            <?php print '<p class="hg-feed-event-details">'; ?>
            <?php $segments = array(); ?>
            <?php if (in_array('Location', $fields['feed_fields_events']) && $feed['event_location'] != '') { $segments[] = $feed['event_location']; } ?>
            <?php if (in_array('Location phone', $fields['feed_fields_events']) && $feed['phone'] != '') { $segments[] = $feed['phone']; } ?>
            <?php if (in_array('Location URL', $fields['feed_fields_events']) && $feed['event_url'] != '') { $segments[] = '<a href="' . $feed['event_url'] . '">' . $feed['event_url'] . '</a>'; } ?>
            <?php if (in_array('Location email', $fields['feed_fields_events']) && $feed['event_email'] != '') { $segments[] = '<a href="' . $feed['event_url'] . '">' . $feed['event_email'] . '</a>'; } ?>
            <?php print implode(' • ', $segments); ?>
            <?php print '</p>'; ?>
          <?php endif; ?>
          <?php if (in_array('Summary sentence', $fields['feed_fields_events'])) { print '<p class="hg-feed-event-summary-sentence">' . $feed['sentence'] . '</p>'; } ?>
          <?php if (in_array('Summary', $fields['feed_fields_events'])) { print '<div class="hg-feed-event-summary">' . $feed['summary'] . '</div>'; } ?>
          <?php if (count(array_intersect(array('Fee', 'Extras'), $fields['feed_fields_events'])) > 0) : ?>
            <?php print '<p class="hg-feed-event-extras">'; ?>
            <?php $segments = array(); ?>
            <?php if (in_array('Fee', $fields['feed_fields_events']) && $feed['event_fee'] != '') { $segments[] = $feed['event_fee']; } ?>
            <?php if (in_array('Extras', $fields['feed_fields_events']) && !empty($feed['event_extras'])) {
              $flat = array_map(function($el) { return $el['extra']; }, $feed['event_extras']);
              $segments[] = implode(', ', $flat);
            } ?>
            <?php print implode(' • ', $segments); ?>
            <?php print '</p>'; ?>
          <?php endif; ?>

        <?php elseif ($feed['type'] == 'hgTechInTheNews') : ?>

          <a href="<?php print $feed['article_url']; ?>">
            <?php
            // if media exists (checking first item in hg_media array)
            if (in_array('Thumbnail image', $fields['feed_fields_external_news']) && isset($feed['hg_media'][0]) && $feed['hg_media'][0]['nid'] != '') {
              // if image...
              if ($feed['hg_media'][0]['type'] == 'image') {
                print '<img src="' . $base_path . 'hg/image/' . $feed['hg_media'][0]['nid'] . '/200xX_scale" alt="' . $feed['hg_media'][0]['title'] . '">';
              } // end if image
              // if video...
              if ($feed['hg_media'][0]['type'] == 'video') {
                // if a video thumbnail was uploaded...
                if ($feed['hg_media'][0]['video_thumb_fid'] != '') {
                  print '<img src="' . $base_path . 'hg/file/' . $feed['hg_media'][0]['video_thumb_fid'] . '/200xX_scale" alt="' . $feed['hg_media'][0]['title'] . '">';
                  // else if it's a youtube clip, use the youtube thumbnail
                } else {
                  if ($feed['hg_media'][0]['youtube_id'] != '') {
                    print '<img src="http://img.youtube.com/vi/' . $feed['hg_media'][0]['youtube_id'] . '/0.jpg" alt="' . $feed['hg_media'][0]['title'] . '" width="80" />';
                  }
                } // end if video thumbnail or youtube
              } // end if video
            } // end if media exists
            ?>
          </a>

          <h3 class="hg-feed-external-title">
            <a href="<?php print $feed['article_url']; ?>"><?php print $feed['title']; ?></a>
          </h3>

          <?php if (count(array_intersect(array('Publication', 'Dateline'), $fields['feed_fields_external_news'])) > 0) : ?>
            <?php print '<p class="hg-feed-external-details">'; ?>
            <?php $segments = array(); ?>
            <?php if (in_array('Publication', $fields['feed_fields_external_news']) && $feed['publication'] != '') { $segments[] = '<em>' . $feed['publication'] . '</em>'; } ?>
            <?php if (in_array('Dateline', $fields['feed_fields_external_news']) && $feed['article_dateline'] != '') { $segments[] = format_date(strtotime($feed['article_dateline']), 'custom', 'M j, Y'); } ?>
            <?php print implode(', ', $segments); ?>
            <?php print '</p>'; ?>
          <?php endif; ?>

        <?php elseif ($feed['type'] == 'empty') : ?>
          <p class="hg-feed-empty">No items available.</p>
        <?php endif; ?>

      </li>
    <?php endforeach; ?>
  </ul>
  <div class="hg-links">
    <?php if ($offset > 0): ?>
      <span class="prev-link"><a href="?hgo=<?php print $offset - $maximum > 0 ? $offset - $maximum : 0; ?>">Prev</a></span>
    <?php endif; ?>
    <?php if ($offset < $total - 1): ?>
      <span class="next-link"><a href="?hgo=<?php print $offset + $maximum; ?>">Next</a></span>
    <?php endif; ?>
  </div>
</div>
