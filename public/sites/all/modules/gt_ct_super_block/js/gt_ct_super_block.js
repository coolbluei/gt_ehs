(function($) {
  Drupal.behaviors.gt_ct_super_block = {
    attach: function (context, settings) {
      
      /*
       * Script for equalizing the heights super blocks.
       * Handy for when you have a few in a row and want them to all have the same height,
       * plus have jump links that line up.
       *
       * Simply apply the '.js_super-block-grouping-uniform-height' class to an outer wrapper element
       * that contains blocks, which contain rendered super blocks, such as the articles section of a
       * multipurpose page, which uses the block reference field.
       *
       */
      
      $.fn.superBlockEqualHeights = function() {
        tallest = 0;
        this.each(function() {
          if($(this).height() > tallest) {
            tallest = $(this).height();
          }
        });
        return this.each(function() {
          // add an additional amount to the height to allow for 2-line jump links
          $(this).height(tallest+75);
        });
      }
      
      // wait until all sub-elements are fully loaded
      $( window ).load(function() {
        // check that viewport is larger than typical tablet (or smaller) window sizes
        if ($(window).width() > '820') {
          $(".js_super-block-grouping-uniform-height .nodeblock-gt-ct-super-block .node-super-block").superBlockEqualHeights();
        }
      });
        
    }
  }
})(jQuery);