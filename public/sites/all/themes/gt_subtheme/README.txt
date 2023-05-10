BUILD A THEME WITH Georgia Tech's 7.x-2.x Theme for Drupal 7
------------------------------------------------------------------

The base GT Theme (7.x-2.x) is designed to be easily extended by its sub-themes. You
shouldn't modify any of the CSS or PHP files in the gt/ folder; instead,
you should create a sub-theme of both which is located in a folder 
outside of the root gt/ folder. The examples below assume your themes
will installed in sites/all/themes/, which will then look like this:
 gt/
 gt_subtheme/


*** IMPORTANT NOTE ***
*
* In Drupal 7, the theme system caches which template files and which theme
* functions should be called. This means that if you add a new theme,
* preprocess or process function to your template.php file or add a new template
* (.tpl.php) file to your sub-theme, you will need to rebuild the "theme
* registry." See http://drupal.org/node/173880#theme-registry
*
* Drupal 7 also stores a cache of the data in .info files. If you modify any
* lines in your sub-theme's .info file, you MUST refresh Drupal 7's cache by
* simply visiting the Appearance page at admin/appearance.
*


 1. Setup the location for your new sub-theme.

    Copy the gt_subtheme folder out of the gt/ folder and rename it to be your
    new sub-theme. IMPORTANT: The name of your sub-theme must start with an
    alphabetic character and can only contain lowercase letters, numbers and
    underscores.

    For example, copy the sites/all/themes/gt/gt_subtheme folder and rename it
    as sites/all/themes/gt_mydepartment.

      Why? Each theme should reside in its own folder. To make it easier to
      upgrade the GT Theme, sub-themes should reside in a folder separate 
      from the base theme.

 2. Setup the basic information for your sub-theme.

    In your new sub-theme folder, rename the gt_subtheme.info.txt file to include
    the name of your new sub-theme and remove the ".txt" extension. Then edit
    the .info file by editing the name and description field.

    For example, rename the gt_mydepartment/gt_subtheme.info.txt file to 
    gt_mydepartment/gt_mydepartment.info. Edit the gt_mydepartment.info file 
    and change "name = GT Sub-theme Starter Kit" to "name = GT My Department".

      Why? The .info file describes the basic things about your theme: its
      name, description, features, template regions, CSS files, and JavaScript
      files. See the Drupal 7 Theme Guide for more info:
      http://drupal.org/node/171205

    Then, visit your site's Appearance page at admin/appearance to refresh
    Drupal 7's cache of .info file data.

 3. Edit your sub-theme to use the proper function names.

    Edit the template.php and theme-settings.php files in your sub-theme's
    folder; replace ALL occurrences of "gt_subtheme" with the name of your
    sub-theme.

    For example, edit gt_mydepartment/template.php and 
    gt_mydepartment/theme-settings.php and replace every occurrence 
    of "gt_subtheme" with "gt_mydepartment".

    It is recommended to use a text editing application with search and
    "replace all" functionality.

 4. Set your website's default theme.

    Log in as an administrator on your Drupal site, go to the Appearance page at
    admin/appearance and click the "Enable and set default" link next to your
    new sub-theme.  You can disable the GT theme, as it doesn't need to be 
    enabled for this subtheme to use them.


Optional steps:

 5. Modify the markup in GT's template files.

    If you decide you want to modify any of the .tpl.php template files in the
    gt folder, copy them to your sub-theme's folder before 
    making any changes. And then rebuild the theme registry.

    For example, copy gt/templates/page.tpl.php to 
    gt_mydepartment/templates/page.tpl.php.

    You can find a full list of Drupal templates that you can override in the
    templates/README.txt file or http://drupal.org/node/190815

      Why? In Drupal 7 theming, if you want to modify a template included by a
      module, you should copy the template file from the module's directory to
      your sub-theme's template directory and then rebuild the theme registry.
      See the Drupal 7 Theme Guide for more info: http://drupal.org/node/173880

 6. Further extend your sub-theme.

    Discover further ways to extend your sub-theme by reading Zen's
    sample documentation online at:
      http://drupal.org/documentation/theme/zen
    and Drupal 7's Theme Guide online at:
      http://drupal.org/theme-guide

 7. Contribute your changes back to the GT community.

    If you make some beautiful code, consider sharing it with other 
    grateful Drupalistas around campus, by logging in and adding it as 
    a comment at:
      http://drupal.gatech.edu/handbook/appearance-gt-drupal-7-theme-repository
