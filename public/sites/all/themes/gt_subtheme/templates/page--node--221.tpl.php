<?php
/**
 * @file
 * GT theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
  * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $gt_logo_file: The Georgia Tech logo image file as configured in theme settings.
 * - $site_title: The site title as configured in the theme settings.
 * - $site_title_class: The CSS class associated with the site title.
 * - $map_image: The map image for the super footer of the site as configured in theme
 *   settings.
 * - $street_address: The street address below the map in the super footer as configured
 *   in theme settings
 *
 * Menus and Search:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 * - $social_media_links: Social media links menu from GT Tools module.
 * - $action_links: Action links menu from GT Tools module.
 * - $footer_links_1: Superfooter links menu 1 from GT Tools module.
 * - $footer_links_2: Superfooter links menu 2 from GT Tools module.
 * - $footer_links_3: Superfooter links menu 3 from GT Tools module.
 * - $footer_ulinks: Footer utility links menu from GT Tools module.
 * - $search_option: Site search option markup as configured in the theme settings.
 *
 * Regions:
 * - $page['left_nav'] = Left Side Menu (displays above all other content in Left Sidebar)
 * - $page['left'] = Left Sidebar
 * - $page['content_lead'] = Area ABOVE Main Content (IGNORES right region)
 * - $page['help'] = Site help content
 * - $page['main_top'] = Area ABOVE Main Content (RESPECTS right region)
 * - $page['content'] = Main Content
 * - $page['main_bottom'] = Area BELOW Main Content (RESPECTS right region)
 * - $page['right'] = Right Sidebar
 * - $page['content_close'] = Area BELOW Main Content (IGNORES right region)
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see gt_preprocess_page()
 * @see template_process()
 */
?>

<div id="page">

  <header id="masthead">

    <section id="identity">
      <div id="identity-wrapper" class="clearfix">
        <h1 id="gt-logo">
          <?php print $gt_logo_file; ?>
          <a href="http://www.gatech.edu" id="gt-logo-mothership-link" title="Georgia Institute of Technology">Georgia Institute of Technology</a>
          <?php if ($gt_logo_right_url != '') : ?>
            <a href="<?php print $gt_logo_right_url; ?>" id="gt-logo-secondary-link" title="<?php print $gt_logo_right_title; ?>"><?php print $gt_logo_right_title; ?></a>
          <?php endif; ?>
        </h1>
        <?php if ($site_title != '') : ?>
          <h2 class="<?php print $site_title_class; ?>" id="site-title" rel="home"><a href="<?php print $front_page; ?>"><?php print $site_title; ?></a></h2>
        <?php endif; ?>
      </div>
    </section><!-- /#identity -->

    <section id="primary-menus">
      <div id="primary-menus-wrapper" class="clearfix">
        <a id="primary-menus-toggle" class="hide-for-desktop"><span>Menu</span></a>
        <div id="primary-menus-off-canvas" class="off-canvas">
          <a id="primary-menus-close" class="hide-for-desktop"><span>Close</span></a>
          <nav>
            <div id="main-menu-wrapper">
              <?php if ($main_menu) : ?>
                <?php print $primary_main_menu; ?>
                <?php if ($is_admin) : print $primary_main_menu_manage; endif; ?>
              <?php endif; ?>
            </div>
            <div id="action-items-wrapper">
              <?php if ($action_items): ?>
                <?php print theme('links', array('links' => $action_items, 'attributes' => array('id' => 'action-items'))); ?>
                <?php if ($is_admin) : print $action_items_manage; endif; ?>
              <?php else : ?>
                <?php if ($is_admin) : print $action_items_add; endif; ?>
              <?php endif; ?>
            </div>
          </nav>
          <div id="utility">
            <div class="row clearfix">
              
              <!-- #utility-links -->
              <?php print $utility_links_content; ?>
              <!-- /#utility-links -->
              
              <div id="social-media-links-wrapper">
                <?php if ($social_media_links): ?>
                  <?php print theme('links', array('links' => $social_media_links, 'attributes' => array('id' => 'social-media-links'))); ?>
                  <?php if ($is_admin) : print $social_media_links_manage; endif; ?>
                <?php else : ?>
                  <?php if ($is_admin) : print $social_media_links_add; endif; ?>
                <?php endif; ?>
              </div>
            </div>
          </div><!-- /#utility -->
        </div>
        <div id="site-search">
          <?php if ($search_option_value == 0 || $search_option_value == 2) : ?>
            <a href="<?php print $base_path; ?>search" id="site-search-container-switch">Search</a>
          <?php else : ?>
            <a href="http://search.gatech.edu" id="site-search-container-switch">Search</a>
          <?php endif; ?>
          <div id="site-search-container">
            <?php print $search_option; ?>
          </div>
        </div>
      </div><!-- /#primary-menus-wrapper -->
      <div id="breadcrumb" class="hide-for-mobile">
        <div class="row clearfix">
          <ul><?php print $breadcrumb; ?></ul>
        </div>
      </div><!-- /#breadcrumb -->
    </section><!-- /#primary-menus -->

    <?php $spotlight = render($page['spotlight']); ?>

    <?php if ($spotlight) : ?>
      <section id="header-spotlight">
        <?php print $spotlight; ?>
      </section>
    <?php endif; ?>

  </header><!-- /#masthead -->

  <section id="main"<?php if ($spotlight) : print ' class="with-spotlight"'; endif; ?>>
    <div class="row clearfix">

      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <div id="page-title">
          <h2 class="title"><?php print $title; ?></h2>
        </div>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php
        // Check for content lead/close and left_nav
        $content_lead = render($page['content_lead']);
        $content_close = render($page['content_close']);
      ?>

      <?php if ($content_lead) : ?>
        <div id="content-lead">
           <?php print $content_lead; ?>
        </div>
      <?php endif; ?>

      <div class="<?php print $content_class; ?>" id="content">

        <?php
          // Check for content page help and tabs
          $page_help = render($page['help']);
          $page_tabs = render($tabs);
        ?>

        <?php if ($messages || $page_help || $page_tabs || $action_links) : ?>
          <div id="support">
            <?php print $messages; ?>
            <?php print render($page['help']); ?>
            <?php print render($tabs); ?>
            <?php if ($action_links) : ?>
              <ul class="action-links">
                <?php print render($action_links); ?>
              </ul>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <?php print render($page['main_top']); ?>

