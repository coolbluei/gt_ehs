<?php
/**
 * @file
 * Default theme implementation to display a Horizontal Landing Page content type.
 *
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    
    <?php if ($body_1) : ?>
      <div class="body-row">
        <div class="row-content clearfix">
          <?php  print render($content['field_body_1']); ?>
        </div>
      </div>
    <?php endif; ?>
    
    <?php if ($block_row_1) : ?>
      <div class="block-row block-row-odd block-count-<?php print $block_row_1; ?>">
        <div class="row-content clearfix">
          <?php print render($content['field_block_row_1']); ?>
        </div>
      </div>
    <?php endif; ?>
    
    <?php if ($block_row_2) : ?>
      <div class="block-row block-row-even block-count-<?php print $block_row_2; ?> clearfix">
        <div class="row-content clearfix">
          <?php print render($content['field_block_row_2']); ?>
        </div>
      </div>
    <?php endif; ?>
    
    <?php if ($block_row_3) : ?>
      <div class="block-row block-row-odd block-count-<?php print $block_row_3; ?> clearfix">
        <div class="row-content clearfix">
          <?php print render($content['field_block_row_3']); ?>
        </div>
      </div>
    <?php endif; ?>
    
    <?php if ($block_row_4) : ?>
      <div class="block-row block-row-even block-count-<?php print $block_row_4; ?> clearfix">
          <div class="row-content clearfix">
            <?php print render($content['field_block_row_4']); ?>
          </div>
      </div>
    <?php endif; ?>
    
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>
    
</div>