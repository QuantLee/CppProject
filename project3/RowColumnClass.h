#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

/*
Definition of RowColumnClass: a very simple class to uniquely identify a
specific pixel within an image. Related attributes include row and column.
*/
class RowColumnClass
{
   private:
      //default value for initial row and column number
      static const int defaultVal = -99999;
      int row;
      int column;
   public:
      // Default constructor and value constructor simply sets the row and
      // column values to the corresponding values passed into the constructor
      RowColumnClass();
      RowColumnClass(int inRow, int inCol);
      // These functions are simple “setter functions” that just directly set
      // the appropriate attribute(s) to the value(s) provided.
      void setRowCol(int inRow, int inCol);
      void setRow(int inRow);
      void setCol(int inCol);
      // These functions are simple “getter functions” that just return the
      // appropriate attribute value to the caller.
      int getRow();
      int getCol();
      // This function adds the row and column index values in the input
      // parameter to the row and column index of the object.
      void addRowColTo(RowColumnClass &inRowCol);
      // This function prints this object's attribute's in the format
      // "[<row>,<col>]" where <row> and <col> are replaced with the value of
      // the corresponding attribute values.
      void printRowCol();
};

#endif