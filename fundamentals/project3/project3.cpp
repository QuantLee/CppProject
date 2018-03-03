#include <iostream>
#include <string.h>
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "RowColumnClass.h"
using namespace std;

//Programmer: Dongxu Li
//Date: Oct 28, 2017
//Purpose: Image editing using cpp, deal with ppm format image, realize three
//main implementations:
// 1. Allow rectangles to be drawn on an image at a specified location
// 2. Annotate image with a special pattern
// 3. insertion of another smaller PPM image within the image being modified
int main()
{
  ColorImageClass picture;
  // If the construction of the picture object is not successful, terminate the
  // program and return to 1. Otherwise return 0.
  if (!picture.constructorIsSuccess())
  {
    return 1;
  }
  picture.imageEditing();
  return 0;
}