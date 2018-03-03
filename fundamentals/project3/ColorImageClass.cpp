#include <iostream>
using namespace std;
#include "ColorImageClass.h"
#include <fstream>

// To see if a construction of an object is successful
bool ColorImageClass::constructorIsSuccess()
{
  return constructorSuccess;
}


// Test if the RowColumnClass inRowCol is in the range of the image
bool ColorImageClass::validRowCol(RowColumnClass &inRowCol)
{
  return (inRowCol.getRow() < defaultRow && inRowCol.getRow() >= minRowCol &&
    inRowCol.getCol() < defaultCol && inRowCol.getCol() >= minRowCol);
}


// This constructor simply reading a image from ppm file,
// and construct an object, if construction is successful,
// constructorIsSuccess() returns true
ColorImageClass::ColorImageClass()
{
  string infname;
  cout << "Enter string for PPM image file name to load: ";
  cin >> infname;
  constructorSuccess = true;
  ifstream inFile;
  inFile.open(infname.c_str());
  while (inFile.fail())
  {
    cout << "Unable to open input file! Please check the file name, or try to"
    << " open another file." << endl;
    cout << "Enter string for PPM image file name to load: ";
    cin >> infname;
    inFile.open(infname.c_str());
  }
  // Magic number as a string, check if it is equal to P3
  inFile >> magicNumber;
  if (!(magicNumber == "P3"))
  {
    cout << endl << "Something is wrong with the magicNumber at the header"
      << " of the file, please check the file again." << endl;
    constructorSuccess = false;
  }
  // Check the format of input column
  else if (!(validFileInput(defaultCol, "simpleInt", inFile)))
  {
    cout << endl << "Something is wrong with the column value at the header"
      << " of the file, please check the file again." << endl;
    constructorSuccess = false;
  }
  // Check the format of input row
  else if (!(validFileInput(defaultRow, "simpleInt", inFile)))
  {
    cout << endl << "Something is wrong with the row value at the header"
      << " of the file, please check the file again." << endl;
    constructorSuccess = false;
  }
  // Check the format of the max color value, and if the value is equal to 255
  else if (!(validFileInput(colorValMax, "simpleInt", inFile) &&
    colorValMax == maxColorVal))
  {
    cout << endl << "Something is wrong with the max color value at the head"
      <<" of the file, please check the file again." << endl;
    constructorSuccess = false;
  }
  // If the deader of the file is perfect, begin to allocate memory for the two
  // dimensional array, and store the image in the two dimentional array
  else
  {
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
        if (!(validFileInput(inRed, "imageBody", inFile)))
        {
          cout << "pixel input at row: " << i << " column: " << j ;
          cout << " red input is invalid, please check the input file, " <<
            "or input another file." << endl;
          constructorSuccess = false;
          break;
        }
        if (!(validFileInput(inGreen, "imageBody", inFile)))
        {
          cout << "pixel input at row: " << i << " column: " << j ;
          cout << " green input is invalid, please check the input file, " <<
            "or input another file." << endl;
          constructorSuccess = false;
          break;
        }
        if (!(validFileInput(inBlue, "imageBody", inFile)))
        {
          cout << "pixel input at row: " << i << " column: " << j ;
          cout << " blue input is invalid, please check the input file, " <<
            "or input another file." << endl;
          constructorSuccess = false;
          break;
        }
        image[i][j] = ColorClass(inRed, inGreen, inBlue);
      }
      if (constructorSuccess == false)
      {
        break;
      }
    }
  }
  // Check the size of the image is as described in the header file, if not
  // assign the value of the constructorSuccess to be false.
  if (constructorSuccess == true)
  {
    // Check the size of the image is as described in the header file, if not
    // assign the value of the constructorSuccess to be false.
    string endFileString;
    inFile >> endFileString;
    if (!inFile.eof())
    {
      cout << "The size of the image is larger than header described" << endl;
      cout << "Please check the file, or try to open a new file."<<endl;
      cout << endl;
      constructorSuccess = false;
    }
  }
  inFile.close();
}

