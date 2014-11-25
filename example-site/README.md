# How to Integrate

This is easy to integrate into your own doxyfile. Simply tell your doxyfile to use these 3 files in the HTML section:

* HTML_HEADER=header.html
    * Adds a simple Bootstrap navbar for the title
    * Wraps the content in a Bootstrap container/row combo
* HTML_FOOTER=footer.html
    * Simply closes the extra divs opened in the header.html
* HTML_EXTRA_STYLESHEET=customdoxygen.css

You should also copy `doxy-boot.js` into your `html` directory, else it won't be found.

## Note

This hasn't been tested with the search box functionality or with the Doxygen sidebar.