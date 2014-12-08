mturk
=====
For txt-csv.cpp, this file generates a csv file from a txt file. 
To change the number of images per HIT, edit the integer number in the line "#define NUM_IMAGE 25" in the .cpp file. 
Then run it either in Visual Studio or in cmd. Be sure the path of input txt file is correct in the code. The output file is named "result1.csv".

For generateHtml.cpp, this file generates the source html for designing the layout of the HIT in mturk. 
Users can change the number of images in each HIT, the number of optional answers for each image, the optional answers and the descriptions for these optionals.
All these changable information are in the begining of the code, which can be found in lines noted as "#define ".
Users can either run the code in Visual Studio or in cmd. The output file is named "source.html".
