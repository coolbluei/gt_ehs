<?php
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
<?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>


  if( count($_POST) ) {
    $style="display: none;";
  }
  else {
    $style="";
  }
  echo "<div id=\"input\" style=\"$style\">";
}	  
?>

<?php input(); ?>
<form name="example" method="POST" onsubmit="training.php">

    <h1 style="margin: 4px 0 0 0px;"> My affiliation with Georgia Tech is: </h1>
    
       <?php
       checkbox("Faculty");
       checkbox("Staff");
       checkbox("Student Employee");
       checkbox("Student Non-employee");
       checkbox("Other");
       ?>
        
    <h1 style="margin: 4px 0 0 0px;"> If working in a lab, my role is: </h1>
    	<?php
        checkbox("PI");
        checkbox("Lab manager");
	checkbox("Neither");
	?>
        
    <h1 style="margin: 4px 0 0 0px;"> I work with/work on/handle/operate: </h1>
    
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

    <h1 style="margin: 4px 0 0 0px;"> I may come into contact with: </h1>

	<?php
	checkbox("Asbestos");
	?>

    <h1 style="margin: 4px 0 0 0px;"> My job duties include: </h1>
    
	<?php
        checkbox("Managing the Chematix inventory");
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
<br><br><input type="submit" value="Get Trainings" style="font-size: 200%;">
</form>
</div> <!--input-->

<?php output(); ?>

<h1 style="margin: 4px 0 0 0px;"> Here are the trainings that are required for you. </h1>

<?php result("Div RTX-1x"); ?>
<h2> Right To Know </h2>
<p>
Required initially at start of work <br>
Course type: online or classroom <br>
Link to take course: <a href=http://www.usg.edu/ehs/training/rtkbasic/> http://www.usg.edu/ehs/training/rtkbasic/ </a> <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11254> http://www.trains.gatech.edu/courses/index#view-11254 </a>
</p>
</div>
    
<?php result("Div RTK-annual"); ?>
<h2> Right To Know </h2>
<p>
Required annually <br>
Course type: online or classroom <br>
Link to take course: <a href=http://www.usg.edu/ehs/training/rtkbasic/> http://www.usg.edu/ehs/training/rtkbasic/ </a> <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11254> http://www.trains.gatech.edu/courses/index#view-11254 </a>
</p>
</div>
    
<?php result("Div Basic Lab Safety"); ?>
<h2> Basic Lab Safety </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11238> http://www.trains.gatech.edu/courses/index#view-11238 </a>
</p>
</div>
    
<?php result("Div Adv Lab Safety"); ?>
<h2> Advanced Lab Safety for PIs and Lab Managers </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11231> http://www.trains.gatech.edu/courses/index#view-11231 </a>
</p>
</div>
    
<?php result("Div Receiving Hazmat"); ?>
<h2> Receiving Hazardous Materials </h2>
<p> 
Required initially, then every 3 years <br>
Course type: online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-7657> http://www.trains.gatech.edu/courses/index#view-7657 </a>
</p>
</div>
    
<?php result("Div Shipping Hazmat"); ?>
<h2> Shipment of Dangerous Goods </h2>
<p>
Required one-time <br>
Course type: online and hands-on (both required) <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-7762> http://www.trains.gatech.edu/courses/index#view-7762 </a>
</p>
</div>
   
<?php result("Div Chematix"); ?>
<h2> Using Chematix </h2>
<p>
Required one-time <br>
Course type: classroom or online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-4092> http://www.trains.gatech.edu/courses/index#view-4092 </a> <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11250> http://www.trains.gatech.edu/courses/index#view-11250 </a>
</p>
</div>
    
<?php result("Div Asbestos"); ?>
<h2> Asbestos Hazard Awareness </h2>
<p>
Required annually <br>
Course type: classroom <br>
Link to sign up: scheduled annually by Chemical Safety, will be on trainsweb Dec-Jan
</p>
</div>
   
<?php result("Div Biosafety"); ?>
<h2> General Biosafety </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11134> http://www.trains.gatech.edu/courses/index#view-11134 </a>
</p>
</div>
    
<?php result("Div Bloodborne Pathogens"); ?>
<h2> Bloodborne Pathogens </h2>
<p>
Required annually <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11145> http://www.trains.gatech.edu/courses/index#view-11145 </a> <br>
Alternate refresher training: <a href=http://www.usg.edu/ehs/training/pathogens/> http://www.usg.edu/ehs/training/pathogens/ </a>
</p>
</div>
    
