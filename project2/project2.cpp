#include <iostream>
using namespace std;

//Programmer: Dongxu Li
//Date: Oct 3, 2017
//Purpose: Practice of Object oriented programming practice. RGB image
//manipulation. In this program the size of the image is 10 * 18. Later in this
//course these definition in this file might be used to work on lager size of
//images.



/*----------------------------------------------------------------------------*/
// Class Definition

/*
Definition of ColorClass: This class is used to describe a color, related
attributes include: an integer representing the amount of red in a color, an
integer representing the amount of green in a color, and an integer representing
the amount of blue in a color.
*/
class ColorClass
{
   private:
      // Function valueClip clips the single value out of range.
      bool valueClip(int &colorVal);
      // Function rgbClip build upon valueClip function, which clips three
      // RGB value back to the valid range.
      bool rgbClip(int &inRed, int &inGreen, int &inBlue);
      // Define the color value range: min 0, max 1000.
      static const int colorValMax = 1000;
      static const int colorValMin = 0;
      // Declare private variables to describe the attribute needed
      int Red;
      int Green;
      int Blue;
   public:
      // Default constructor and constructor with RGB input.
      ColorClass();
      ColorClass(int inRed, int inGreen, int inBlue);
      // Class function prototype
      void setToBlack(); // Set the pixel to be full black
      void setToRed(); // Set the pixel to be full red
      void setToGreen(); // Set the pixel to be full green
      void setToBlue(); // Set the pixel to be full blue
      void setToWhite(); // Set the pixel to be full white
      // Set the pixel to a specific color
      bool setTo(int inRed, int inGreen, int inBlue);
      // Set the pixel to be the color of another pixel
      bool setTo(ColorClass &inColor);
      // This function causes each RGB value to have the corresponding value
      // from the input parameter color added to it.
      bool addColor(ColorClass &rhs);
      // This function causes each RGB value to have the corresponding value
      // from the input parameter subtracted from it.
      bool subtractColor(ColorClass &rhs);
      // This function performs a simplified brightness adjustment which
      // multiplies each RGB value by the adjustment factor provided.
      bool adjustBrightness(double adjFactor);
      // Prints the component color values to the console using the following
      // format: "R: <red> G: <green> B: <blue>".
      void printComponentValues();
};


/*
Definition of RowColumnClass: a very simple class to uniquely identify a
specific pixel within an image. Related attributes include row and column.
*/
class RowColumnClass
{
   private:
      //default value for initial row and column number
      static const int defaultVal = -99999;
      int row;
      int column;
   public:
      // Default constructor and value constructor simply sets the row and
      // column values to the corresponding values passed into the constructor
      RowColumnClass();
      RowColumnClass(int inRow, int inCol);
      // These functions are simple “setter functions” that just directly set
      // the appropriate attribute(s) to the value(s) provided.
      void setRowCol(int inRow, int inCol);
      void setRow(int inRow);
      void setCol(int inCol);
      // These functions are simple “getter functions” that just return the
      // appropriate attribute value to the caller.
      int getRow();
      int getCol();
      // This function adds the row and column index values in the input
      // parameter to the row and column index of the object.
      void addRowColTo(RowColumnClass &inRowCol);
      // This function prints this object's attribute's in the format
      // "[<row>,<col>]" where <row> and <col> are replaced with the value of
      // the corresponding attribute values.
      void printRowCol();
};


/*
Definition of ColorImageClass: this class build upon the ColorClass. The class
represent a small image, a color image will simply be defined as a collection
of color pixel values arranged in a rectangle. Required attribute for
ColorImageClass is a 2D array of ColorClass objects.
*/
class ColorImageClass
{
   private:
      // Default size of the image
      static const int defaultRow = 10;
      static const int defaultCol = 18;
      static const int minRowCol = 0;
      // The only attribute
      ColorClass image[defaultRow][defaultCol];
      // This function use to set value of every ColorClass object in the 2D
      // array using the input ColorClass object.
      void setValueForArray(ColorClass &inColor);
      // Test if RowColumnClass inRowCol is in the range of the image
      bool validRowCol(RowColumnClass &inRowCol);
   public:
      // This default constructor simply sets all pixels in the image to
      // full black.
      ColorImageClass();
      // This function initializes all image pixels to the color provided
      // via input.
      void initializeTo(ColorClass &inColor);
      // This function performs a pixel-wise addition, such that each pixel
      // in the image has the pixel in the corresponding location in the right
      // hand side input image added to it.
      bool addImageTo(ColorImageClass &rhsImg);
      // This function causes the image's pixel values to be set to the sum
      // of the corresponding pixels in each image in the imagesToAdd input
      // parameter.
      bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
      // This function attempts to set the pixel at the location specified by
      // the “inRowCol” parameter to the color specified via the “inColor”
      // parameter.
      bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
      // This function returns true and the output parameter "outColor" is
      // assigned to the color of the image pixel at that location.
      bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
      // This function prints the contents of the image to the screen. Each
      // pixel is printed using the format described for the ColorClass above.
      void printImage();
};


