INSTALLATION

Decompress the module and place the resulting directory into
/sites/all/modules, as you would any other module. Go to
admin/build/modules in your site, enable the Mercury Reader module, and
save changes.


MERCURY

In order to use Mercury Reader, you will, at a minimum, need the ID
number of the Mercury feed you wish to display. Within Mercury, the feed
ID is the five- or six-digit number shown in the URL when viewing a
feed. For example, the Georgia Tech homepage feed is available at
http://hg.gatech.edu/node/42142, and the feed ID is 42142.

You are not required to have a Mercury account to include feeds on your
site. If you do not have an account and wish to display an existing
feed, contact the administrator of that feed to get the ID number.


CONFIGURATION

Mercury Reader allows you to create feed pages and feed blocks.

To enable Mercury for a given content type, edit the content type and check the box labeled, "Allow Mercury feeds to be
displayed on pages of this type." If the box is not visible, you may need to click the Mercury settings fieldset first.

Next create a page of the type you just edited. Edit the page as you would ordinarily, then click the Mercury tab to
manage the feed. The fields to be supplied are as follows:

- "Feed ID" : Enter the Mercury ID (see "Mercury" above).

- "Maximum Items" : Enter the maximum number of items you wish to display, or 0 for unlimited.

- "Feed Classes" : Terms entered here will appear as classes within the generated HTML for use in CSS. They are also
  used to generate theme template suggestions (see "Theming" below).

- "Parent URL" : Provides a URL fragment to be used as a parent when generating path aliases with Pathauto.

- "Use a pager" : For feeds attached to nodes, this will chunk the feed into pages the length of "Maximum Items."

- "Reverse sort" : It is often necessary to flip the sorting of items — events are typically sorted in ascending order
  while news is typically sorted in descending order. Check this to reverse the sorting of the feed.

When you save the feed, return to the View tab and you should see the feed items listed below the body copy, if there is
any. Each title will link to the full item at /hg/item/item-ID. The full item pages can be themed (see below), as can
feed lists.

To create a feed block, go to admin/build/block and choose Add Mercury block. The form items are the same as above
(though there are no paging options for blocks as yet).


THEMING

There are three templates included in Mercury Reader -- hg_feed.tpl.php, which controls the appearance of a feed;
hg_item.tpl.php, which controls the appearance of full item displays; and hg_media.tpl.php, which controls the
appearance of the related media box shown on item pages. To override these, make a duplicate of the desired template in
your local theme directory, and modify as you see fit.

You may also create templates for specific feeds by specifying a feed class on the node or block edit form. Classes
supplied in this manner will generate theme template suggestions in the form hg_feed__class.tpl.php.


TROUBLESHOOTING

There are no known issues as of this writing, but if you have problems with Mercury Reader, contact webteam@gatech.edu.
