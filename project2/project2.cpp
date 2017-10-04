#include <iostream>
using namespace std;

//Programmer: Dongxu Li
//Date: Oct 3, 2017
//Purpose:

// Definition of ColorClass
class ColorClass
{
    private:
        bool valueClip( int &colorVal);
        bool rgbClip(int &inRed, int &inGreen, int &inBlue);
        // Define the color range: min 0, max 1000.
        static const int colorValMax = 1000;
        static const int colorValMin = 0;
        // Declare of the private variable
        int Red;
        int Green;
        int Blue;
    public:
        // Declare constructor and deconstructor
        ColorClass();
        ColorClass(int inRed, int inGreen, int inBlue);
        // Class function prototype
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
    return setTo(int(Red * adjFactor), int(Green * adjFactor), int(Blue * adjFactor));
}

void ColorClass::printComponentValues()
{
    cout << "R: " << Red << " G: " << Green << " B: " << Blue;
}




// Definition of RowColumnClass
class RowColumnClass
{
    private:
        //default value for initial row and column number
        static const int defaultVal = -99999;
        int row;
        int column;
    public:
        RowColumnClass();
        RowColumnClass(int inRow, int inCol);
        void setRowCol(int inRow, int inCol);
        void setRow(int inRow);
        void setCol(int inCol);
        int getRow();
        int getCol();
        void addRowColTo(RowColumnClass &inRowCol);
        void printRowCol();
};

RowColumnClass::RowColumnClass()
{
    row = defaultVal;
    column = defaultVal;
}

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


// Definition of ColorImageClass
class ColorImageClass
{
    private:
        static const int defaultRow = 10;
        static const int defaultCol = 18;
        ColorClass image[defaultRow][defaultCol];
        void setValueForArray(ColorClass &inColor);
    public:
        ColorImageClass();
        void initializeTo(ColorClass &inColor);
        bool addImageTo(ColorImageClass &rhsImg);
        bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
        bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
        bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
        void printImage();
};


void ColorImageClass::setValueForArray(ColorClass &inColor)
{
    for(int i = 0; i < defaultRow; i++)
    {
        for(int j = 0; j< defaultCol; j++)
        {
            image[i][j] = inColor;
        }
    }
}

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
    // store the rhsImg[i][j] member
    for(int i = 0; i < defaultRow; i++)
    {
        for(int j = 0; j< defaultCol; j++)
        {
            if(image[i][j].addColor(rhsImg.image[i][j]))
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
    // a new variable use to remember if a clip happens
    bool clip = false;
    // construct a black image
    ColorClass blackColor;
    blackColor.setToBlack();
    initializeTo(blackColor);
    for(int i = 0; i < numImgsToAdd; i++)
    {
        if(addImageTo(imagesToAdd[i]))
        {
            clip = true;
        }
    }
    return clip;
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
    ColorClass &inColor)
{
    // values of row and column are larger than 0
    if(inRowCol.getRow() < defaultRow && inRowCol.getRow() >= 0 &&
        inRowCol.getCol() < defaultCol && inRowCol.getCol() >= 0)
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
    if(inRowCol.getRow() < defaultRow && inRowCol.getRow() >= 0 &&
        inRowCol.getCol() < defaultCol && inRowCol.getCol() >= 0)
    {
        outColor.setTo(image[inRowCol.getRow()][inRowCol.getCol()]);
        return true;
    }
    return false;
}

void ColorImageClass::printImage()
{
    for(int i = 0; i < defaultRow; i++)
    {
        for(int j = 0; j< defaultCol; j++)
        {
            image[i][j].printComponentValues();
            if(j <= defaultCol - 2)
            {
                cout<<"--";
            }
        }
        cout<<endl;
    }
}


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
