<?php
/**
 * @file
 * Default theme implementation to display a GT Carousel Slide content node.
 *
 * Variables - Background or Overlay
 * - $gt_ct_cs_bg_image_url: URL of background image (absolute link to file)
 * - $gt_ct_cs_overlay_image_url: URL of main overlay image
 * - $gt_ct_cs_bg_color: background color
 *
 * Variables - Title Box
 * - $gt_ct_cs_slide_title: title of the slide (used for img alt text where needed)
 * - $gt_ct_cs_slide_title_summary_sentence: summary sentence included with title
 * - $gt_ct_cs_slide_title_graphic_url: URL of slide title graphic
 * - $gt_ct_cs_slide_title_graphic_alt: alt text of slide title graphic
 * - $gt_ct_cs_slide_title_placement: placement of slide title
 *
 * Variables - Jump Link
 * - $gt_ct_cs_jump_link_url: URL (absolute), used only in Title Box
 * - $gt_ct_cs_jump_link_title: Title given to Jump Link (required if URL)
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="gtct-carousel-slide__bg-image <?php print 'bg-color-' . $gt_ct_cs_bg_color; ?>"<?php
    if ($gt_ct_cs_bg_image_url) : print ' style="background-image: url(\'' . $gt_ct_cs_bg_image_url . '\');"';
    endif;
    ?>>

        <div class="content node-body clearfix gtct-carousel-slide__overlay-image title-<?php print $gt_ct_cs_slide_title_placement; ?><?php
        if (!$gt_ct_cs_slide_title_graphic_url) : print ' static-title';
        endif;
        ?>"<?php
        if ($gt_ct_cs_overlay_image_url) : print ' style="background-image: url(\'' . $gt_ct_cs_overlay_image_url . '\');"';
        endif;
        ?><?php print $content_attributes; ?>>

            <?php if (strcmp($gt_ct_cs_slide_title_placement, 'none') == 0) : ?>
              <?php if ($gt_ct_cs_bg_image_url) : ?>
                <?php if ($gt_ct_cs_jump_link_url) : ?>
                  <h3 class="element-invisible element-focusable"><a href="<?php print $gt_ct_cs_jump_link_url; ?>"><?php print $gt_ct_cs_slide_title; ?></a></h3>
                  <?php if ($gt_ct_cs_slide_title_summary_sentence) : ?>
                    <div class="element-invisible element-focusable gtct-carousel-slide__summary-text"><?php print $gt_ct_cs_slide_title_summary_sentence; ?></div>
                    <a class="element-invisible element-focusable gtct-carousel-slide__jumplink" href="<?php print $gt_ct_cs_jump_link_url; ?>"><?php print $gt_ct_cs_jump_link_title; ?></a>
                  <?php endif; ?>
                <?php else : ?>
                  <h3 class="element-invisible element-focusable"><?php print $gt_ct_cs_slide_title; ?></h3>
                  <?php if ($gt_ct_cs_slide_title_summary_sentence) : ?>
                    <div class="element-invisible element-focusable gtct-carousel-slide__summary-text"><?php print $gt_ct_cs_slide_title_summary_sentence; ?></div>
                  <?php endif; ?>
                <?php endif; ?>
              <?php endif; ?>
            <?php endif; ?>

            <?php if (strcmp($gt_ct_cs_slide_title_placement, 'none') != 0) : ?>

              <div class="gtct-carousel-slide__title-wrapper title-<?php print $gt_ct_cs_slide_title_placement; ?>">
                  <?php print render($title_prefix); ?>
                  <?php print render($title_suffix); ?>
                  <?php if ($gt_ct_cs_slide_title_graphic_url) : ?>
                    <div class="gtct-carousel-slide__title-graphic">
                        <a href="<?php print $gt_ct_cs_jump_link_url; ?>"><img alt="<?php print $gt_ct_cs_slide_title_graphic_alt; ?>" src="<?php print $gt_ct_cs_slide_title_graphic_url; ?>" /></a>
                        <?php if ($gt_ct_cs_slide_title) : ?>
                          <div class="gtct-carousel-slide__title-static hidden">
                              <h4 class="gtct-carousel-slide__title-text"><a href="<?php print $gt_ct_cs_jump_link_url; ?>"><?php print $gt_ct_cs_slide_title; ?></a></h4>
                              <?php if ($gt_ct_cs_slide_title_summary_sentence) : ?>
                                <div class="gtct-carousel-slide__summary-text"><?php print $gt_ct_cs_slide_title_summary_sentence; ?></div>
                              <?php endif; ?>
                              <a class="gtct-carousel-slide__jumplink" href="<?php print $gt_ct_cs_jump_link_url; ?>"><?php print $gt_ct_cs_jump_link_title; ?></a>
                          </div>
                        <?php endif; ?>
                    </div>
                  <?php else : ?>
                    <?php if ($gt_ct_cs_slide_title) : ?>
                      <div class="gtct-carousel-slide__title-static clearfix">
                          <h4 class="gtct-carousel-slide__title-text"><a href="<?php print $gt_ct_cs_jump_link_url; ?>"><?php print $gt_ct_cs_slide_title; ?></a></h4>
                          <?php if ($gt_ct_cs_slide_title_summary_sentence) : ?>
                            <div class="gtct-carousel-slide__summary-text"><?php print $gt_ct_cs_slide_title_summary_sentence; ?></div>
                          <?php endif; ?>
                          <a class="gtct-carousel-slide__jumplink" href="<?php print $gt_ct_cs_jump_link_url; ?>"><?php print $gt_ct_cs_jump_link_title; ?></a>
                      </div>
                    <?php endif; ?>
                  <?php endif; ?>
              </div>

          </div>

        <?php endif; ?>

    </div>

</div>