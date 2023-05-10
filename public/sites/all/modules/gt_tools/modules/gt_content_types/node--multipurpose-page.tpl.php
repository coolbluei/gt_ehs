<?php
/**
 * @file
 * Default theme implementation to display a Multipurpose Page content type.
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
    
    <?php if ($body_1 || $aside_1 || $articles_1) : ?>
      <div class="content-row row-top clearfix">
        <?php if ($body_1) : ?>
          <div class="body<?php if ($aside_1) : print ' with-aside'; endif; ?>">
            <?php print render($content['field_body_1']); ?>
          </div>
        <?php endif; ?>
        <?php if ($aside_1) : ?>
          <aside class="sidebar block-count-<?php print $aside_1; ?>">
            <?php print render($content['field_aside_1']) ?>
          </aside>
        <?php endif; ?>
        <?php if ($articles_1) : ?>
          <div class="articles block-count-<?php print $articles_1; ?> clearfix">
            <?php print render($content['field_articles_1']); ?>
          </div>
        <?php endif; ?>  
      </div>
    <?php endif; ?>
    
    <?php if ($body_2 || $aside_2 || $articles_2) : ?>
      <div class="content-row row-middle clearfix">
        <?php if ($body_2) : ?>
          <div class="body<?php if ($aside_2) : print ' with-aside'; endif; ?>">
            <?php print render($content['field_body_2']); ?>
          </div>
        <?php endif; ?>
        <?php if ($aside_2) : ?>
          <aside class="sidebar block-count-<?php print $aside_2; ?>">
            <?php print render($content['field_aside_2']) ?>
          </aside>
        <?php endif; ?>
        <?php if ($articles_2) : ?>
          <div class="articles block-count-<?php print $articles_2; ?> clearfix">
            <?php print render($content['field_articles_2']); ?>
          </div>
        <?php endif; ?>  
      </div>
    <?php endif; ?>
    
    <?php if ($body_3 || $aside_3 || $articles_3) : ?>
      <div class="content-row row-bottom clearfix">
        <?php if ($body_3) : ?>
          <div class="body<?php if ($aside_3) : print ' with-aside'; endif; ?>">
            <?php print render($content['field_body_3']); ?>
          </div>
        <?php endif; ?>
        <?php if ($aside_3) : ?>
          <aside class="sidebar block-count-<?php print $aside_3; ?>">
            <?php print render($content['field_aside_3']) ?>
          </aside>
        <?php endif; ?>
        <?php if ($articles_3) : ?>
          <div class="articles block-count-<?php print $articles_3; ?> clearfix">
            <?php print render($content['field_articles_3']); ?>
          </div>
        <?php endif; ?>  
      </div>
    <?php endif; ?>
    
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>