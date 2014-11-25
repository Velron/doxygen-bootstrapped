doxygen-bootstrapped
===================

Customize doxygen (v1.8.8) output to use the twitter bootstrap framework (v3.2.0)

[Demo](https://biogearsengine.com/documentation/index.html)

I took the work done by CoActionOS and extended it further. 
[Credit](http://coactionos.com/embedded%20design%20tips/2014/01/07/Tips-Integrating-Doxygen-and-Bootstrap/)

# Customizing Doxygen
Doxygen provides for a handful of ways to [customize the output](http://www.stack.nl/~dimitri/doxygen/manual/customize.html). The simplest way is to customize the HTML output.

Doxygen allows you to customize the HTML output by modifying a master HTML header, footer, and stylesheet. The following command will generate the default Doxygen HTML files.

`doxygen -w html header.html footer.html customdoxygen.css`
 
Modifying these files alone is not enough to get good Twitter Bootstrap integration. Bootstrap requires that certain classes be applied within the HTML. For example, a Bootstrap “table” needs to have a class called “table” in order to apply the Bootstrap table formatting. We just need to augment the default HTML with these Bootstrap classes. To do this, we use the provided doxy-boot.js javascript file.

Also, you can augment doxygen’s default stylesheet with a customdoxygen.css stylesheet. This is where you would place any custom styling such as sticky footers.

# How to Integrate

This is easy to integrate into your own doxyfile. Simply tell your doxyfile to use these 3 files in the HTML section (see the example site for an example of each file):

* HTML_HEADER=header.html
    * Adds a simple Bootstrap navbar for the title
    * Wraps the content in a Bootstrap container/row combo
* HTML_FOOTER=footer.html
    * Simply closes the extra divs opened in the header.html
* HTML_EXTRA_STYLESHEET=customdoxygen.css

You should also copy `doxy-boot.js` into your `html` directory, else it won't be found.

We have also modified the HTML header/footer to load the Bootstrap css/javascript and our custom javascript (doxy-boot.js). This is where you can specify your own bootstrap compilation. These files will also need to be placed in the html directory (or sub-directory) else they wont be found.

```
<link href="bootstrap3/css/bootstrap.min.css" rel="stylesheet">
<script src="bootstrap3/js/jquery-2.0.3.min.js"></script>
<script src="bootstrap3/js/bootstrap.min.js"></script>
<script type="text/javascript" src="doxy-boot.js"></script>
```

## Note
This hasn't been tested with the search box functionality or with the Doxygen sidebar.
