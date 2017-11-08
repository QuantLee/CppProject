#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
using namespace std;

/*
Definition of ColorImageClass: this class build upon the ColorClass. The class
represent a small image, a color image will simply be defined as a collection
of color pixel values arranged in a rectangle. Required attribute for
ColorImageClass is a 2D array of ColorClass objects. The 2D array construction
is achieved by using dynamic anocation method. And the ColorImageClass itself
has a function of imageEditing, it is a start of interactive image editing
method, which has several depth menu inside.
*/

class ColorImageClass
{
  private:
    static const int minRowCol = 0;
    static const int minColorVal = 0;
    static const int maxColorVal = 255;
    // Define the column row and maximum RGB value
    string magicNumber;
    int defaultRow;
    int defaultCol;
    int colorValMax;
    // To see if a construction of an object is successful
    bool constructorSuccess;
    // Dynamic allocation of two dimensional array
    ColorClass** image;
    // Test if RowColumnClass inRowCol is in the range of the image
    bool validRowCol(RowColumnClass &inRowCol);
    // Check the valid input of rgb value, string input can be 'r', 'g', 'b',
    // corresponded with the red green blue input, and the value should be
    // in [0 255]. HeaderCheck is for check the first a few lines of input,
    // the check option can be "simpleInt", "imageBody", "binaryFile".
    bool validFileInput(int &input, string checkOption, ifstream &inFile);
    // Function for cin with error detection, make sure input is int variable
    void intInput(int &input);
    // This function attempts to set the pixel at the location specified by
    // the “inRowCol” parameter to the color specified via the “inColor”
    // parameter.
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    // This function prints the contents of the image to the file. Each
    // pixel is printed using the format described for the ColorClass above.
    void saveImage();
    // Rectangle outlines may be placed on an image to draw attention to a
    // specific area, or filled rectangles may be placed on an image to
    // block out a specific area. fillOptionTrueFalse is the bool input to
    // specify whether the rectangle should be fill in by the same color
    bool drawRectangle(bool fillOptionTrueFalse, ColorClass &pixelColor,
      RowColumnClass &upperLeft, RowColumnClass &lowerRight);
    // Insertion of another (presumably smaller) PPM image at a specified
    // location within the image being modified
    bool insertImage(ColorImageClass &inImage, ColorClass &transparecyColor
      , RowColumnClass &upperLeft);
    // An image may be annotated with a “pattern”. A pattern, while
    // rectangular overall, contains a description of a shape that is to be
    // placed on an image
    // Detailsin editing image with rectangle,including rectangleAnnotateMenu
    // inside the private funciton and this is the second level of the menu.
    int rectangleAnnotateMenu();
    // Details in editing image with rectangle,including patternAnnotateMenu
    // inside the private funciton and this is the second level of the menu.
    int patternAnnotateMenu();
    // Details in editing image with pattern,including insertImageMenu
    // inside the private funciton and this is the second level of the menu.
    int insertImageMenu();
    // Color menu which enables using to select a color for invisible color or
    // select color for drawing the rectangle.
    ColorClass ColorMenu(string colorObj);
  public:
    // To output a true or false value, indicating if the constructor is
    // successful
    bool constructorIsSuccess();
    // This constructor simply reading a image from ppm file
    ColorImageClass();
    // This deconstructor release all the momery allocated
    ~ColorImageClass();
    // With this function to begin an interactive way of editing the image,
    // it's the first step to enter in the main menu, which is the first level
    // of menu.
    void imageEditing();
};

#endif