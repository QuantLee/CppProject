#include <iostream>
using namespace std;
#include "ColorImageClass.h"
#include <fstream>

// ColorImageClass member functions definiton
// Function used to interate through the array and assign value to the
// ColorImageClass object.
void ColorImageClass::setValueForArray(ColorClass &inColor)
{
   for (int i = 0; i < defaultRow; i++)
   {
      for (int j = 0; j < defaultCol; j++)
      {
         image[i][j] = inColor;
      }
   }
}
// This constructor simply reading a image from ppm file
ColorImageClass::ColorImageClass(string fname)
{
	ifstream inFile;
	inFile.open(fname.c_str());
	inFile >> magicNumber;
	inFile >> defaultCol;
	inFile >> defaultRow;
	inFile >> colorValMax;
	// allocate memory for the two dimensional array
	image = new ColorClass* [defaultRow];
	for (int i = 0; i < defaultRow; i++)
	{
		image[i] = new ColorClass [defaultCol];
	}
	// assign every element array to be the corresponding pixel value
	for (int i = 0; i < defaultRow; i++)
	{
		for (int j = 0; j < defaultCol; j++)
		{
			int inRed;
			int inGreen;
			int inBlue;
			inFile >> inRed;
			inFile >> inGreen;
			inFile >> inBlue;
			image[i][j] = ColorClass(inRed, inGreen, inBlue);
		}
	}
	inFile.close();
}

ColorImageClass::~ColorImageClass()
{
	for (int i = 0; i < defaultRow; i++)
	{
		delete [] image[i];
	}
	delete [] image;
}

void ColorImageClass::initializeTo(ColorClass &inColor)
{
   setValueForArray(inColor);
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
   // a new variable use to remember if a clip happens
   bool clip = false;
   for (int i = 0; i < defaultRow; i++)
   {
      for (int j = 0; j < defaultCol; j++)
      {
         if (image[i][j].addColor(rhsImg.image[i][j]))
         {
            clip = true;
         }
      }
   }
   return clip;
}

bool ColorImageClass::addImages(int numImgsToAdd,
   ColorImageClass imagesToAdd [])
{
   // A new variable use to remember if a clip happens
   bool clip = false;
   // Construct a black image, becausethe object we are working on may not be a
   // full black image.
   ColorClass blackColor;
   blackColor.setToBlack();
   initializeTo(blackColor);
   for (int i = 0; i < numImgsToAdd; i++)
   {
      if (addImageTo(imagesToAdd[i]))
      {
         clip = true;
      }
   }
   return clip;
}
// Test if the RowColumnClass inRowCol is in the range of the image
bool ColorImageClass::validRowCol(RowColumnClass &inRowCol)
{
   return (inRowCol.getRow() < defaultRow && inRowCol.getRow() >= minRowCol &&
     inRowCol.getCol() < defaultCol && inRowCol.getCol() >= minRowCol);
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
   ColorClass &inColor)
{
   // values of row and column are larger than 0
   if (validRowCol(inRowCol))
   {
      image[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
      return true;
   }
   return false;
}

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
   ColorClass &outColor)
{
   // values of row and column are larger than 0
   if (validRowCol(inRowCol))
   {
      outColor.setTo(image[inRowCol.getRow()][inRowCol.getCol()]);
      return true;
   }
   return false;
}

void ColorImageClass::saveImage(string fname)
{
   ofstream outFile;
   outFile.open(fname.c_str());
   outFile << magicNumber << endl;
   outFile << defaultCol << " " << defaultRow << endl;
   outFile << colorValMax << endl;
   for (int i = 0; i < defaultRow; i++)
   {
      for (int j = 0; j < defaultCol; j++)
      {
         outFile << image[i][j].getRed() << " " << image[i][j].getGreen() << " "
         << image[i][j].getBlue();
         if(j < defaultCol-1)
         {
            outFile << " ";
         }
      }
      outFile << endl;
   }
   outFile.close();
}

void ColorImageClass::drawRectangle(bool fillOptionTrueFalse, ColorClass &pixelColor,
	RowColumnClass &upperLeft, RowColumnClass &lowerRight)
{
	if(fillOptionTrueFalse == true)
	{
		for (int i = upperLeft.getRow(); i <= lowerRight.getRow(); i++)
		{
			for (int j = upperLeft.getCol(); j <= lowerRight.getCol(); j++)
			{
				RowColumnClass inRowCol(i,j);
				setColorAtLocation(inRowCol, pixelColor);
			}
		}
	}
	else
	{
		for (int i = upperLeft.getRow(); i <= lowerRight.getRow(); i++)
		{
			for (int j = upperLeft.getCol(); j <= lowerRight.getCol(); j++)
			{
				if(i == upperLeft.getRow() || i == lowerRight.getRow() ||
					j == upperLeft.getCol() || j == lowerRight.getCol())
				{
					RowColumnClass inRowCol(i,j);
					setColorAtLocation(inRowCol, pixelColor);
				}
			}
		}
	}
}


void ColorImageClass::insertImage(ColorImageClass &inImage,
	ColorClass &transparecyColor, RowColumnClass &upperLeft)
{
	int row = upperLeft.getRow();
	int col = upperLeft.getCol();
	for (int i = row; i < row + inImage.defaultRow; i++)
	{
		for (int j = col; j < col + inImage.defaultCol; j++)
		{
			if ((inImage.image[i-row][j-col].getRed() == transparecyColor.getRed() &&
				inImage.image[i-row][j-col].getGreen() == transparecyColor.getGreen() &&
				inImage.image[i-row][j-col].getBlue() == transparecyColor.getBlue()) == false)
			{
				image[i][j] = inImage.image[i-row][j-col];
			}
		}
	}
}

void ColorImageClass::annotatePattern(string infname, ColorClass &patternColor,
	RowColumnClass &upperLeft)
{
	// readin txt file and store it in a two dimensional array
	ifstream inFile;
	inFile.open(infname.c_str());
	int inRow;
	int inCol;
	int patter;
	inFile >> inRow;
	inFile >> inCol;
	int** pattern;
	pattern = new int* [inRow];
	for (int j = 0; j < inCol; j++)
	{
		pattern[i] = new int [inCol];
	}
	for (int i = 0; i < inRow; i++)
	{
		for (int j = 0; j < inCol; j++)
		{
			inFile >> pattern[i][j];
		}
	}
	// add pattern to the imnage
	int row = upperLeft.getRow();
	int col = upperLeft.getCol();
	int transparecy = 0;
	for (int i = row; i < row + inImage.defaultRow; i++)
	{
		for (int j = col; j < col + inImage.defaultCol; j++)
		{
			if (pattern[i-row][j-col] != transparecy)
			{
				image[i][j] = patternColor;
			}
		}
	}
	// release the two dimensional array, and close file
	for (int i = 0; i < inRow; i++)
	{
		delete [] pattern[i];
	}
	delete [] pattern;
	inFile.close();
}