<div id="content">
<?php
$training_lookup = array(
  "55 gallons or more of oil" => array("Div SPCC"),
  "Aerial lifts" => array("Div Heights"),
  "Asbestos" => array("Div Asbestos"),
  "Biologicals" => array("Div Biosafety"),
  "Chemicals" => array("Div RTK-annual", "Div Lab Safety"),
  "Confined space" => array("Div Confined Space"),
  "Driving GT vans" => array("Div Defensive Driving", "Div Van Driving"),
  "Driving GT vehicles" => array("Div Defensive Driving"),
  "Energized Electrical Systems" => array("Div Electrical LOTO"),
  "Faculty" => array("Div RTX-1x", "Div Fire Safety"),
  "Fluorescent bulbs" => array("Div Fluorescent bulbs"),
  "Forklifts" => array("Div Forklifts"),
  "Human materials" => array("Div Bloodborne Pathogens"),
  "IBC-approved protocols" => array("Div rDNA"),
  "Landscaping" => array("Div Landscaping"),
  "Lasers: Class 3B or 4" => array("Div Laser User"),
  "Managing a 90-day hazardous waste storage area" => array("Div Haz Waste"),
  "Managing the chemical inventory" => array("Div Chematix"),
  "Other" => array("Div "),
  "Radioactive material" => array("Div Basic RAM", "Div Hands-on RAM", "Div Refresher RAM"),
  "Receiving hazardous materials" => array("Div Receiving Hazmat"),
  "Shipping hazardous materials" => array("Div Shipping Hazmat"),
  "Staff" => array("Div RTX-1x", "Div Fire Safety"),
  "Student Employee" => array("Div RTX-1x", "Div Fire Safety"),
  "Student Non-employee" => array("Div "),
  "Trenches" => array("Div Trenches"),
  "Working at heights" => array("Div Heights"),
  "Working near (but not with) a laser" => array("Div Laser Awareness"),
  "X-Ray machine" => array("Div Basic XRAY", "Div Refresher XRAY")
);

