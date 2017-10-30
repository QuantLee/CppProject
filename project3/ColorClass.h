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
      // Function valueClip clips the single value out of range.
      bool valueClip(int &colorVal);
      // Function rgbClip build upon valueClip function, which clips three
      // RGB value back to the valid range.
      bool rgbClip(int &inRed, int &inGreen, int &inBlue);
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
      // return color values to the console using the following
      int getRed();
      int getGreen();
      int getBlue();
};

#endif