/*----------------------------------------------------------------------------*/
// The main test function provided by professor

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
   ColorClass testColor;
   RowColumnClass testRowCol;
   RowColumnClass testRowColOther(111, 222);
   ColorImageClass testImage;
   ColorImageClass testImages[3];

   //Test some basic ColorClass operations...
   cout << "Initial: ";
   testColor.printComponentValues();
   cout << endl;

   testColor.setToBlack();
   cout << "Black: ";
   testColor.printComponentValues();
   cout << endl;

   testColor.setToGreen();
   cout << "Green: ";
   testColor.printComponentValues();
   cout << endl;

   testColor.adjustBrightness(0.5);
   cout << "Dimmer Green: ";
   testColor.printComponentValues();
   cout << endl;

   //Test some basic RowColumnClass operations...
   cout << "Want defaults: ";
   testRowCol.printRowCol();
   cout << endl;

   testRowCol.setRowCol(2, 8);
   cout << "Want 2,8: ";
   testRowCol.printRowCol();
   cout << endl;

   cout << "Want 111, 222: ";
   testRowColOther.printRowCol();
   cout << endl;

   testRowColOther.setRowCol(4, 2);
   testRowCol.addRowColTo(testRowColOther);
   cout << "Want 6,10: ";
   testRowCol.printRowCol();
   cout << endl;

   //Test some basic ColorImageClass operations...
   testColor.setToRed();
   testImage.initializeTo(testColor);

   testRowCol.setRowCol(555, 5);
   cout << "Want: Color at [555,5]: Invalid Index!" << endl;
   cout << "Color at ";
   testRowCol.printRowCol();
   cout << ": ";
   if (testImage.getColorAtLocation(testRowCol, testColor))
   {
      testColor.printComponentValues();
   }
   else
   {
      cout << "Invalid Index!";
   }
   cout << endl;

   testRowCol.setRow(4);
   cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
   cout << "Color at ";
   testRowCol.printRowCol();
   cout << ": ";
   if (testImage.getColorAtLocation(testRowCol, testColor))
   {
      testColor.printComponentValues();
   }
   else
   {
      cout << "Invalid Index!";
   }
   cout << endl;

   //Set up an array of images of different colors
   testColor.setToRed();
   testColor.adjustBrightness(0.25);
   testImages[0].initializeTo(testColor);
   testColor.setToBlue();
   testColor.adjustBrightness(0.75);
   testImages[1].initializeTo(testColor);
   testColor.setToGreen();
   testImages[2].initializeTo(testColor);

   //Modify a few individual pixel colors
   testRowCol.setRowCol(4, 2);
   testColor.setToWhite();
   testImages[1].setColorAtLocation(testRowCol, testColor);

   testRowCol.setRowCol(2, 4);
   testColor.setToBlack();
   testImages[2].setColorAtLocation(testRowCol, testColor);

   //Add up all images in testImages array and assign result
   //to the testImage image
   testImage.addImages(3, testImages);

   //Check some certain values
   cout << "Added values:" << endl;
   for (int colInd = 0; colInd < 8; colInd += 2)
   {
      testRowCol.setRowCol(4, colInd);
      cout << "Color at ";
      testRowCol.printRowCol();
      cout << ": ";
   if (testImage.getColorAtLocation(testRowCol, testColor))
   {
      testColor.printComponentValues();
   }
   else
   {
      cout << "Invalid Index!";
   }
      cout << endl;
   }

   for (int rowInd = 0; rowInd < 8; rowInd += 2)
   {
      testRowCol.setRowCol(rowInd, 4);
      cout << "Color at ";
      testRowCol.printRowCol();
      cout << ": ";
   if (testImage.getColorAtLocation(testRowCol, testColor))
   {
      testColor.printComponentValues();
   }
   else
   {
      cout << "Invalid Index!";
   }
      cout << endl;
   }

   cout << "Printing entire test image:" << endl;
   testImage.printImage();

   return 0;
}
#endif


