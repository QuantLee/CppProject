#include <iostream>
using namespace std;
#include "SortedListClass.h"

// Default Constructor. Will properly initialize a list to be an empty list,
// to which values can be added.
template < class T >
SortedListClass< T >::SortedListClass()
{
  head = 0;
  tail = 0;
}

// Copy constructor. Will make a complete (deep) copy of the list, such that
// one can be changed without affecting the other.
template < class T >
SortedListClass< T >::SortedListClass(const SortedListClass< T > &rhs)
{
  LinkedNodeClass< T >* temp = rhs.head;
  if (temp == 0)
  {
    head = 0;
    tail = 0;
  }
  else
  {
    head = new LinkedNodeClass< T >(0, temp -> getValue(), 0);
    // copy cTemp used for construct a new lined list
    LinkedNodeClass< T >* cTemp = head;
    while (temp -> getNext() != 0)
    {
      temp = temp -> getNext();
      cTemp = new LinkedNodeClass< T >(cTemp, temp -> getValue(), 0);
      cTemp -> setBeforeAndAfterPointers();
    }
    tail = cTemp;
  }
}

// Overloaded assignment operator.  Will make a complete (deep) copy of the
// list, such that one can be changed without affecting the other.
template < class T >
void SortedListClass< T >::operator=(const SortedListClass< T > &rhs)
{
  clear();
  LinkedNodeClass< T >* temp = rhs.head;
  if (temp == 0)
  {
    head = 0;
    tail = 0;
  }
  else
  {
    head = new LinkedNodeClass< T >(0, temp -> getValue(), 0);
    // copy cTemp used for construct a new lined list
    LinkedNodeClass< T >* cTemp = head;
    while (temp -> getNext() != 0)
    {
      temp = temp -> getNext();
      cTemp = new LinkedNodeClass< T >(cTemp, temp -> getValue(), 0);
      cTemp -> setBeforeAndAfterPointers();
    }
    tail = cTemp;
  }
}

// Clears the list to an empty state without resulting in any memory leaks.
template < class T >
void SortedListClass< T >::clear()
{
  LinkedNodeClass< T >* temp = head;
  // cTemp is used to delete the node
  if (temp == 0)
  {
    //cout << "The list is clear" << endl;
  }
  else
  {
    head = 0;
    tail = 0;
    LinkedNodeClass< T >* cTemp;
    while (temp != 0)
    {
      cTemp = temp;
      temp = temp -> getNext();
      delete cTemp;
    }
    // At this point the temp is set to be 0
    // cout << "The list is clear" << endl;
  }
}

// Allows the user to insert a value into the list. Since this is a sorted
// list, there is no need to specify where in the list to insert the element
// . It will insert it in the appropriate location based on the value being
// inserted. If the node value being inserted is found to be "equal to" one
// or more node values already in the list, the newly inserted node will be
// placed AFTER the previously inserted nodes. Input is: The value to insert
// into the list.
template < class T >
void SortedListClass< T >::insertValue(const T &valToInsert)
{
  LinkedNodeClass< T >* temp = head;
  if (temp == 0)
  {
    head = new LinkedNodeClass< T >(0, valToInsert, 0);
    tail = head;
  }
  else
  {
    while (temp != 0)
    {
      if (temp -> getValue() > valToInsert)
      {
        if (temp -> getPrev() == 0)
        {
          head = new LinkedNodeClass< T >(0, valToInsert, temp);
          head -> setBeforeAndAfterPointers();
        }
        else
        {
          LinkedNodeClass< T >* insertNode;
          insertNode = new LinkedNodeClass< T >(temp -> getPrev(), valToInsert, temp);
          insertNode -> setBeforeAndAfterPointers();
          insertNode = 0;
        }
        break;
      }
      else
      {
        if (temp -> getNext() != 0)
        {
          temp = temp -> getNext();
        }
        else
        {
          tail = new LinkedNodeClass< T >(temp, valToInsert, 0);
          tail -> setBeforeAndAfterPointers();
          break;
        }
      }
    }
  }
  temp = 0;
}

