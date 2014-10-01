doxygen-bootstrapped
===================

Customize doxygen (v1.8.8) output to use the twitter bootstrap framework (v3.2.0)

I took the work done by CoActionOS and extended it further. 
[Credit](http://coactionos.com/embedded%20design%20tips/2014/01/07/Tips-Integrating-Doxygen-and-Bootstrap/)

# Getting Started
Doxygen is a great tool for documenting embedded projects. Twitter Bootstrap is an elegant, HTML5 framework that works great on both desktop and mobile browsers. Using jquery and javascript, the two technologies can be easily integrated.

# Customizing Doxygen Output
Doxygen provides for a handful of ways to [customize the output](http://www.stack.nl/~dimitri/doxygen/manual/customize.html). If you want full control over all of the Doxygen objects, you can have Doxygen output XML and then write your own output generator to do anything you want. The drawback of doing this is that it requires a substantial effort. It is much easier to simply customize the Doxygen HTML output.

Doxygen allows you to customize the HTML output by modifying the master HTML header, footer, and stylesheet. The following command will generate the default Doxygen HTML files.

`doxygen -w html header.html footer.html customdoxygen.css`
 
Modifying these files alone is not enough to get good Twitter Bootstrap integration. Bootstrap requires that certain classes be applied within the body of the HTML. For example, a Bootstrap “table” needs to have a class called “table” in order to apply the Bootstrap table formatting. Doxygen does a good job of applying classes to different objects. We just need to augment those classes with the Bootstrap classes. To do this, we use javascript and jquery. The code below will add Bootstrap formatting to various Doxygen tables.

```
$( document ).ready(function() {
	$("table.params").addClass("table");
	$("table.directory").addClass("table table-striped");
	$("table.fieldtable").addClass("table");	
});
```

For this to work well, we need to modify doxygen’s default stylesheet and remove almost all formatting. We leave the code highlighting formatting in place since this doesn’t affect any of the Bootstrap formatting, but pretty much all other Doxygen formatting is removed.
We also modify the HTML header or footer to load the Bootstrap css/javascript and our custom javascript (doxy-boot.js).

```
<link href="bootstrap3/css/bootstrap.min.css" rel="stylesheet">
<script src="bootstrap3/js/jquery-2.0.3.min.js"></script>
<script src="bootstrap3/js/bootstrap.min.js"></script>
<script type="text/javascript" src="doxy-boot.js"></script>
```

The doxy-boot.js is where all of the bootstrapping will happen.

# Conclusion
There are various ways to customize the Doxygen output. The easiest way to integrate Doxygen and Twitter Bootstrap is to use a few lines of javascript/jquery code to apply the desired Bootstrap classes to the already well documented Doxygen output. This results in fully responsive, mobile-ready code documentation.