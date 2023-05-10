(function ($) {

  Drupal.behaviors.gt_tools = {
    attach: function (context, settings) {
      fields = {
        'facebook'   : { 'link-title'  : 'Facebook',
                         'link-path'   : 'https://www.facebook.com/georgiatech',
                         'description' : 'Facebook' },
        'flickr'     : { 'link-title'  : 'Flickr',
                         'link-path'   : 'http://www.flickr.com/photos/georgiatech',
                         'description' : 'Flickr' },
        'googleplus' : { 'link-title'  : 'Google Plus',
                         'link-path'   : 'https://plus.google.com/+georgiatech/posts',
                         'description' : 'Google Plus' },
        'instagram'  : { 'link-title'  : 'Instagram',
                         'link-path'   : 'https://instagram.com/georgiatech',
                         'description' : 'Instagram' },
        'linkedin'   : { 'link-title'  : 'LinkedIn',
                         'link-path'   : 'http://www.linkedin.com/edu/school?id=18158&trk=tyah',
                         'description' : 'LinkedIn' },
        'pinterest'  : { 'link-title'  : 'Pinterest',
                         'link-path'   : 'http://pinterest.com/georgiatech/',
                         'description' : 'Pinterest' },
        'rss'        : { 'link-title'  : 'RSS',
                         'link-path'   : 'http://www.news.gatech.edu/rss',
                         'description' : 'RSS' },
        'twitter'    : { 'link-title'  : 'Twitter',
                         'link-path'   : 'https://twitter.com/georgiatech',
                         'description' : 'Twitter' },
        'youtube'    : { 'link-title'  : 'YouTube',
                         'link-path'   : 'http://www.youtube.com/georgiatech',
                         'description' : 'YouTube' },
      };
      $('#social-media-presets').change(function() {
        preset = fields[$(this).val()];
        $.each(preset, function(index, value) {
          $('#edit-' + index).val(value);
        });
      });
    }
  };

})(jQuery);
