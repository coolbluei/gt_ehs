<?php
/**
 * @file field--gt-ct-carousel.tpl.php
 *
 * Default template implementation to display the value of a field in carousel content type.
 * (reducing divitis)
 *
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>