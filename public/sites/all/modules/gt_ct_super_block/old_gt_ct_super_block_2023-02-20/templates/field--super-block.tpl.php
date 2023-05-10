<?php
/**
 * @file field--super-block.tpl.php
 *
 * Default template implementation to display the value of a field in super block content type.
 * (reducing divitis)
 *
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>