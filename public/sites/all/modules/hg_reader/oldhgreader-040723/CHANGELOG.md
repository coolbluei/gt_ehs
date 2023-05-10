Mercury Reader 7.x-2.10, 2020-06-11
-----------------------------------
- It takes some people three tries to get something right.

Mercury Reader 7.x-2.9, 2020-05-27
-----------------------------------
- Followup from the last fix.

Mercury Reader 7.x-2.8, 2020-05-15
-----------------------------------
- Fixed redirection following for AWS

Mercury Reader 7.x-2.7, 2017-04-14
-----------------------------------
- Just when you thought hg_reader couldn't get any sweeter, I done went and
  added (some) support for event audiences.

Mercury Reader 7.x-2.6, 2016-03-29
-----------------------------------
- Removed some debugging code.

Mercury Reader 7.x-2.5, 2015-10-02
-----------------------------------
- Bugfix: first option in the list of selected fields was not being properly honored.

Mercury Reader 7.x-2.4, 2015-05-06
-----------------------------------
- Added a separate block feed template so that blocks don't get nuked by field settings in the main feed template.

Mercury Reader 7.x-2.3, 2015-04-23
-----------------------------------
- Added field options to Mercury form, so display of Mercury items can be controlled without so much themery.
- Moved templates into their own cozy directory, preparatory to cracking the module up into a bunch of parts.
- Broke out cache, node, and block functions into separate files.
- Massively refactored hgSerializedFeed.xsl to enhance maintainability; trimmed that mother from 3804 lines down to
  a svelte 1118.
- Fixed bug which caused the reader to fixate on its cache after items have been deleted from Mercury.
- Updated documentation.
- Rolled in the theme changes from the GT subtheme, as well as some of my own devising.

Mercury Reader 7.x-2.2, 2015-01-13
-----------------------------------
- Fixed theme_status_report notice.
- Fixed an issue in which feed sort checkbox was receiving an erroneous default value on empty forms.
- Fixed the ICS functionality, which oddly hadn't been updated since the D6 version, and anyway appeared to have been
  written by a madman.
- Broke a bunch of functions out of the monolithic module file into an include.
- Added paging to node-oriented feeds.
- Added a special easter egg. Whoever finds it gets $50.

Mercury Reader 7.x-2.1, 2013-09-11
-----------------------------------
- Added a check to prevent cache flush actions from spamming whole sites.
- Mercury error reporting now respects site error reporting level, logging errors where appropriate.

Mercury Reader 7.x-2.0, 2012-12-06
-----------------------------------
- Moved caching from Cache_lite to database.
- Changed signatures of image and file function calls.
- Documented API.
- Isn't that enough?

Mercury Reader 7.x-1.17, 2012-11-09
-----------------------------------
- Fixed error messages on empty feeds.
- Fixed combined feed sorting bug.

Mercury Reader 7.x-1.16, 2012-10-25
-----------------------------------
- Removed cron hook for pathauto aliases. Thanks Derek.
- New db schema to prevent feed overlaps between nodes and blocks.
- Expanded test cases.

Mercury Reader 7.x-1.15, 2012-10-18
-----------------------------------
- Added parent field to node forms.
- Fixed another pathauto integration bug.
- Added uninstall routine so that hg_reader properly cleans up after itself.
- Added test cases to the hg_reader module.

Mercury Reader 7.x-1.14, 2012-10-08
-----------------------------------
- Added parent field to block configuration form so that hg block items can properly be assigned a URL predicate.

Mercury Reader 7.x-1.13, 2012-10-04
-----------------------------------
- Fixed more issues with pathauto integration. For real.

Mercury Reader 7.x-1.12, 2012-10-03
-----------------------------------
- Fixed issue with pathauto integration in which updated sites ignored pathauto settings.

Mercury Reader 7.x-1.11, 2012-09-24
-----------------------------------
- Fixed showstopping template bug.

Mercury Reader 7.x-1.10, 2012-08-22
-----------------------------------
- Added support for user-defined block classes and theme suggestions.
- Item titles promoted to page titles.
— Pathauto support added.

Mercury Reader 7.x-1.9, 2012-07-25
----------------------------------
- Added support for multiple hg_feed templates (hg-feed--1.tpl.php, etc.)

Mercury Reader 7.x-1.8, 2012-06-26
----------------------------------
- Fixed template bug

Mercury Reader 7.x-1.7, 2012-06-22
----------------------------------
- Miscellaneous bug fixes

Mercury Reader 7.x-1.6, 2012-06-14
----------------------------------
- Fixed sidebar bugs

Mercury Reader 7.x-1.5, 2012-05-23
----------------------------------
- Clearing Drupal cache now clears Hg cache

Mercury Reader 7.x-1.4, 2012-05-18
----------------------------------
- Fixed caching bug
- CSS tweaks
- Corrected date formatting for news items
- Corrected location display for news items

Mercury Reader 7.x-1.3, 2012-05-10
----------------------------------
- Fixed settings bug

Mercury Reader 7.x-1.2, 2012-05-10
----------------------------------
- Fixed permissions bug
- Fixed block deletion bug

Mercury Reader 7.x-1.1, 2012-04-30
----------------------------------
- Improved requirements checking
- Support for update module
- File support improvements

Mercury Reader 7.x-1.0, 2012-04-27
----------------------------------
- Initial release of D7 hg_reader module
