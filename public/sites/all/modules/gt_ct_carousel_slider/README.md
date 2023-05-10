GT Carousel Slider
=====================

Another carousel slider option for your GT website.

This module (generated via Features) will create two content types:

1. Carousel Side
2. Carousel

#### Carousel Slide

#####Fields:

* **Description**: Provide a description for your slide.
* **Title Settings**:
  * **Title Graphic**: By default the slide will use HTML text to display a title and teaser sentence, 
  but if you would like to upload a graphic file instead to handle those aspects, then you can do 
  that with this field. For best results upload a transparent .png file.
  * **Slide Title**: Provide a slide title. This will be used in the HTML text markup for the slide's
  title if you haven't provided a slide title graphic.
  * **Summary Sentence**: Provide a summary sentence for your slide (optional.) This will be used in 
  the HTML text markup for the slide's "teaser" if you haven't provided a slide title graphic.
  * **Title Placement**: Select a title placement option. The title and teaser will appear either over 
  the left, or right side of whatever image you upload in the Image Settings options.
  
* **Image Settings**:
  * **Background Image**: Upload a background image. This will "flood" the entire background of the 
  slide. This means that when your Carousel is placed in the "Spotlight" region the background image 
  will expand to the full width of the browser window. If your Carousel is located in a one of the regions 
  above or below the main content area the background image will only expand to the width of that region.
  * **Background Color**: Select a background color. If no background image is uploaded, and you have 
  your Carousel in the Spotlight region this color will fill the background area.
  * **Overlay Image**: This image appears in the "meat" of the slide, and does not expand out like the 
  background image does when your Carousel is placed in the Spotlight region.
  
* **Link Location**: If you want the slide to link somewhere provide the URL and a title for a link. 
If you're NOT using a title graphic then the text you enter in the Title field of the Link Location 
  option will be used as a button that will appear below the summary sentence (i.e, enter "Learn More 
  in the title field, and a Learn More button will appear below the teaser.) Note that the Slide 
  Title, and Overlay Image will also be linked.
  
#### Carousel

#####Fields:

* **Carousel Name**: Provide a name for your carousel.

* **Slides**: Add your carousel slides. This is an auto-complete field that references the title of 
  your slides. Slides will be displayed in the order they are listed with the one at the top of the 
  list being first.

##How To Use GT Carousels With The GT Theme

1. Install the module either through the Drupal interface, or by adding it to sites/all/modules 
(or sites/all/modules/custom if you have a 'custom' directory in your modules directory.)
2. Turn the module on by going to the modules configuration page for your site (/admin/modules), 
checking the "Enabled" checkbox for the GT Carousel Slider module, and saving the modules 
configuration. Note that depending on how your site is set up you may have to enable some additional 
modules required by the GT Carousel Slider module.
3. Create some carousel slides (Content -> Add Content -> Carousel Slide.) 
4. Create a carousel that references the slides you created (Content -> Add Content -> Carousel.)
5. After saving your carousel it will then be available as a block. You can find it listed on the blocks 
   overview table (Structure -> Blocks.) Click on the configure link in the row for the carousel you 
   created, and use the standard block settings to set the carousel to appear in the desired page 
   region, and on what page(s) it should appear.
6. Since the carousel you created is available as a block, you can also reference it within an Articles
   section of a Multi-purpose page, or in one of the block rows of a horizontal landing page.
   
  

