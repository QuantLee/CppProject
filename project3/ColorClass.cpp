#include <iostream>
using namespace std;
#include "ColorClass.h"
#include <fstream>

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

int ColorClass::getRed()
{
   return Red;
}

int ColorClass::getGreen()
{
   return Green;
}
int ColorClass::getBlue()
{
   return Blue;
}