// Deconstructor of the class
ColorImageClass::~ColorImageClass()
{
  if (constructorSuccess)
  {
    for (int i = 0; i < defaultRow; i++)
    {
      delete [] image[i];
    }
    delete [] image;
  }
}

// Save and output image
void ColorImageClass::saveImage()
{
  cout << "Enter string for PPM file name to output: ";
  string outfname;
  cin >> outfname;
  ofstream outFile;
  outFile.open(outfname.c_str());
  while (outFile.fail())
  {
    cout << "Unable to open output file!" << endl;
    cout << "Please check the file, or try to give another file name.";
    cout << "Enter string for PPM file name to output: ";
    cin >> outfname;
    outFile.open(outfname.c_str());
  }
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

// This function attempts to set the pixel at the location specified by
// the “inRowCol” parameter to the color specified via the “inColor”
// parameter.
bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
  ColorClass &inColor)
{
  // values of row and column are larger than 0
  if (validRowCol(inRowCol))
  {
    image[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
    return true;
  }
  else
  {
    cout << endl << "The shape of the insert image size can cannot fit in the"
      << " original image because the the shape size" << endl;
    cout << endl;
  }
  return false;
}

// Insertion of another (presumably smaller) PPM image at a specified
// location within the image being modified
bool ColorImageClass::insertImage(ColorImageClass &inImage,
  ColorClass &transparecyColor, RowColumnClass &upperLeft)
{
  int row = upperLeft.getRow();
  int col = upperLeft.getCol();
  for (int i = row; i < row + inImage.defaultRow; i++)
  {
    for (int j = col; j < col + inImage.defaultCol; j++)
    {
      if (!(inImage.image[i-row][j-col].getRed() == transparecyColor.getRed() &&
        inImage.image[i-row][j-col].getGreen() == transparecyColor.getGreen() &&
        inImage.image[i-row][j-col].getBlue() == transparecyColor.getBlue()))
      {
        if (i >= defaultRow || j > defaultCol)
        {
          cout << endl << "The shape of the insert image size can cannot fit in"
            << " the original image because the the shape size" << endl;
          cout << endl;
          return false;
        }
        image[i][j].setTo(inImage.image[i-row][j-col]);
      }
    }
  }
  return true;
}

// Details in editing image with rectangle,including rectangleAnnotateMenu
// inside the private funciton and this is the second level of the menu.
bool ColorImageClass::drawRectangle(bool fillOptionTrueFalse,
  ColorClass &pixelColor, RowColumnClass &upperLeft, RowColumnClass &lowerRight)
{
  if(fillOptionTrueFalse == true)
  {
    for (int i = upperLeft.getRow(); i <= lowerRight.getRow(); i++)
    {
      for (int j = upperLeft.getCol(); j <= lowerRight.getCol(); j++)
      {
        RowColumnClass inRowCol(i,j);
        if (!setColorAtLocation(inRowCol, pixelColor))
        {
          return false;
        }
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
          if (!setColorAtLocation(inRowCol, pixelColor))
          {
            return false;
          }
        }
      }
    }
  }
  return true;
}

