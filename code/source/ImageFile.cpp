#include "../headers/ImageFile.hpp"

ImageFile::ImageFile()
{
}

ImageFile::ImageFile(const char* name, string mode)
{
	openImage(name, mode);

}


ImageFile::~ImageFile()
{
	if (myFile.is_open())
		myFile.close();
}

void ImageFile::openImage(const char* name, string mode) {

	if (mode == "read")
		myFile.open(name, fstream::in);
	else
		myFile.open(name, fstream::out);
	
}

void ImageFile::closeImage() {

	if (myFile.is_open())
		myFile.close();
	else
		cout << endl << "The file is not open, so I cant close it" << endl;

}

void ImageFile::addText(const char* text) {

	if (myFile.is_open())
		myFile << text;
	else
		cout << endl << "The file is not open, so I cant write it" << endl;

}

void ImageFile::addText(string text) {

	const char* str = text.c_str();

	if (myFile.is_open())
		myFile << str;
	else
		cout << endl << "The file is not open, so I cant write it" << endl;

}