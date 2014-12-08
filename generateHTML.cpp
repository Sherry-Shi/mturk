// tsf-csv.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <fstream>
 
using namespace std;
#define NUM_IMAGE 25
#define NUM_OPTION 4
#define OPTIONS {"Photo of ONE person","Photo of MULTIPLE people or same person multiple times","Photo WITHOUT people","Not a photo; e.g.logo or graphics"}
#define OPTION_DESCRIPTION {"the image is a photo&nbsp; and shows a single person, even if the person is not fully visible.","the image is a photo and shows multiple people, or multiple photos of the same person. The people don&#39;t have to be fully visible.","the image is a photo, but no people are clearly visible.","the image is not produced with a camera or phone; select this option when the image looks like it was created using a computer or drawn by hand."}
int main(int argc, char **argv)
{
   char *del;
   string line, creds[3];
   int x = 0;
   int ID=0;
   string option[NUM_OPTION]= OPTIONS;
   string option_description[NUM_OPTION]=OPTION_DESCRIPTION;
    ifstream myfile;
	ofstream outfile;
   outfile.open("source.html");
   outfile<<" <link href='https://s3.amazonaws.com/mturk-public/bs30/css/bootstrap.min.css' rel='stylesheet' /> ";
outfile<<" <section class='container' id='Other' style='margin-bottom:15px; padding: 10px 10px; font-family: Verdana, Geneva, sans-serif; color:#333333; font-size:0.9em;'>";
outfile<<" <div class='row col-xs-12 col-md-12'><!-- Instructions -->";
outfile<<" <div class='panel panel-primary'>";
outfile<<"<div class='panel-heading'><strong>Instructions</strong></div>";
outfile<<"<div class='panel-body'>";
outfile<<"<div class='panel-body'>";
outfile<<"<p>Given an image select the category that best describes it. The first decision is whether the image shows a photo (ie, taken with a camera or phone). Photos with graphics on top still qualify as photos. Then choose the best category as follows:</p>";
outfile<<"<ul>";
for(int i=0;i< NUM_OPTION;i++){

outfile<<"	<li><strong>";
outfile<<option[i];
outfile<<"</strong>:";
outfile<<option_description[i];
outfile<<"</li>";
//outfile<<"	<li><strong>Photo of MULTIPLE people or same person multiple times</strong>: the image is a photo and shows multiple people, or multiple photos of the same person. The people don&#39;t have to be fully visible.</li>";
}
outfile<<" </ul>";
outfile<<"</div>";
outfile<<"</div>";
outfile<<"</div>";
outfile<<"<!-- End Instructions --><!-- Content Body -->";
outfile<<"<section>";
for(int i=0;i< NUM_IMAGE;i++){
outfile<<"<fieldset> ";
outfile<<"<div class='row'>";
outfile<<"<div class='col-xs-8'><img src='${Image";
outfile<<i+1;
outfile<<"URL}' style='max-width:400px;max-height:304px;min-height:200px' /></div>";
outfile<<"<div class='col-lg-2' style='position:relative; margin-top: 100px'>";
for(int j=0;j< NUM_OPTION;j++){
outfile<<"<form action=''>";
outfile<<"<div class='radio'><label><input name='Image";
outfile<<i+1;
outfile<<"Answer' type='radio' value='option";
outfile<<j+1;
outfile<<"' />";
outfile<< option[j];
outfile<<"</label></div>";
}
//outfile<<"<div class='radio'><label><input name='Image1Answer' type='radio' value='NA' />Not a photo; e.g.logo or graphics</label></div>";
outfile<<"</form>";
outfile<<"</div>";
outfile<<"</div>";
outfile<<"</fieldset>";
}
outfile<<"</section>";
outfile<<"<!-- End Content Body --></div>";
outfile<<"</section>";
outfile<<"<!-- close container -->";
outfile<<"<style type='text/css'>fieldset {";
outfile<< "   padding: 10px;";
outfile<<"    background:#fbfbfb;";
outfile<<"    border-radius:5px;";
outfile<<"    margin-bottom:5px;";
outfile<<"}";
outfile<<"</style>";
outfile<<"\n";
outfile<<"<script type='text/javascript' src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js\"></script><script type='text/javascript'>";
outfile<<"\n";
outfile<<"	$(function() { ";
outfile<<"\n";
outfile<<"    var pixelSource = 'http://upload.wikimedia.org/wikipedia/commons/c/ce/Transparent.gif';";
outfile<<"\n";
outfile<<"     var useOnAllImages = true;";
outfile<<"\n";
    // Preload the pixel
outfile<<"     var preload = new Image();";
outfile<<"\n";
outfile<<"     preload.src = pixelSource;";
outfile<<"\n";
outfile<<"     $('img').live('mouseenter touchstart', function(e) {";
outfile<<"\n";
        // Only execute if this is not an overlay or skipped
outfile<<"         var img = $(this);";
outfile<<"\n";
outfile<<"         if (img.hasClass('protectionOverlay')) return;";
outfile<<"\n";
outfile<<"         if (!useOnAllImages && !img.hasClass('protectMe')) return;";
outfile<<"\n";        // Get the real image's position, add an overlay
outfile<<"         var pos = img.offset();";
outfile<<"\n";
outfile<<"         var overlay = $('<img class=\"protectionOverlay\" src=\"' + pixelSource + '\" width=\"' + img.width() + '\" height=\"' + img.height() + '\" />').css({position: 'absolute', zIndex: 9999999, left: pos.left, top: pos.top}).appendTo('body').bind('mouseleave', function() {";
outfile<<"\n";
outfile<<"         setTimeout(function(){ overlay.remove(); }, 0, $(this));";
outfile<<"         });";
outfile<<"\n";
outfile<<"         if ('ontouchstart' in window) $(document).one('touchend', function(){ setTimeout(function(){ overlay.remove(); }, 0, overlay); });";
outfile<<"     });";
outfile<<"\n";
outfile<<" });";
outfile<<"\n";
outfile<<" </script>";
  return 0;
}