// Check the valid input of rgb value, string input can be 'r', 'g', 'b',
// corresponded with the red green blue input, and the value should be
// in [0 255]. HeaderCheck is for check the first a few lines of input,
// the check option can be "simpleInt", "imageBody", "binaryFile".
bool ColorImageClass::validFileInput(int &input, string checkOption,
  ifstream &inFile)
{
  // This founction is used to check the input from the ifstream
  // Option can be simpleInt, imageBody, binaryFile
  int charIgnoreNum = 200;

  if (checkOption == "simpleInt")
  {
    inFile >> input;
    if (inFile.eof())
    {
      cout << "Value in the file is missing!" << endl;
      return false;
    }
    if (inFile.fail())
    {
      inFile.clear();
      inFile.ignore(charIgnoreNum, '\n');
      cout << endl << "Fail state! The input is not an interger!" << endl;
      return false;
    }
  }

  if (checkOption == "imageBody")
  {
    inFile >> input;
    if (inFile.eof())
    {
      cout << "Image size is smaller than the file head described!" << endl;
      return false;
    }
    if (inFile.fail())
    {
      inFile.clear();
      inFile.ignore(charIgnoreNum, '\n');
      cout << endl << "Fail state! The input is not an interger!" << endl;
      return false;
    }
    if (input > maxColorVal || input < minColorVal)
    {
      cout << endl << "The input color value is out of range [0, 255]!" << endl;
      return false;
    }
  }

  if (checkOption == "binaryFile")
  {
    inFile >> input;
    if (inFile.eof())
    {
      cout << "Image size is smaller than the file head described!" << endl;
      return false;
    }
    if (inFile.fail())
    {
      inFile.clear();
      inFile.ignore(charIgnoreNum, '\n');
      cout << endl << "Fail state! The input is not an interger!" << endl;
      return false;
    }
    if ((input == 1 || input == 0) == false)
    {
      cout << endl << "The input txt file body is not binary value!" << endl;
      return false;
    }
  }
  return true;
}

// Function for cin with error detection, make sure input is int variable
void ColorImageClass::intInput(int &input)
{
  int charIgnoreNum = 200;
  bool validInputFound = false;
  while (!validInputFound)
  {
    cin >> input;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(charIgnoreNum, '\n');
      cout << endl << "Fail state! The input is not an interger" << endl;
      cout << "Try again - Enter an interger: ";
    }
    else
    {
      validInputFound = true;
    }
  }
}

// Color menu which enables using to select a color for invisible color or
// select color for drawing the rectangle.
ColorClass ColorImageClass::ColorMenu(string colorObj)
{
  // colorObj can be 'rectangle', 'transparecy', 'pattern'
  int colorChoice;
  // User has to have a valid input to escape from this loop
  while(true)
  {
    int RedChoice = 1;
    int GreenChoice = 2;
    int BlueChoice = 3;
    int BlackChoice = 4;
    int WhiteChoice = 5;
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    cout << "Enter int for " << colorObj << " color: ";
    intInput(colorChoice);
    ColorClass colorChosen;
    if (colorChoice == RedChoice)
    {
      // Return the Red color
      colorChosen.setToRed();
      return colorChosen;
    }
    else if (colorChoice == GreenChoice)
    {
      // Return the Green color
      colorChosen.setToGreen();
      return colorChosen;
    }
    else if (colorChoice == BlueChoice)
    {
      // Return the Blue color
      colorChosen.setToBlue();
      return colorChosen;
    }
    else if (colorChoice == BlackChoice)
    {
      // Return the Black color
      colorChosen.setToBlack();
      return colorChosen;
    }
    else if (colorChoice == WhiteChoice)
    {
      // Return the White color
      colorChosen.setToWhite();
      return colorChosen;
    }
    else
    {
      cout << endl << "Invalid choice for color menu, ";
      cout << "Please input another choice!" << endl;
      cout << endl;
      continue;
    }
  }
}

