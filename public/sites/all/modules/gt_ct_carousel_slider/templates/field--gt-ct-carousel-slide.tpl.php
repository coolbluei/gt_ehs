<?php
/**
 * @file field--gt-ct-carousel-slide.tpl.php
 *
 * Default template implementation to display the value of a field in carousel slide content type.
 * (reducing divitis)
 *
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; //FOO! ?>