<?php result("Div rDNA"); ?>
<h2> Recombinant DNA </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11157> http://www.trains.gatech.edu/courses/index#view-11157 </a>
</p>
</div>
    
<?php result("Div Confined Space"); ?>
<h2> Confined Space Training </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
   
<?php result("Div Heights"); ?>
<h2> Working at Heights </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
    
<?php result("Div Electrical LOTO"); ?>
<h2> Electrical Safety and Lock Out / Tag Out </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
    
<?php result("Div Landscaping"); ?>
<h2> Grounds Keeping Safety </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
    
<?php result("Div Forklifts"); ?>
<h2> Powered Industrial Trucks </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
    
<?php result("Div Trenches"); ?>
<h2> Excavation and Trenching </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
    
<?php result("Div Defensive Driving"); ?>
<h2> Defensive Driving (DDC-6) </h2>
<p>
Required initially, then every 3 years <br>
Course type: classroom or online <br>
Link to take course: NO LINK FOUND <br>
Link to sign up: <a href=http://www.trains.gatech.edu/courses/index#view-11191> http://www.trains.gatech.edu/courses/index#view-11191 </a>
</p>
</div>
    
<?php result("Div Van Driving"); ?>
<h2> Coaching the Van Driver Course </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: NO LINK FOUND
</p>
</div>
    
<?php result("Div Fire Safety"); ?>
<h2> Fire Safety Training </h2>
<p>
Required one-time <br>
Course type: online <br>
Link to take course: <a href=www.ehs.gatech.edu/fire/fire_training/Fire_Intro.html> www.ehs.gatech.edu/fire/fire_training/Fire_Intro.html </a>
</p>
</div>
    
<?php result("Div Adv Haz Waste"); ?>
<h2> Advanced Hazardous Waste </h2>
<p> Required one-time </p>
</div>
    
<?php result("Div Fluorescent bulbs"); ?>
<h2> Fluorescent Bulbs and Ballast Management </h2>
<p>
Required one-time <br>
Course type: online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-6885> http://www.trains.gatech.edu/courses/index#view-6885 </a>
</p>
</div>
    
<?php result("Div SPCC"); ?>
<h2> Spill Prevention Control and Countermeasures </h2>
<p>
Required annually <br>
Course type: classroom <br>
Link to sign up: call 404-894-6224
</p>
</div>
    
<?php result("Div Basic RAM"); ?>
<h2> Radioactive Materials Safety Training </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.ors.gatech.edu/ram/training.php> http://www.ors.gatech.edu/ram/training.php </a>
</p>
</div>
    
<?php result("Div Hands-on RAM"); ?>
<h2> Hands-on Radioactive Materials Safety </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: no sign up required, attend Radioactive Materials Safety Training 1-2 days prior
</p>
</div>
    
<?php result("Div Refresher RAM"); ?>
<h2> Radioactive Materials Safety Annual Refresher </h2>
<p>
Required after 3 years, annually <br>
Course type: online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-7259> http://www.trains.gatech.edu/courses/index#view-7259 </a>
</p>
</div>
    
<?php result("Div Basic XRAY"); ?>
<h2> X-Ray Safety Training </h2>
<p>
Required one-time <br>
Course type: classroom <br>
Link to sign up: <a href=http://www.ors.gatech.edu/xray/training.php> http://www.ors.gatech.edu/xray/training.php </a>
</p>
</div>
    
<?php result("Div Refresher XRAY"); ?>
<h2> XRAY Refresher </h2>
<p>
Required after 2 years, every 2 years <br>
Course type: online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-7720> http://www.trains.gatech.edu/courses/index#view-7720 </a>
</p>
</div>
    
<?php result("Div Laser User"); ?>
<h2> Laser Safety </h2>
<p>
Required one-time <br>
Course type: online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-7801> http://www.trains.gatech.edu/courses/index#view-7801 </a>
</p>
</div>
    
<?php result("Div Laser Awareness"); ?>
<h2> Laser Awareness </h2>
<p> 
Required one-time <br>
Course type: online <br>
Link to take course: <a href=http://www.trains.gatech.edu/courses/index#view-8219> http://www.trains.gatech.edu/courses/index#view-8219 </a>
</p>
</div>
    
</div> <!--output-->
</div> <!--content-->
</div> <!--meat-->
  </div>
</div>