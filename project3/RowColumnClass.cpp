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