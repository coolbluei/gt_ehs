Super Block
==========

A Drupal module (generated via Features) that creates a dynamic callout/highlight content type intended to be displayed on pages via block reference fields.

To use this module, install it like you would any typical third-party Drupal module, either through the modules interface (provided you have update manager turned on, and the correct access privileges,) or un-tarring it, SFTPing into your site and placing it in /sites/all/modules/.

*Note that if you're downloading a zip file of this repo from github you might need to remove the branch name before uploading it to your site (i.e., upload a directory named "gt_ct_super_block," not "gt_ct_super_block-master".)*

Once installed it will create a new content type called "Super Block."

##Super Block Options
- **Description:** (required) Use this field to provide a description of the super block. Be sure to be as concise as possible. This serves as the value that's used for the auto complete block reference field in GT Tools content types (like a multipurpose page.) For example, enter something like "Bachelor's Programs callout for the home page" instead of "Bachelor's callout."
- **Title:** (optional) The title will show up above the image provided with the super block. You can use &lt;em&gt;, &lt;strong&gt;, and &lt;br /&gt;, tags in the title if needed. Just don't forget to close &lt;em&gt; and &lt;strong&gt; tags! (i.e., &lt;strong&gt;Strong Title&lt;/strong&gt;)
- **Primary Image:** (optional, but highly recommended -- this is the heart of super blocks!) Upload an image to be displayed with the super block. An optimal size for the image is 492px X 320px.
- **Image Placement:** (required, defaults to 'left') Select a positioning for the image. If a super block appears alone in a region the image will be floated left or right around summary text (depending on what option you choose.) If super blocks are in a region with other blocks the image will take up the full width of the super block's outer wrapper, and the teaser text (if provided) will appear below (ignoring the value in the image placement drop-down.) 
- **Teaser Text:** (optional) This will display to the left/right of the primary image, or below it if the super block is stacked with other blocks within a region.
- **Jump Link:** (optional) Provide a link, if necessary. The link title will appear as a standard "Highlight Button." Depending on what options are selected in the Jump Link Location option the link will appear either below the teaser text/image, or as an overlay on top of the image. The title and image will also be linked.
- **Jump Link Location:** (required, defaults to below teaser) Select the location of the jump link
- **Skin:** (required, defaults to Standard) Standard skin uses a gray title and jump link with white text and a gold icon; GT Blue uses a blue title and jump link with white text and gold icon; GT Gold uses a blue title, but the jump link is gold with white text, and a blue icon.  
