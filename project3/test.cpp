#include <iostream>
#include <fstream>
using namespace std;

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
      // Prints the component color values to the console using the following
      // format: "R: <red> G: <green> B: <blue>".
      void printComponentValues();
};

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

int main()
{
	int defaultRow;
	int defaultCol;
	int colMax;
	string fname = "deer.ppm";
	ColorClass** image;
	ifstream inFile;
	inFile.open(fname.c_str());
	string magicNumber;
	inFile >> magicNumber;
	inFile >> defaultRow;
	inFile >> defaultCol;
	inFile >> colMax;
	// allocate memory for the two dimensional array
	image = new ColorClass* [defaultRow];
	for (int i; i < defaultRow; i++)
	{
		image[i] = new ColorClass [defaultCol];
	}
	// assign every element array to be the corresponding pixel value
	for (int i; i < defaultRow; i++)
	{
		for (int j; j < defaultCol; j++)
		{
			int inRed;
			int inGreen;
			int inBlue;
			inFile >> inRed;
			inFile >> inGreen;
			inFile >> inBlue;
			// ColorClass pixel(inRed, inGreen, inBlue);
			image[i][j] = ColorClass(inRed, inGreen, inBlue);
		}
	}
	inFile.close();

	for (int i; i < defaultRow; i++)
	{
		delete [] image[i];
	}
	delete [] image;
}



outFile << "1"