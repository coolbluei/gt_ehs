<?php
/**
 * @file
 * GT theme's implementation to display a single Drupal page.
 *
 * See README for variables explanation.
 *
 */
?>

<!--  Header -->
<header id="gt-header" role="banner">
    <a href="#main-navigation" id="page-navigation" class="sr-only">Skip To
        Keyboard Navigation</a>

    <div class="bg-gold-md-gold position-relative" id="brandhead">
        <!--  Hamburger -->
        <div id="mobile-menu-wrapper" class="d-block d-md-none mr-3 container">
            <button class="d-block ml-auto navbar-toggler collapsed"
                    type="button" data-toggle="collapse"
                    data-target="#Navbar" aria-controls="navbarResponsive"
                    aria-expanded="false"
                    aria-label="Toggle navigation">
                <span class="icon-bar top-bar"></span>
                <span class="icon-bar middle-bar"></span>
                <span class="icon-bar bottom-bar mb-1"></span>
                <span class="icon-text"></span>
                <span class="sr-only">Toggle navigation</span>
            </button>
        </div>

        <!--  Top Header -->
        <div class="container">
            <div class="row">
                <div class="col-5 col-sm-5 col-md-4 col-lg-3 bg-tech-md-gold"
                     id="logo-wrapper">
                    <div id="gt-logo">
                        <a class="d-flex align-items-center"
                           href="https://gatech.edu"
                           title="Georgia Institute of Technology">
                            <img id="gt-logo-image"
                                 src="/sites/all/themes/gt/images/gt-logo-oneline-white.svg"
                                 alt="Georgia Institute of Technology">
                        </a>
                    </div><!--end gt-logo-->
                </div>

                <div class="col bg-gold-grad">
                </div>
            </div><!--end row -->
        </div><!--end container-->
    </div><!--end gold bg -->

    <div class="container">
        <div class="row">
            <div class="col" id="site-name-slogan-wrapper">

                <!-- GT Site Name/Site Title -->
                <?php if ($site_title != '') : ?>
                    <div id="site-title" class="h2 site-title-single"
                         rel="home">
                        <a href="<?php print $front_page; ?>"><?php print $site_title; ?></a>
                    </div>
                <?php endif; ?>
            </div><!--END col-->
        </div><!--end row -->
    </div><!--end container-->

    <!--  Bottom Header  -->
    <div class="container">
        <div class="navbar-expand-md">
            <div id="bottom-header" class="py-1">
                <nav id="Navbar" class="collapse navbar navbar-collapse">
                    <div class="d-md-flex w-100">

                        <!--  Page Navigation -->
                        <?php if (!empty($primary_main_menu)): ?>
                            <a id="main-navigation"></a>
                            <div id="page-navigation" class="main-nav flex-shrink-1" role="navigation" aria-label="Primary"
                                 aria-labelledby="main-navigation">
                                <?php if ($main_menu) : ?>
                                    <nav role="navigation">
                                        <?php print $primary_main_menu; ?>
                                        <?php
                                        if ($is_admin) : print $primary_main_menu_manage;
                                        endif;
                                        ?>
                                    </nav>
                                <?php endif; ?>
                            </div>
                        <?php endif; ?>

                        <!--  Utility Navigation -->
                        <?php if (!empty($action_items)): ?>
                            <div id="utility-search-wrapper" class="ml-auto d-sm-block d-md-flex justify-content-end flex-grow-1"
                                 role="navigation" aria-label="Secondary">
                                <?php if ($action_items): ?>
                                    <div class="utility-navigation">
                                    <?php print theme('links', array('links' => $action_items, 'attributes' => array('id' => 'action-items'))); ?>
                                    <?php
                                    if ($is_admin) : print $action_items_manage;
                                    endif;
                                    ?>
                                <?php else : ?>
                                    <?php
                                    if ($is_admin) : print $action_items_add;
                                    endif;
                                    ?>
                                    </div>
                                <?php endif; ?>
                            </div>
                        <?php endif; ?>

                        <!--  Search -->
                        <?php if (!empty($search_page)): ?>
                            <div id="search-container" class="force-w-100">
                                <?php if (module_exists('search')) : ?>
                                    <a href="<?php print $base_path; ?>search" id="site-search-container-switch"
                                       class="element-focusable">Search</a>
                                    <div id="site-search-container" class="element-invisible">
                                        <?php print $search_page; ?>
                                    </div>
                                <?php endif; ?>
                            </div>
                        <?php endif; ?>
                    </div>
                </nav>
            </div>
        </div>
    </div>
</header>