$results = array();
foreach($training_lookup as $key => $value) {
  $alt_key = str_replace(" ","_",$key);
  if( isset($_GET[$key] ) || isset($_GET[$alt_key] ) ) {
    foreach($training_lookup[$key] as $result) {
      if( ! in_array($result, $results, TRUE) ) {
      	  $results[] = $result;
      }
    }
  }
}

function check_post($name) {
  $retV = FALSE;
  if( array_key_exists($name,$_GET) ) {
    if( $_GET[$name] == "$name" ) {
      $retV = TRUE;
    }
  }
  else {
    $alt_key = str_replace(" ","_",$name);
    if( array_key_exists($alt_key,$_GET) && $_GET[$alt_key] == $name ) {
      $retV = TRUE;
    }
  }
  return $retV;
}

function checkbox($name) {
  if( check_post($name) ) {
    $checked = "checked";
  }
  else {
    $checked = "";
  }
  //Normal header sytle is "margin: 4px 0 0 200px"
  echo "<p style=\"margin: 4px 0 0 0px;\"><input type=\"checkbox\" name=\"$name\" value=\"$name\" $checked>$name</p>";
}

function result($results,$name) {
  if( in_array($name, $results, TRUE) ) {
      $style="";
  }
  else {
      $style="display: none;";
  }
  echo "<div id=\"$name\" style=\"$style\">";
}

function output() {
  if( array_key_exists("showresults",$_GET) ) {
    $style="";
  }
  else {
    $style="display: none;";
  }
  echo "<div id=\"output\" style=\"$style\">";
}

function input() {
  if( array_key_exists("showresults",$_GET) ) {
    $style="display: none;";
  }
  else {
    $style="";
  }
  echo "<div id=\"input\" style=\"$style\">";
}	  
?>

<?php input(); ?>
<p>EHS provides training ranging from laser safety to defensive driving. All faculty, staff, students, and affiliates can quickly determine their EHS training requirements by using the interactive training tool below.<br><br>Select all that apply to you, then click "Get Trainings" to see which training courses are required for you.</p>
<form name="example" method="GET" onsubmit="http://ehs.gatech.edu/node/221">

    <h3 style="margin: 4px 0 0 0px;"> My affiliation with Georgia Tech is: </h3>
    
       <?php
       checkbox("Faculty");
       checkbox("Staff");
       checkbox("Student Employee");
       checkbox("Student Non-employee");
       checkbox("Other");
       ?>
        
    <h3 style="margin: 4px 0 0 0px;"> I work with/work on/handle/operate: </h3>
    
	<?php
	checkbox("Chemicals");        
        checkbox("Biologicals");        
        checkbox("Human materials");
        checkbox("IBC-approved protocols");        
        checkbox("Radioactive material");
        checkbox("X-Ray machine");
        checkbox("Lasers: Class 3B or 4");
        checkbox("Aerial lifts");
        checkbox("Forklifts");        
        checkbox("Energized Electrical Systems");
        checkbox("Trenches");
        checkbox("Fluorescent bulbs");
        checkbox("55 gallons or more of oil");
	?>        

    <h3 style="margin: 4px 0 0 0px;"> I may come into contact with: </h3>

	<?php
	checkbox("Asbestos");
	?>

    <h3 style="margin: 4px 0 0 0px;"> My job duties include: </h3>
    
	<?php
        checkbox("Managing the chemical inventory");
        checkbox("Managing a 90-day hazardous waste storage area");
        checkbox("Shipping hazardous materials");
        checkbox("Receiving hazardous materials");
        checkbox("Working near (but not with) a laser");
        checkbox("Driving GT vehicles");
        checkbox("Driving GT vans");
        checkbox("Confined space");
        checkbox("Working at heights");
        checkbox("Landscaping");
        ?>

<!-- <hr color="#e3ca84" height="1px"> -->
<br><br>
<input type="hidden" name="showresults" value="true">
<input type="submit" value="Get Trainings" style="font-size: 200%;">
</form>
</div> <!--input-->

<?php output(); ?>

<h3 style="margin: 4px 0 0 0px;"> Here are the trainings that are required for you. </h3><br>

