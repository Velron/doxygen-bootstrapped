doxygen-bootstrapped
===================

Customize doxygen (v1.8.9) output to use the twitter bootstrap framework (v3.3.1)

[Demo](https://biogearsengine.com/documentation/index.html)

This started as work done by Stratify Labs and was extended further here.
[Credit](https://stratifylabs.co/embedded%20design%20tips/2014/01/07/Tips-Integrating-Doxygen-and-Bootstrap/)

## Example project

This is a minimal working example to get you started. It can be run by executing `doxygen` from the `example-site` directory. The documentation for this minimal example will be generated in Docs/html.

## How to integrate with your own Doxygen project

This example uses `footer.html` and `header.html` from the `example-site` directory. The following options must be set in your Doxyfile.

* HTML_HEADER=../rel/path/to/header.html
    * Adds a Bootstrap navbar
    * Wraps the content in a Bootstrap container/row
* HTML_FOOTER=../rel/path/to/footer.html
    * Closes the extra divs opened in the header.html
* HTML\_EXTRA_STYLESHEET=../rel/path/to/customdoxygen.css
    * Adds additional styling such as a sticky footer
* HTML\_EXTRA_FILES=../rel/path/to/doxy-boot.js
    * Where the magic happens to augment the HTML with bootstrap
* HTML_DYNAMIC_MENUS   = NO
* GENERATE_TREEVIEW = NO
    * Without these two options as NO, the menu looks weird or does not display at all, and makes the whole page really buggy
* GENERATE_HTML = YES

This will copy the header.html, footer.html, doxy-boot.js and the custom_doxygen.css files to the html output directory. See below for further customisation

# Customizing Doxygen
Doxygen provides a handful of ways to [customize the output](http://www.stack.nl/~dimitri/doxygen/manual/customize.html). The simplest way is to customize the HTML output.

Doxygen allows you to customize the HTML output by modifying a master HTML header, footer and stylesheet. You can then include additional stylesheets and javascript files. The following command will generate the default Doxygen files.

`doxygen -w html header.html footer.html customdoxygen.css`

Modifying these files alone is not enough to get good Twitter Bootstrap integration. Bootstrap requires that certain classes be applied within the HTML. For example, a Bootstrap “table” needs to have a class called “table” in order to apply the Bootstrap table formatting. We just need to augment the default HTML with these Bootstrap classes. To do this, we use the provided doxy-boot.js javascript file.

Also, you can augment doxygen’s default stylesheet with a customdoxygen.css stylesheet. This is where you would place any custom styling such as sticky footers.

NOTE: Your header.html file needs to include the Bootstrap css/javascript for this to work. This is where you can specify your own bootstrap compilation. These files will need to appear in the html directory. This can be done manually, or added as additional files for HTML_EXTRA_FILES or using a hyperlink (see example-site header.html).

## Todo List
    * Menu is not correctly displayed when Doxygen sidebar is enabled.
