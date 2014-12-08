// tsf-csv.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <fstream>
 
using namespace std;
#define NUM_IMAGE 25
 
 
int main(int argc, char **argv)
{
   char *del;
   string line, creds[3];
   int x = 0;
   int ID=0;
    ifstream myfile;
	ofstream outfile;
   myfile.open("all_urls.txt");
   outfile.open("result1.csv");
   for(int i=0;i < NUM_IMAGE; i++)
   {
		outfile<< "Image";
		outfile<< i+1;
		outfile<< "ID";
		outfile<< ",";
		outfile<< "Image";
		outfile<< i+1;
		outfile<< "URL";
		if(i<NUM_IMAGE-1)	outfile<<",";
   }
     outfile<< "\n";
  if (myfile.is_open())
  {
	  int lineNum;
    while (!myfile.eof())
    {
		for( lineNum=0;lineNum<NUM_IMAGE;lineNum++)
		{
			if(!myfile.eof())
			{
				char oneline[1000];
				getline(myfile,line);
				//char *oneline1;
				strcpy_s(oneline,line.c_str());
				if(outfile.is_open()){
				outfile<<ID;
				outfile<<",";
				outfile<< oneline;//image URL
				if(lineNum<NUM_IMAGE-1) outfile<<",";
				}
				ID++;
			}
			else if(lineNum<NUM_IMAGE)
			{
				for(int i=lineNum; i<NUM_IMAGE;i++ ) {
				outfile<<ID++;
				outfile<<",";
				outfile<< "no picture";
				}
				lineNum=NUM_IMAGE;
				break;

			}
		}
		outfile<<"\n";
			
    }
	
		outfile.close();
		myfile.close();
  }
  else 
      cout << "Unable to open file"; 
  return 0;
}