<?php result($results,"Div RTX-1x"); ?>
<h2> Right To Know </h2>
<p>
Required initially at start of work <br>
Course type: online<br>
Link to take course: <a href=https://ehs.gatech.edu/rtk> https://ehs.gatech.edu/rtk </a>
</p>
</div>
    
<?php result($results,"Div RTK-annual"); ?>
<h2> Right To Know </h2>
<p>
Required annually <br>
Course type: online<br>
Link to take course: <a href=https://ehs.gatech.edu/rtk> https://ehs.gatech.edu/rtk </a>
</p>
</div>
    
<?php result($results,"Div Lab Safety"); ?>
<h2> Lab Safety 101 </h2>
<p>
Required initially, then every 3 years <br>
Course type: online <br>
Link to sign up: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a>
</p>
</div>
    
<?php result($results,"Div Receiving Hazmat"); ?>
<h2> Receiving Hazardous Materials </h2>
<p> 
Required initially, then every 3 years <br>
Course type: online <br>
Link to take course: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a>
</p>
</div>
    
<?php result($results,"Div Shipping Hazmat"); ?>
<h2> Shipment of Dangerous Goods </h2>
<p>
Required every 2 years <br>
Course type: online <br>
Link to take course: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a>
</p>
</div>
   
<?php result($results,"Div Chematix"); ?>
<h2> Using Chemical Inventory System - EHSA </h2>
<p>
Recommended one-time <br>
Course type: classroom or online <br>
Link to take course: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a> <br>
</p>
</div>
    
<?php result($results,"Div Asbestos"); ?>
<h2> Asbestos Awareness </h2>
<p>
Required annually <br>
Course type: classroom <br>
To request course: contact <a href=http://ehs.gatech.edu/contact/environmental>EHS Environmental Programs</a>
</p>
</div>
   
<?php result($results,"Div Biosafety"); ?>
<h2> General Biosafety </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a>
</p>
</div>
    
<?php result($results,"Div Bloodborne Pathogens"); ?>
<h2> Bloodborne Pathogens </h2>
<p>
Required annually <br>
Course type: classroom or online <br>
Link to sign up: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a> <br>
Alternate refresher training: <a href=http://www.usg.edu/facilities/training/pathogens/> http://www.usg.edu/facilities/training/pathogens/ </a>
</p>
</div>
    
<?php result($results,"Div rDNA"); ?>
<h2> Recombinant DNA </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: <a href=https://gatech.geniussis.com/> https://gatech.geniussis.com/ </a>
</p>
</div>
    
<?php result($results,"Div Confined Space"); ?>
<h2> Confined Space Training </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
   
<?php result($results,"Div Heights"); ?>
<h2> Working at Heights </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
    
<?php result($results,"Div Electrical LOTO"); ?>
<h2> Electrical Safety and Lock Out / Tag Out </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
    
<?php result($results,"Div Landscaping"); ?>
<h2> Grounds Keeping Safety </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
    
<?php result($results,"Div Forklifts"); ?>
<h2> Powered Industrial Trucks </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
    
<?php result($results,"Div Trenches"); ?>
<h2> Excavation and Trenching </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
    
<?php result($results,"Div Defensive Driving"); ?>
<h2> Defensive Driving </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom or online <br>
Link to sign up for classroom session or online access: <a href=https://gatech.geniussis.com/>https://gatech.geniussis.com/</a>
</p>
</div>
    
<?php result($results,"Div Van Driving"); ?>
<h2> Coaching the Van Driver Course </h2>
<p>
To request course: contact <a href=http://ehs.gatech.edu/contact/general>EHS General Safety</a>
</p>
</div>
    
<?php result($results,"Div Fire Safety"); ?>
<h2> Fire Safety Training </h2>
<p>
Coming soon
</p>
</div>
    
<?php result($results,"Div Haz Waste"); ?>
<h2> Hazardous Waste 101 </h2>
<p> Required one-time <br>
Link to take course: <a href=https://gatech.geniussis.com/>https://gatech.geniussis.com/</a></p>
</div>
    
<?php result($results,"Div Fluorescent bulbs"); ?>
<h2> Fluorescent Bulbs and Ballast Management </h2>
<p>
Required one-time <br>
Course type: online <br>
Link to take course: none at this time
</p>
</div>
    
