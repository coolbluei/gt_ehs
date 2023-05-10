<?php

/**
 * @file
 * Default GT Super Block module implementation to display a block.
 *
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> nodeblock-gt-ct-super-block"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <div class="content block-body clearfix"<?php print $content_attributes; ?>>
    <?php print $content ?>
  </div>
    
</div>
