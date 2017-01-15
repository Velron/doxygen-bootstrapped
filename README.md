doxygen-bootstrapped
=====================

Doxygen theme that applies the styles of twitter bootstrap

[SEE DEMO](https://biogearsengine.com/documentation/index.html)

# Installation

Requires 'doxygen v1.8.9' or below, and 'doxygen-gui'.

* Open doxywizard
* File > Open > /example-site/Doxyfile

Now you can use this configuration as template for your project.


# For developers
Doxygen allows to customize the HTML output by modifying the HTML header,
footer and stylesheet. If you want, you can then include additional stylesheets and javascript files. 
The following command will generate the default Doxygen files.

`doxygen -w html header.html footer.html customdoxygen.css`

Modifying these files alone is not enough to get a good integration.
Bootstrap requires that certain classes be applied within the HTML. For example,
a Bootstrap “table” needs to have a class called “table” in order to apply the Bootstrap
table formatting. We just need to augment the default HTML with these Bootstrap classes.
To do this, we use the provided doxy-boot.js javascript file. Also, here you will find extra ways to
[customize the output](http://www.stack.nl/~dimitri/doxygen/manual/customize.html). 

# Files

This theme uses the next files in the HTML section of doxywizard. See example-site.

* HTML_HEADER=header.html

    > Adds a Bootstrap navbar
    >
    > Wraps the content in a Bootstrap container/row

* HTML_FOOTER=footer.html

    > Closes the extra divs opened in the header.html

* HTML\_EXTRA_STYLESHEET=customdoxygen.css

    > Adds additional styling such as a sticky footer

* HTML\_EXTRA_FILES=doxy-boot.js

    > Where the magic happens to augment the HTML with bootstrap

## Todo List
* GENERATE_TREEVIEW option is not shown, or initialized correctly.

## Credits
This started as work done by CoActionOS and was extended further here.
[Credit](http://coactionos.com/embedded%20design%20tips/2014/01/07/Tips-Integrating-Doxygen-and-Bootstrap/)
