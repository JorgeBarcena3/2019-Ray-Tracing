#pragma once
#include <iostream>
#include <fstream>  //To open files

using namespace std;

class ImageFile
{

private:

	const char* myName;
	fstream myFile;

public:

	ImageFile();
	ImageFile(const char* name, string mode);
	~ImageFile();
	
	void openImage(const char* name, string mode);
	void closeImage();

	void addText(const char* text);
	void addText(string text);

	

};

