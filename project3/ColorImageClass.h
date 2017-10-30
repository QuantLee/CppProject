#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
using namespace std;

class ColorImageClass
{
   private:
      static const int minRowCol = 0;
      // define the column row and maximum RGB value
      string magicNumber;
      int defaultRow;
      int defaultCol;
      int colorValMax;
      // The only attribute
      ColorClass** image;
      // This function use to set value of every ColorClass object in the 2D
      // array using the input ColorClass object.
      void setValueForArray(ColorClass &inColor);
      // Test if RowColumnClass inRowCol is in the range of the image
      bool validRowCol(RowColumnClass &inRowCol);
   public:
      // This constructor simply reading a image from ppm file
      ColorImageClass(string fname);
      // This deconstructor release all the momery allocated
      ~ColorImageClass();
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
      void saveImage(string fname);
      // Rectangle outlines may be placed on an image to draw attention to a
      // specific area, or filled rectangles may be placed on an image to
      // block out a specific area. fillOptionTrueFalse is the bool input to
      // specify whether the rectangle should be fill in by the same color
      void drawRectangle(bool fillOptionTrueFalse, ColorClass &pixelColor,
        RowColumnClass &upperLeft, RowColumnClass &lowerRight);
      // Insertion of another (presumably smaller) PPM image at a specified
      // location within the image being modified
      void insertImage(ColorImageClass &inImage, ColorClass &transparecyColor
        , RowColumnClass &upperLeft);
};

#endif