<?php
// hg_media.tpl.php
//dpm($items);
?>

<div class="hg-sidebar">
  <h4 class="hg-sidebar-header">Related Media</h4>
  <p class="hg-sidebar-media-instructions">Click on image(s) to view larger version(s)</p>
  <div class="hg-sidebar-content">
    <ul class="itemList hg-sidebar-media-list">
      <?php foreach ($items as $item): ?>

        <?php if ($item['type'] == 'image'): ?>
          <li class="clear-block clearfix">
            <a href="<?php print base_path(); ?>hg/image/<?php print $item['nodeid']; ?>/740xX_scale" title="<?php print $item['title']; ?>">
              <img src="<?php print base_path(); ?>hg/image/<?php print $item['nodeid']; ?>/400xX_scale" alt="" />
            </a>
            <p>
              <?php print $item['title']; ?>
            </p>
          </li>
        <?php endif; ?>

        <?php if ($item['type'] == 'video'): ?>
          <li class="clear-block clearfix">
            <?php if ($item['video'] != '' || $item['flash'] != '') : ?>
              <?php if ($item['video'] != '') { $fid = $item['video_fid']; $file = $item['video']; } else { $fid = $item['flash_fid']; $file = $item['flash']; }?>
              <?php
                // to prevent corrupt content errors, and support inline playback, video/swf files are served` directly from Mercury
              ?>
              <a href="http://hg.gatech.edu/hgfile/<?php print $fid; ?>?fname=<?php print $file; ?>">
                <?php if ($item['videothumb_fid'] != '') : ?>
                  <img src="<?php print base_path(); ?>hg/file/<?php print $item['videothumb_fid']; ?>/400xX_scale" alt="<?php print $item['title']; ?>" />
                <?php else : ?>
                  <?php print $item['title']; ?>
                <?php endif; ?>
              </a>
            <?php endif; ?>
            <?php if ($item['youtube'] != '') : ?>
              <?php if ($item['videothumb_fid'] != '') : ?>
                <a href="http://www.youtube.com/watch?v=<?php print $item['youtube']; ?>">
                  <img src="<?php print base_path(); ?>hg/file/<?php print $item['videothumb_fid']; ?>/400xX_scale" alt="<?php print $item['title']; ?>" />
                </a>
              <?php else : ?>
                <a href="http://www.youtube.com/watch?v=<?php print $item['youtube']; ?>">
                  <img src="http://img.youtube.com/vi/<?php print $item['youtube']; ?>/0.jpg" alt="<?php print $item['title']; ?>" width="80" />
                </a>
              <?php endif; ?>
            <?php endif; ?>
            <p>
              <?php print $item['title']; ?>
            </p>
          </li>
        <?php endif; ?>

      <?php endforeach; ?>
    </ul>
  </div>
</div>

