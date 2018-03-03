#include <iostream>
using namespace std;
#include "RowColumnClass.h"

// RowColumnClass member functions definiton
// Default constructor
RowColumnClass::RowColumnClass()
{
  row = defaultVal;
  column = defaultVal;
}

// Value constructor
RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  row = inRow;
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