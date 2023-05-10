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

        <?php if (isset($feed['type']) && $feed['type'] == 'news') : ?>

          <div class="hg-feed-news-thumbnail">
            <a href="/<?php print drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) ? drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) : 'hg/item/' . $feed['nid']; ?>">
              <?php
                // if media exists (checking first item in hg_media array)
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
              ?>
            </a>
          </div>

          <h3 class="hg-feed-news-title">
            <a href="/<?php print drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) ? drupal_lookup_path('alias', 'hg/item/' . $feed['nid']) : 'hg/item/' . $feed['nid']; ?>">
              <?php print $feed['title']; ?>
            </a>
          </h3>

          <?php print '<div class="hg-feed-news-summary">' . $feed['summary'] . '</div>'; ?>

        <?php elseif (isset($feed['type']) && $feed['type'] == 'event') : ?>
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
          <?php print '<p class="hg-feed-event-summary-sentence">' . $feed['sentence'] . '</p>'; ?>

        <?php elseif ($feed['type'] == 'hgTechInTheNews') : ?>

          <h3 class="hg-feed-external-title">
            <a href="<?php print $feed['article_url']; ?>"><?php print $feed['title']; ?></a>
          </h3>

          <?php print '<p class="hg-feed-external-details">'; ?>
          <?php print '<em>' . $feed['publication'] . '</em>, '; ?>
          <?php print format_date(strtotime($feed['article_dateline']), 'custom', 'M j, Y'); ?>
          <?php print '</p>'; ?>

        <?php elseif (isset($feed['type']) && $feed['type'] == 'empty') : ?>
          <p class="hg-feed-empty">No items available.</p>
        <?php endif; ?>

      </li>
    <?php endforeach; ?>
  </ul>
</div>
