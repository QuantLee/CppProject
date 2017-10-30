#include <iostream>
#include <string.h>
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "RowColumnClass.h"
using namespace std;
void mainMenu(string infname);
ColorClass ColorMenu(string colorObj);
void rectangleAnnotateMenu(ColorImageClass &picture);
void patternAnnotateMenu(ColorImageClass &picture);
void insertImageMenu(ColorImageClass &picture);
//Programmer: Dongxu Li
//Date: Oct 28, 2017
//Purpose: Image editing using cpp, deal with ppm format image, realize three
//main implementations:
// 1. Allow rectangles to be drawn on an image at a specified location
// 2. Annotate image with a special pattern
// 3. insertion of another smaller PPM image within the image being modified

ColorClass ColorMenu(string colorObj)
{
	// colorObj can be 'rectangle', 'transparecy', 'pattern'
	int colorChoice;
	cout << "1. Red" << endl;
	cout << "2. Green" << endl;
	cout << "3. Blue" << endl;
	cout << "4. Black" << endl;
	cout << "5. White" << endl;
	cout << "Enter int for " << colorObj << " color: ";
	cin >> colorChoice;
	if (colorChoice == 1)
	{
		return ColorClass(255, 0, 0);
	}
	else if (colorChoice ==2)
	{
		return ColorClass(0, 255, 0);
	}
	else if (colorChoice == 3)
	{
		return ColorClass(0, 0, 255);
	}
	else if (colorChoice == 4)
	{
		return ColorClass(0, 0, 0);
	}
	else
	{
		return ColorClass(255, 255, 255);
	}
}

void rectangleAnnotateMenu(ColorImageClass &picture)
{
	cout << "1. Specify upper left and lower right corners of rectangle" << endl;
	cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
	cout << "3. Specify extent from center of rectangle"  << endl;
	cout << "Enter int for rectangle specification method: ";
	int locationMethodChoice;
	int upperLeftLowerRightChoice = 1;
	int upperLeftDimensionChoice = 2;
	int centerExtentChoice = 3;
	RowColumnClass upperLeft;
	RowColumnClass lowerRight;
	cin >> locationMethodChoice;
	if(locationMethodChoice == upperLeftLowerRightChoice)
	{
		int upperLeftRow;
		int upperLeftCol;
		int lowerRightRow;
		int lowerRightCol;
		cout << "Enter upper left corner row and column: ";
		cin >> upperLeftRow;
		cin >> upperLeftCol;
		cout << "Enter lower right corner row and column: ";
		cin >> lowerRightRow;
		cin >> lowerRightCol;
		upperLeft = RowColumnClass(upperLeftRow, upperLeftCol);
		lowerRight = RowColumnClass(lowerRightRow, lowerRightCol);
	}
	else if(locationMethodChoice  == upperLeftDimensionChoice)
	{
		int upperLeftRow;
		int upperLeftCol;
		cout << "Enter upper left corner row and column: ";
		cin >> upperLeftRow;
		cin >> upperLeftCol;
		int numOfRows;
		int numOfCols;
		cout << "Enter int for number of rows: ";
		cin >> numOfRows;
		cout << "Enter int for number of columns: ";
		cin >> numOfCols;
		// use the information provided, calculate lowerRight row and column
		// location, 1 appear below is due to simple row and column arithmetic
		upperLeft = RowColumnClass(upperLeftRow, upperLeftCol);
		lowerRight = RowColumnClass(upperLeftRow + numOfRows - 1,
			upperLeftCol + numOfCols -1);
	}
	else if(locationMethodChoice == centerExtentChoice)
	{
		int centerRow;
		int centerCol;
		cout << "Enter rectangle center row and column: ";
		cin >> centerRow;
		cin >> centerCol;
		int halfRows;
		int halfCols;
		cout << "Enter int for half number of rows: ";
		cin >> halfRows;
		cout << "Enter int for half number of columns: ";
		cin >> halfCols;
		upperLeft = RowColumnClass(centerRow - halfRows, centerCol - halfCols);
		lowerRight = RowColumnClass(centerRow + halfRows, centerCol + halfCols);
	}
	ColorClass rectangleColor;
	rectangleColor = ColorMenu("rectangle");
	int fillOption;
	int yesChoice = 1;
	int noChoice= 2;
	cout << "1. No" << endl;
	cout << "2. Yes" << endl;
	cout << "Enter int for rectangle fill option: ";
	cin >> fillOption;
	bool fillOptionTrueFalse;
	if(fillOption == yesChoice)
	{
		fillOptionTrueFalse = false;
	}
	if(fillOption == noChoice)
	{
		fillOptionTrueFalse = true;
	}
	picture.drawRectangle(fillOptionTrueFalse, rectangleColor,
		upperLeft, lowerRight);
}

void patternAnnotateMenu(ColorImageClass &picture)
{
	string infname;
	cout << "Enter string for file name containing pattern: ";
	cin >> infname;
	cout << "Enter upper left corner to insert image row and column: ";
	int upperLeftRow;
	int upperLeftCol;
	cin >> upperLeftRow;
	cin >> upperLeftCol;
	ColorClass patternColor;
	patternColor = ColorMenu("patternColor");
	RowColumnClass upperLeft(upperLeftRow, upperLeftCol);
	picture.annotatePattern(string infname, patternColor, upperLeft);
}

void insertImageMenu(ColorImageClass &picture)
{
	string infname;
	cout << "Enter string for file name of PPM image to insert: ";
	cin >> infname;
	cout << "Enter upper left corner to insert image row and column: ";
	int upperLeftRow;
	int upperLeftCol;
	cin >> upperLeftRow;
	cin >> upperLeftCol;
	RowColumnClass upperLeft(upperLeftRow, upperLeftCol);
	ColorClass transparecyColor;
	transparecyColor = ColorMenu("transparecy");
	ColorImageClass inImage(infname);
	picture.insertImage(inImage, transparecyColor, upperLeft);
}

void mainMenu(string infname)
{
	cout << "Enter string for PPM image file name to load: ";
	cin >> infname;
	ColorImageClass picture(infname);
	int mainMenuChoice = 0;
	int rectangleAnnotateChoice = 1;
	int patternAnnotateChoice = 2;
	int insertImageChoice = 3;
	int writeOutImageChoice = 4;
	// int exitProgramChoice = 5;
	while(mainMenuChoice != 5)
	{
		cout << "1. Annotate image with rectangle" << endl;
		cout << "2. Annotate image with pattern from file" << endl;
		cout << "3. Insert another image" << endl;
		cout << "4. Write out current image" << endl;
		cout << "5. Exit the program" << endl;
		cout << "Enter int for main menu choice: ";
		cin >> mainMenuChoice;
		if(mainMenuChoice == rectangleAnnotateChoice)
		{
			rectangleAnnotateMenu(picture);
		}
		else if(mainMenuChoice == patternAnnotateChoice)
		{
			patternAnnotateMenu(picture);
		}
		else if(mainMenuChoice == insertImageChoice)
		{
			insertImageMenu(picture);
		}
		else if(mainMenuChoice == writeOutImageChoice)
		{
			cout << "Enter string for PPM file name to output: ";
			string outfname;
			cin >> outfname;
			picture.saveImage(outfname);
		}
	}
	cout << "Thank you for using this program" << endl;
}


int main()
{
	string infname = "deer.ppm";
	mainMenu(infname);
}