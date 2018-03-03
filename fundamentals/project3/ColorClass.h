#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

/*
Definition of ColorClass: This class is used to describe a color, related
attributes include: an integer representing the amount of red in a color, an
integer representing the amount of green in a color, and an integer representing
the amount of blue in a color.
*/
class ColorClass
{
  private:
    // Define the color value range: min 0, max 1000.
    static const int colorValMax = 255;
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
    // Set the pixel to be the color of another pixel
    void setTo(int inRed, int inGreen, int inBlue);
    void setTo(ColorClass &inColor);
    // Get the rgb value in the private
    int getRed();
    int getGreen();
    int getBlue();
};

#endif