<div id="page">

    <section role="main" id="main"<?php

    if (isset($spotlight)) : print ' class="with-spotlight"';
    endif;
    ?>>
        <?php $spotlight = render($page['spotlight']); ?>

        <?php if ($spotlight) : ?>
            <section id="header-spotlight">
                <?php print $spotlight; ?>
            </section>
        <?php endif; ?>

        <div class="row clearfix">

            <div id="breadcrumb gt-breadcrumbs-title"
                 class="container <?php print $breadcrumb_remove; ?> hide-for-mobile"
                 role="complementary">
                <div class="breadcrumb-links">

                    <nav class="breadcrumb mt-3 ml-4">
                        <ul><?php print $breadcrumb; ?></ul>
                    </nav>

                </div>
            </div>

            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
                <div id="page-title" class="col col-12">
                    <h1 class="title"><?php print $title; ?></h1>
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
                <?php print render($page['content']); ?>
                <?php print render($page['main_bottom']); ?>
                <?php print $feed_icons; ?>
            </div><!-- /#content -->

            <?php
            // Render the sidebars to see if there's anything in them.
            $left_nav = render($page['left_nav']);
            $sidebar_left = render($page['left']);
            $sidebar_right = render($page['right']);
            ?>

            <?php if ($left_nav || $sidebar_left || $sidebar_right): ?>


                <?php if ($left_nav || $sidebar_left): ?>
                    <aside id="sidebar-left"
                           class="<?php print $sidebar_left_class; ?>">
                        <?php if ($left_nav) : ?>
                            <nav id="left-nav" role="navigation" aria-label="Local">
                                <?php print $left_nav; ?>
                            </nav>
                        <?php endif; ?>
                        <?php print $sidebar_left; ?>
                    </aside>
                <?php endif; ?>

                <?php if ($sidebar_right): ?>
                    <aside id="sidebar-right"
                           class="<?php print $sidebar_right_class; ?>">
                        <?php print $sidebar_right; ?>
                    </aside>
                <?php endif; ?>

            <?php endif; ?>

            <?php if ($content_close) : ?>
                <div id="content-close">
                    <?php print $content_close; ?>
                </div>
            <?php endif; ?>

        </div>
    </section><!-- /#main -->

    <!-- Social Media Icons -->
    <div id="social-media-wrapper" class="container-fluid">

        <div class="row social-media-inner clearfix" role="navigation"
             aria-label="Social Media">


            <?php if ($social_media_links): ?>
                <?php print theme('links', [
                    'links' => $social_media_links,
                    'attributes' => ['id' => 'social-media-links'],
                ]); ?>
                <?php
                if ($is_admin) : print $social_media_links_manage;
                endif;
                ?>
            <?php else : ?>
                <?php
                if ($is_admin) : print $social_media_links_add;
                endif;
                ?>
            <?php endif; ?>

        </div>

    </div>

    <div id="contentinfo" aria-label="Footers">

        <?php print $superfooter_content; ?>


        <!-- #superfooter/ -->

        <!-- /#superfooter -->

        <!-- #footer/ -->

        <!-- Top Footer Gradient Bar -->
        <div class="container-fluid footer-top-bar">
        </div>

        <div id="gt-footer" class="container-fluid footer-bottom-bar">
            <div class="container pt-3">

                <div class="row">
                    <div class="col-sm-12 col-sm-6 col-md-4 col-lg-3 ctn-footer">
                        <div id="address_text" class="pt-1">
                            <p><strong>Georgia Institute of
                                    Technology</strong><br/>
                                North Avenue, Atlanta, GA 30332<br/>
                                404.894.2000</p>
                        </div>
                    </div>


                    <div class="col-sm-12 col-md-4 col-lg-3 pt-1">
                        <ul>
                            <li>
                                <a href="https://directory.gatech.edu/"
                                   title="Directory">Directory</a>
                            </li>
                            <li>
                                <a href="https://careers.gatech.edu/"
                                   title="Employment">Employment</a>
                            </li>
                            <li>
                                <a href="https://gatech.edu/emergency/"
                                   title="Emergency Information">Emergency
                                    Information</a>
                            </li>
                            <li>
                                <a href="#" class="UsableNetAssistive" onclick="return enableUsableNetAssistive()">Enable Accessibility</a>
                            </li>
                        </ul>
                    </div>

                    <div class="col-sm-12 col-md-4 col-lg-3 pt-1">
                        <ul role="menu" aria-expanded="false">
                            <li role="menuitem"><a
                                        href="https://gatech.edu/legal/"
                                        aria-label="Legal &amp; Privacy Information">Legal
                                    &amp; Privacy Information</a></li>
                            <li role="menuitem"><a
                                        href="https://gbi.georgia.gov/human-trafficking-notice"
                                        aria-label="Human Trafficking Notice">Human
                                    Trafficking Notice</a></li>
                            <li role="menuitem"><a
                                        href="https://titleix.gatech.edu/">Title
                                    IX/Sexual Misconduct</a></li>
                            <li role="menuitem"><a
                                        href="https://osi.gatech.edu/hazing-conduct-history">Hazing
                                    Public Disclosures</a></li>
                            <li role="menuitem"><a
                                        href="https://gatech.edu/accessibility/"
                                        aria-label="Accessibility">Accessibility</a>
                            </li>
                            <li role="menuitem"><a
                                        href="https://gatech.edu/accountability/"
                                        aria-label="Accountability">Accountability</a>
                            </li>
                            <li role="menuitem"><a
                                        href="https://gatech.edu/accreditation/"
                                        aria-label="Accreditation">Accreditation</a>
                            </li>
                        </ul>
                    </div>

                    <div id="gt-logo-footer"
                         class="col-sm-12 col-sm-6 col-md-12 col-lg-3 p-0">
                        <div id="copyright">
                            <a href="https://gatech.edu"><img src="/sites/all/themes/gt/images/gt-logo-stacked-white.svg"
                                 alt="Georgia Institute of Technology"/></a>
                            <p class="p-1 float-right">© Georgia Institute of
                                Technology</p>
                            <div class="clearfix"></div>
                            <div class="<?php print $login_remove; ?> float-right pb-2">
                                <a href="/cas">Login</a>
                            </div>
                        </div>
                    </div>

                </div>
            </div>
        </div>
        <!-- /#footer -->

    </div>
</div><!-- /#page -->
