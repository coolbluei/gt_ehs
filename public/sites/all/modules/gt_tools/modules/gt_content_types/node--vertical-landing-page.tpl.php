<?php
/**
 * @file
 * Default theme implementation to display a Vertical Landing Page content type.
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

  <div class="content clearfix"<?php print $content_attributes; ?>>
    
    <?php if ($body_1) : ?>
      <div class="body-row">
        <div class="row-content clearfix">
          <?php  print render($content['field_body_1']); ?>
        </div>
      </div>
    <?php endif; ?>
    <?php if ($column_left) : ?>
      <div class="column-left block-count-<?php print $column_left; ?>">
        <?php print render($content['field_column_left']); ?>
      </div>
    <?php endif; ?>
    <?php if ($column_right) : ?>
      <div class="column-right block-count-<?php print $column_right; ?>">
        <?php print render($content['field_column_right']); ?>
      </div>
    <?php endif; ?>
     
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>
  
</div>