// With this function to begin an interactive way of editing the image,
// it's the first step to enter in the main menu, which is the first level
// of menu.
void ColorImageClass::imageEditing()
{
  int mainMenuChoice = 0;
  int rectangleAnnotateChoice = 1;
  int patternAnnotateChoice = 2;
  int insertImageChoice = 3;
  int writeOutImageChoice = 4;
  int exitProgramChoice = 5;
  while(mainMenuChoice != exitProgramChoice)
  {
    cout << "1. Annotate image with rectangle" << endl;
    cout << "2. Annotate image with pattern from file" << endl;
    cout << "3. Insert another image" << endl;
    cout << "4. Write out current image" << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter int for main menu choice: ";
    intInput(mainMenuChoice);
    if(mainMenuChoice == rectangleAnnotateChoice)
    {
      rectangleAnnotateMenu();
    }
    else if(mainMenuChoice == patternAnnotateChoice)
    {
      patternAnnotateMenu();
    }
    else if(mainMenuChoice == insertImageChoice)
    {
      insertImageMenu();
    }
    else if(mainMenuChoice == writeOutImageChoice)
    {
      saveImage();
    }
    else if(mainMenuChoice == exitProgramChoice)
    {
      cout << endl << "Thank you for using this program!" << endl;
    }
    else
    {
      cout << endl << "Invalid choice for main menu, ";
      cout << "Please input another choice!" << endl;
      cout << endl;
    }
  }
}

// Detailsin editing image with rectangle,including rectangleAnnotateMenu
// inside the private funciton and this is the second level of the menu.
int ColorImageClass::rectangleAnnotateMenu()
{
  cout << "1. Specify upper left and lower right corners of rectangle" << endl;
  cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
  cout << "3. Specify extent from center of rectangle" << endl;
  cout << "Enter int for rectangle specification method: ";
  int locationMethodChoice;
  int upperLeftLowerRightChoice = 1;
  int upperLeftDimensionChoice = 2;
  int centerExtentChoice = 3;
  RowColumnClass upperLeft;
  RowColumnClass lowerRight;
  intInput(locationMethodChoice);
  if(locationMethodChoice == upperLeftLowerRightChoice)
  {
    int upperLeftRow;
    int upperLeftCol;
    int lowerRightRow;
    int lowerRightCol;
    cout << "Enter upper left corner row and column: ";
    intInput(upperLeftRow);
    intInput(upperLeftCol);
    cout << "Enter lower right corner row and column: ";
    intInput(lowerRightRow);
    intInput(lowerRightCol);
    upperLeft = RowColumnClass(upperLeftRow, upperLeftCol);
    lowerRight = RowColumnClass(lowerRightRow, lowerRightCol);
  }
  else if(locationMethodChoice  == upperLeftDimensionChoice)
  {
    int upperLeftRow;
    int upperLeftCol;
    cout << "Enter upper left corner row and column: ";
    intInput(upperLeftRow);
    intInput(upperLeftCol);
    int numOfRows;
    int numOfCols;
    cout << "Enter int for number of rows: ";
    intInput(numOfRows);
    cout << "Enter int for number of columns: ";
    intInput(numOfCols);
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
    intInput(centerRow);
    intInput(centerCol);
    int halfRows;
    int halfCols;
    cout << "Enter int for half number of rows: ";
    intInput(halfRows);
    cout << "Enter int for half number of columns: ";
    intInput(halfCols);
    upperLeft = RowColumnClass(centerRow - halfRows, centerCol - halfCols);
    lowerRight = RowColumnClass(centerRow + halfRows, centerCol + halfCols);
  }
  else
  {
    cout << endl << "location Method Choice not valid, please start all over!"
      << endl;
    return 1;
  }
  ColorClass rectangleColor;
  rectangleColor = ColorMenu("rectangle");
  int fillOption;
  int yesChoice = 1;
  int noChoice= 2;
  cout << "1. No" << endl;
  cout << "2. Yes" << endl;
  cout << "Enter int for rectangle fill option: ";
  intInput(fillOption);
  bool fillOptionTrueFalse;
  if(fillOption == yesChoice)
  {
    fillOptionTrueFalse = false;
  }
  else if(fillOption == noChoice)
  {
    fillOptionTrueFalse = true;
  }
  else
  {
    cout << endl << "The fill option is invalid, please start all over" << endl;
    cout << endl;
    return 1;
  }
  if (!drawRectangle(fillOptionTrueFalse, rectangleColor, upperLeft,
    lowerRight))
  {
    return 1;
  }
  return 0;
}

