#include <iostream>
using namespace std;
#include "ColorClass.h"

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

void ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
  Red = inRed;
  Green = inGreen;
  Blue = inBlue;
}

void ColorClass::setTo(ColorClass &inColor)
{
  setTo(inColor.Red, inColor.Green, inColor.Blue);
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