// Prints the contents of the list from head to tail to the screen. Begins
// with a line reading "Forward List Contents Follow:", then prints one list
// element per line, indented two spaces, then prints the line "End Of List
// Contents" to indicate the end of the list.
template < class T >
void SortedListClass< T >::printForward() const
{
  LinkedNodeClass< T >* temp = head;
  cout << "Forward List Contents Follow:" << endl;
  while(temp != 0)
  {
    cout << "  " << temp -> getValue() << endl;
    temp = temp -> getNext();
  }
  cout << "End Of List Contents" << endl;
}

// Prints the contents of the list from tail to head to the screen. Begins
// with a line reading "Backward List Contents Follow:", then prints one
// list element per line, indented two spaces, then prints the line "End Of
// List Contents" to indicate the end of the list.
template < class T >
void SortedListClass< T >::printBackward() const
{
  LinkedNodeClass< T >* temp = tail;
  cout << "Backward List Contents Follow:" << endl;
  while (temp != 0)
  {
    cout << "  " << temp -> getValue() << endl;
    temp = temp -> getPrev();
  }
  cout << "End Of List Contents" << endl;
}

// Removes the front item from the list and returns the value that was
// contained in it via the reference parameter. If the list was empty, the
// function returns false to indicate failure, and the contents of the
// reference parameter upon return is undefined. If the list was not empty
// and the first item was successfully removed, true is returned, and the
// reference parameter will be set to the item that was removed.
template < class T >
bool SortedListClass< T >::removeFront(T &theVal)
{
  LinkedNodeClass< T >* temp = head;
  if (temp == 0)
  {
    //cout << "empty list, theVal is undefined" << endl;
    return false;
  }
  else
  {
    theVal = temp -> getValue();
    head = temp -> getNext();
    if (head != 0)
    {
      head -> setPreviousPointerToNull();
    }
    else
    {
      tail = 0;
    }
    delete temp;
    return true;
  }
}

// Removes the last item from the list and returns the value that was
// contained in it via the reference parameter. If the list was empty, the
// function returns false to indicate failure, and the contents of the
// reference parameter upon return is undefined. If the list was not empty
// and the last item was successfully removed, true is returned, and the
// reference parameter will be set to the item that was removed.
template < class T >
bool SortedListClass< T >::removeLast(T &theVal)
{
  LinkedNodeClass< T >* temp = tail;
  if (temp == 0)
  {
    cout << "empty list, theVal is undefined" << endl;
    return false;
  }
  else
  {
    theVal = temp -> getValue();
    tail = temp -> getPrev();
    if (tail != 0)
    {
      tail -> setNextPointerToNull();
    }
    else
    {
      head = 0;
    }
    delete temp;
    return true;
  }
}

// Returns the number of nodes contained in the list.
template < class T >
int SortedListClass< T >::getNumElems() const
{
  int count = 0;
  LinkedNodeClass< T >* temp = head;
  while (temp != 0)
  {
    count = count + 1;
    temp = temp -> getNext();
  }
  return count;
}

// Provides the value stored in the node at index provided in the 0-based
// "index" parameter. If the index is out of range, then outVal remains
// unchanged and false is returned.  Otherwise, the function returns true,
// and the reference parameter outVal will contain a copy of the value at
// that location.
template < class T >
bool SortedListClass< T >::getElemAtIndex(const int index, T &outVal)
{
  LinkedNodeClass< T >* temp = head;
  if (index < 0)
  {
    return false;
  }
  // empty list, ask for index, no return value
  if (temp == 0)
  {
    return false;
  }
  for (int i = 0; i < index; i++)
  {
    if (temp -> getNext() != 0)
    {
      temp = temp -> getNext();
    }
    else
    {
      // index out of bound
      return false;
    }
  }
  outVal = temp -> getValue();
  return true;
}
// Destructor, which will free up all dynamic memory associated with this
// list when the list is destroyed (i.e when a statically allocated list
// goes out of scope or a dynamically allocated list is deleted).
template < class T >
SortedListClass< T >::~SortedListClass()
{
  clear();
}