// Details in editing image with rectangle,including patternAnnotateMenu
// inside the private funciton and this is the second level of the menu.
int ColorImageClass::patternAnnotateMenu()
{
  // readin txt file and store it in a two dimensional array
  string infname;
  cout << "Enter string for file name containing pattern: ";
  cin >> infname;
  ifstream inFile;
  inFile.open(infname.c_str());
  while (inFile.fail())
  {
    cout << "Unable to open input file!" << endl;
    cout << "Please check the file, or try to give another file name." << endl;
    cout << "Enter string for txt file name to input: ";
    cin >> infname;
    inFile.open(infname.c_str());
  }

  int inRow;
  int inCol;
  if (!(validFileInput(inCol, "simpleInt", inFile) &&
    validFileInput(inRow, "simpleInt", inFile)))
  {
    cout << endl << "Header of the file is not valid, please start all over!"
    << endl;
    return 0;
  }

  int** pattern;
  pattern = new int* [inRow];
  for (int i = 0; i < inRow; i++)
  {
    pattern[i] = new int [inCol];
  }
  for (int i = 0; i < inRow; i++)
  {
    for (int j = 0; j < inCol; j++)
    {
      if (!validFileInput(pattern[i][j], "binaryFile", inFile))
      {
        cout << "binary input at row: " << i << " column: " << j ;
        cout << " is invalid, please check the input file, " <<
          "or input another file" << endl;
        cout << endl;
        return 0;
      }
    }
  }
  string endFileString;
  inFile >> endFileString;
  if (!inFile.eof())
  {
    cout << "The size of pattern is larger than the header described. " << endl;
    cout << "Please check the file, or try to open a new file."<<endl;
    cout << endl;
    inFile.close();
    return 0;
  }

  cout << "Enter upper left corner to insert image row and column: ";
  int upperLeftRow;
  int upperLeftCol;
  intInput(upperLeftRow);
  intInput(upperLeftCol);
  RowColumnClass upperLeft(upperLeftRow, upperLeftCol);
  if (!validRowCol(upperLeft))
  {
    cout << endl << "Invalid input for upper left row and colunm input"
      << " please start all over!" ;
    cout << endl;
    return false;
  }
  ColorClass patternColor;
  patternColor = ColorMenu("patternColor");

  // add pattern to the imnage
  int row = upperLeft.getRow();
  int col = upperLeft.getCol();
  // for patter the transparency is denote by 0
  int transparecy = 0;
  for (int i = row; i < row + inRow; i++)
  {
    for (int j = col; j < col + inCol; j++)
    {
      if (pattern[i-row][j-col] != transparecy)
      {
        if (i >= defaultRow || j > defaultCol)
        {
          cout << endl << "The shape of the insert image size can cannot fit in"
            << " the original image because the the shape size" << endl;
          cout << endl;
          return false;
        }
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
  return 0;
}

// Details in editing image with pattern,including insertImageMenu
// inside the private funciton and this is the second level of the menu.
int ColorImageClass::insertImageMenu()
{
  ColorImageClass inImage;
  while (!inImage.constructorIsSuccess())
  {
    return 1;
  }
  cout << "Enter upper left corner to insert image row and column: ";
  int upperLeftRow;
  int upperLeftCol;
  intInput(upperLeftRow);
  intInput(upperLeftCol);
  RowColumnClass upperLeft(upperLeftRow, upperLeftCol);
  if (!validRowCol(upperLeft))
  {
    cout << endl << "Invalid input for upper left row and colunm input"
      << " please start all over!" ;
    cout << endl;
    return false;
  }
  ColorClass transparecyColor;
  transparecyColor = ColorMenu("transparecy");
  if (!insertImage(inImage, transparecyColor, upperLeft))
  {
    return 1;
  }
  return 0;
}
