<?php
/**
 * @file
 * Default theme implementation to display a GT Carousel node.
 *
 * This is styled to use the "default" settings of Flexslider, which shows the previous/next arrows,
 * and small indicator dots.
 *
 * * Available variables:
 * - $gt_ct_cs_slide_array: an array of full rendered slide nodes 
 *
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <div class="content node-body clearfix"<?php print $content_attributes; ?>>
    
    <div class="gtct-carousel__slides-wrapper">
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
      <div id="carousel-<?php print $node->nid; ?>" >    
        <ul class="slides">
        <?php foreach ($gt_ct_cs_slide_array AS $slide) : ?>
          <li class="slide"><?php print render($slide); ?></li>
        <?php endforeach; ?>
        </ul>
      </div>
      
      <?php flexslider_add('carousel-' . $node->nid, 'default'); ?>
      
    </div>

  </div>
  
</div>