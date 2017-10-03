#include <iostream>
using namespace std;

//Programmer: Dongxu Li
//Date: Oct 3, 2017
//Purpose:

// Definition of ColorClass
class ColorClass
{
    public:
        // Define the color range: min 0, max 1000.
        static const int colorValMax = 1000;
        static const int colorValMin = 0;
        // Declare of the public variable
        int Red;
        int Green;
        int Blue;
        // Declare constructor and deconstructor
        ColorClass();
        ColorClass(int inRed, int inGreen, int inBlue);
        // Class function prototype
        bool valueClip( int &colorVal);
        bool rgbClip(int &inRed, int &inGreen, int &inBlue);
        void setToBlack();
        void setToRed();
        void setToGreen();
        void setToBlue();
        void setToWhite();
        bool setTo(int inRed, int inGreen, int inBlue);
        bool setTo(ColorClass &inColor);
        bool addColor(ColorClass &rhs);
        bool subtractColor(ColorClass &rhs);
        bool adjustBrightness(double adjFactor);
        void printComponentValues();
};

// fix input value of color which is out of range
bool ColorClass::valueClip( int &colorVal)
{
    if(colorVal < colorValMin)
    {
        colorVal = colorValMin;
        return true;
    }
    else if(colorVal > colorValMax)
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
    if(trueOrFalseR || trueOrFalseG || trueOrFalseB)
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
    int newRed = inColor.Red;
    int newGreen = inColor.Green;
    int newBlue = inColor.Blue;
    bool trueOrFalse =  rgbClip(newRed, newGreen, newBlue);
    Red = newRed;
    Green = newGreen;
    Blue = newBlue;
    return trueOrFalse;
}

bool ColorClass::addColor(ColorClass &rhs)
{
    int newRed = Red + rhs.Red;
    int newGreen = Green + rhs.Green;
    int newBlue = Blue + rhs.Blue;
    bool trueOrFalse =  rgbClip(newRed, newGreen, newBlue);
    Red = newRed;
    Green = newGreen;
    Blue = newBlue;
    return trueOrFalse;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
    int newRed = Red - rhs.Red;
    int newGreen = Green - rhs.Green;
    int newBlue = Blue - rhs.Blue;
    bool trueOrFalse =  rgbClip(newRed, newGreen, newBlue);
    Red = newRed;
    Green = newGreen;
    Blue = newBlue;
    return trueOrFalse;
}

bool ColorClass::adjustBrightness(double adjFactor)
{
    int newRed = int(Red * adjFactor);
    int newGreen = int(Green * adjFactor);
    int newBlue = int(Blue * adjFactor);
    bool trueOrFalse =  rgbClip(newRed, newGreen, newBlue);
    Red = newRed;
    Green = newGreen;
    Blue = newBlue;
    return trueOrFalse;
}

void ColorClass::printComponentValues()
{
    cout << "R: " << Red << " G: " << Green << " B: " << Blue;
}


int main()
{
    ColorClass testColor;

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
}
