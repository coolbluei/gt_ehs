(function ($) {

  Drupal.behaviors.hgReader = {};

  Drupal.behaviors.hgReader.attach = function (context, settings) {
    $('#item-fields-buttons').mouseenter(function(){
      // Show buttons and darken scrim.
      $('#item-fields-buttons button').fadeToggle();
      $('#scrim').fadeTo(400, .9);
    });
    $('#item-fields-buttons').mouseleave(function(){
      // Hide buttons and lighten scrim.
      $('#item-fields-buttons button').fadeToggle();
      $('#scrim').fadeTo(400, .5);
    });
    $('#item-fields-edit-all').click(function() {
      // Send user to defaults page.
      event.preventDefault();
      window.location.href = '/admin/config/hg/hg-reader#item-fields';
    })
    $('#item-fields-override').click(function() {
      // Override defaults; remove scrim and buttons.
      event.preventDefault();
      $('#item-fields-buttons').remove();
      $('#scrim').remove();
      $('input[name=override]').val('TRUE');
    })
  }

})(jQuery);