<?php
/**
 * @file
 * Default theme implementation to display a super block node.
 *
 * Node variables:
 * - $image_placement: Value of the image placement selection used as a CSS class, "sb-image-left", or " sb-image-right".
 * - $sb_jump_link_url: Value of the jump link URL.
 * - $sb_jump_link_title: Value of the jump link title.
 * - $sb_jump_link_location_array: An array containing the values of the jump link location, "bottom", "image", or both
 * - $sb_skin: Value of the skin selection used as a CSS class, "sb-skin-standard", "sb-skin-blue", "sb-skin-gold"
 *
 */
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix <?php print $sb_skin; ?> <?php print $sb_content_placement; ?>"<?php print $attributes; ?>>

    <?php print render($title_prefix); ?>
    <?php if ($sb_title) : ?>
      <h4 class="super-block__title">
          <?php if ($sb_jump_link_url) : ?>
            <?php print l(t($sb_title), $sb_jump_link_url, array('html' => TRUE, 'attributes' => array('class' => array('super-block__title-link')))); ?>
          <?php else : ?>
            <?php print $sb_title; ?>
          <?php endif; ?>
      </h4>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="content node-body clearfix "<?php print $content_attributes; ?>>

        <?php if ($sb_image) : ?>
          <div class="super-block__image">
              <div class="super-block__image-wrapper">
                  <?php if ($sb_jump_link) : ?>
                    <?php print l($sb_image, $sb_jump_link_url, array('html' => TRUE)); ?>
                  <?php else : ?>
                    <?php print $sb_image; ?>
                  <?php endif; ?>
                  <?php if (in_array('image', $sb_jump_link_location_array) && $sb_jump_link) : ?>
                    <div class="super-block__jump-link clearfix">
                        <?php print l(t($sb_jump_link_title), $sb_jump_link_url); ?>
                    </div>
                  <?php endif; ?>
              </div>
          </div>
        <?php endif; ?>

        <div class="super-block__lower">
            <?php if ($sb_teaser) : ?>
              <div class="super-block__teaser">
                  <?php print $sb_teaser; ?>
              </div>
            <?php endif; ?>
            <?php if (in_array('bottom', $sb_jump_link_location_array) && $sb_jump_link) : ?>
              <div class="super-block__jump-link clearfix">
                  <?php print l(t($sb_jump_link_title), $sb_jump_link_url); ?>
              </div>
            <?php endif; ?>
        </div>

    </div>

</div>