/*----------------------------------------------------------------------------*/
// Class member functions definiton


// ColorClass member functions definiton
// fix input value of color which is out of range
bool ColorClass::valueClip(int &colorVal)
{
   // Return true if a clip happens
   if (colorVal < colorValMin)
   {
      colorVal = colorValMin;
      return true;
   }
   else if (colorVal > colorValMax)
   {
      colorVal = colorValMax;
      return true;
   }
   else
   {
      return false;
   }
}

bool ColorClass::rgbClip(int &inRed, int &inGreen, int &inBlue)
{
   // Define 3 container to catch is there is a clip for 3 input value
   bool trueOrFalseR = valueClip(inRed);
   bool trueOrFalseG = valueClip(inGreen);
   bool trueOrFalseB = valueClip(inBlue);
   if (trueOrFalseR || trueOrFalseG || trueOrFalseB)
   {
      return true;
   }
   else
   {
      return false;
   }
}

// default constructor definition
ColorClass::ColorClass()
{
   Red = colorValMax;
   Green = colorValMax;
   Blue = colorValMax;
}

// value constructor definition
ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
   rgbClip(inRed, inGreen, inBlue);
   Red = inRed;
   Green = inGreen;
   Blue = inBlue;
}

void ColorClass::setToBlack()
{
   Red = colorValMin;
   Green = colorValMin;
   Blue = colorValMin;
}

void ColorClass::setToRed()
{
   Red = colorValMax;
   Green = colorValMin;
   Blue = colorValMin;
}

void ColorClass::setToGreen()
{
   Red = colorValMin;
   Green = colorValMax;
   Blue = colorValMin;
}

void ColorClass::setToBlue()
{
   Red = colorValMin;
   Green = colorValMin;
   Blue = colorValMax;
}

void ColorClass::setToWhite()
{
   Red = colorValMax;
   Green = colorValMax;
   Blue = colorValMax;
}

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
   bool trueOrFalse =  rgbClip(inRed, inGreen, inBlue);
   Red = inRed;
   Green = inGreen;
   Blue = inBlue;
   return trueOrFalse;
}

bool ColorClass::setTo(ColorClass &inColor)
{
   return setTo(inColor.Red, inColor.Green, inColor.Blue);
}

bool ColorClass::addColor(ColorClass &rhs)
{
   return setTo(Red + rhs.Red, Green + rhs.Green, Blue + rhs.Blue);
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
   return setTo(Red - rhs.Red, Green - rhs.Green, Blue - rhs.Blue);
}

bool ColorClass::adjustBrightness(double adjFactor)
{
   return setTo(int(Red * adjFactor), int(Green * adjFactor),
      int(Blue * adjFactor));
}

void ColorClass::printComponentValues()
{
   cout << "R: " << Red << " G: " << Green << " B: " << Blue;
}


// RowColumnClass member functions definiton
// Default constructor
RowColumnClass::RowColumnClass()
{
   row = defaultVal;
   column = defaultVal;
}
// Value constructor
RowColumnClass::RowColumnClass(int inRow, int inCol)
{
   row = inRow;
   column = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
   row = inRow;
   column = inCol;
}

void RowColumnClass::setRow(int inRow)
{
   row = inRow;
}

void RowColumnClass::setCol(int inCol)
{
   column = inCol;
}

int RowColumnClass::getRow()
{
   return row;
}

int RowColumnClass::getCol()
{
   return column;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
   setRowCol(row + inRowCol.row, column + inRowCol.column);
}

void RowColumnClass::printRowCol()
{
   cout << "[" << row << "," << column << "]";
}


// ColorClass member functions definiton
// Function used to interate through the array and assign value to the
// ColorClass object.
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
// Default constructor, set all pixels to black color
ColorImageClass::ColorImageClass()
{
   ColorClass inColor;
   inColor.setToBlack();
   setValueForArray(inColor);
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

void ColorImageClass::printImage()
{
   for (int i = 0; i < defaultRow; i++)
   {
      for (int j = 0; j < defaultCol; j++)
      {
         image[i][j].printComponentValues();
         if (j <= defaultCol - 2)
         {
            cout << "--";
         }
      }
      cout << endl;
   }
}
