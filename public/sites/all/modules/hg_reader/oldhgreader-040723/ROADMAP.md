This document is not a formal roadmap so much as a bucket indicating those features that will be included in some future
release of Mercury Reader. I'm listing them by order of priority, though a) the priorities are mine, and b)any items
that can be knocked out quickly and thus convey the impression that I'm developing at breakneck speed will necessarily
jump to the front of the queue.

— Item classes indicating whether or not an item in a list has an image; css to go with it.
- Block "more" links: a couple people have been asking about these for a while, but I haven't yet implemented them
  because they require the generation of a page to go with each block (probably on the fly), with associated templating,
  etc. Making a page isn't so tough, but I'd like to do so with a minimum of additional code, since the Reader already
  makes pages. Wiring that in efficiently, however, will be challenging.
- Field settings for blocks: getting this right requires a more robust system for linking items to their parents. Right
  now the system uses the referrer element from the $_SERVER variable and looks up the parent node. This is somewhat
  slow for starters, and not possible for blocks since the parent node is not actually the entity bearing the Mercury
  data.
- Views integration: the day will come.

Feel free to suggest additional improvements or changes to the prioritization of this list — fletch@gatech.edu.