<?php result($results,"Div SPCC"); ?>
<h2> Spill Prevention Control and Countermeasures </h2>
<p>
Required annually <br>
Course type: classroom <br>
To request course: contact <a href=http://ehs.gatech.edu/contact/hazardous>EHS Hazardous Waste</a></p>
</p>
</div>
    
<?php result($results,"Div Basic RAM"); ?>
<h2> Radioactive Materials Safety Training </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.ehs.gatech.edu/radiation/ram/training> http://www.ehs.gatech.edu/radiation/ram/training </a>
</p>
</div>
    
<?php result($results,"Div Hands-on RAM"); ?>
<h2> Hands-on Radioactive Materials Safety </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.ehs.gatech.edu/radiation/ram/training> http://www.ehs.gatech.edu/radiation/ram/training </a>
</p>
</div>
    
<?php result($results,"Div Refresher RAM"); ?>
<h2> Radioactive Materials Safety Annual Refresher </h2>
<p>
Required after 3 years, annually <br>
Course type: online <br>
Link to take course: <a href=https://www.ehs.gatech.edu/radiation/ram/training> https://www.ehs.gatech.edu/radiation/ram/training </a>
</p>
</div>
    
<?php result($results,"Div Basic XRAY"); ?>
<h2> X-Ray Safety Training </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: <a href=https://www.ehs.gatech.edu/radiation/xray/training> https://www.ehs.gatech.edu/radiation/xray/training </a>
</p>
</div>
    
<?php result($results,"Div Refresher XRAY"); ?>
<h2> XRAY Refresher </h2>
<p>
Required after 2 years, every 2 years <br>
Course type: online <br>
Link to take course: <a href=https://www.ehs.gatech.edu/radiation/xray/training> https://www.ehs.gatech.edu/radiation/xray/training </a>
</p>
</div>
    
<?php result($results,"Div Laser User"); ?>
<h2> Laser Safety </h2>
<p>
Required one-time <br>
Course type: online <br>
Link to take course: <a href=https://www.ehs.gatech.edu/radiation/laser/training> https://www.ehs.gatech.edu/radiation/laser/training </a>
</p>
</div>

<?php result($results,"Div Laser User"); ?>
<h2> Laser Safety Refresher</h2>
<p>
Required after 2 years, every 2 years <br>
Course type: online <br>
Link to take course: <a href=https://www.ehs.gatech.edu/radiation/laser/training> https://www.ehs.gatech.edu/radiation/laser/training </a>
</p>
</div>

<?php result($results,"Div Laser Awareness"); ?>
<h2> Laser Awareness </h2>
<p> 
Required one-time <br>
Course type: online <br>
Link to take course: <a href=https://www.ehs.gatech.edu/radiation/laser/training> https://www.ehs.gatech.edu/radiation/laser/training </a>
</p>
</div>
    
</div> <!--output-->
</div> <!--content-->
</div> <!--meat-->

        <?php print render($page['main_bottom']); ?>
        <?php print $feed_icons; ?>
      </div><!-- /#content -->

      <?php
        // Render the sidebars to see if there's anything in them.
        $left_nav = render($page['left_nav']);
        $sidebar_left  = render($page['left']);
        $sidebar_right = render($page['right']);
      ?>

      <?php if ($left_nav || $sidebar_left): ?>
        <aside id="sidebar-left" class="<?php print $sidebar_left_class; ?>">
          <?php if ($left_nav) : ?>
            <nav id="left-nav">
               <?php print $left_nav; ?>
            </nav>
          <?php endif; ?>
          <?php print $sidebar_left; ?>
        </aside>
      <?php endif; ?>

      <?php if ($sidebar_right): ?>
        <aside id="sidebar-right" class="<?php print $sidebar_right_class; ?>">
          <?php print $sidebar_right; ?>
        </aside>
      <?php endif; ?>

      <?php if ($content_close) : ?>
        <div id="content-close">
           <?php print $content_close; ?>
        </div>
      <?php endif; ?>

    </div>
  </section><!-- /#main -->
  
  <!-- #superfooter/ -->
  <?php print $superfooter_content; ?>
  <!-- /#superfooter -->

  <!-- #superfooter/ -->
  <?php print $footer_content; ?>
  <!-- /#superfooter -->

</div><!-- /#page -->

<?php print render($page['bottom']); ?>