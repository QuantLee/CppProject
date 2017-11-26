#include<iostream>
using namespace std;
#include "LIFOStackClass.h"

// Default Constructor. Will properly initialize a stack to be an empty
// stack, to which values can be added.
LIFOStackClass::LIFOStackClass()
{
  head = 0;
  tail = 0;
}

// Inserts the value provided (newItem) into the stack.
void LIFOStackClass::push(const int &newItem)
{
  if (head == 0)
  {
    head = new LinkedNodeClass(0, newItem, 0);
    tail = head;
  }
  else
  {
    head = new LinkedNodeClass(0, newItem, head);
    head -> setBeforeAndAfterPointers();
  }
}

// Attempts to take the next item out of the stack. If the stack is empty,
// the function returns false and the state of the reference parameter
// (outItem) is undefined.  If the stack is not empty, the function returns
// true and outItem becomes a copy of the next item in the stack, which is
// removed from the data structure.
bool LIFOStackClass::pop(int &outItem)
{
  if (head == 0)
  {
    return false;
  }
  else
  {
    LinkedNodeClass* temp = head;
    outItem = temp -> getValue();
    if (head -> getNext() != 0)
    {
      head = head -> getNext();
      head -> setPreviousPointerToNull();
      delete temp;
    }
    else
    {
      tail = 0;
      head = 0;
      delete temp;
    }
    return false;
  }
}

// Prints out the contents of the stack. All printing is done on one line,
// using a single space to separate values, and a single newline character
// is printed at the end.
void LIFOStackClass::print() const
{
  LinkedNodeClass* temp = head;
  if (temp == 0)
  {
    cout << "empty stack, no print out" << endl;
  }
  while (temp != 0)
  {
    cout << temp -> getValue() << " ";
    temp = temp -> getNext();
  }
  cout << endl;
}

//Clears the stack to an empty state without resulting in any /memory leaks.
void LIFOStackClass::clear()
{
  LinkedNodeClass* temp = head;
  // cTemp is used to delete the node
  if (temp == 0)
  {
    cout << "The stack is clear" << endl;
  }
  else
  {
    head = 0;
    tail = 0;
    LinkedNodeClass* cTemp;
    while (temp != 0)
    {
      cTemp = temp;
      temp = temp -> getNext();
      delete cTemp;
    }
    // At this point the temp is set to be 0
    cout << "The stack is clear" << endl;
  }
}













