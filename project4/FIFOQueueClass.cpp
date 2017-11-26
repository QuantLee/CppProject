#include<iostream>
#include "FIFOQueueClass.h"
using namespace std;

// Default Constructor. Will properly initialize a queue to be an empty
// queue, to which values can be added.
FIFOQueueClass::FIFOQueueClass()
{
  head = 0;
  tail = 0;
}

// Inserts the value provided (newItem) into the queue.
void FIFOQueueClass::enqueue(const int &newItem)
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

// Attempts to take the next item out of the queue.  If the queue is empty,
// the function returns false and the state of the reference parameter
// (outItem) is undefined. If the queue is not empty, the function returns
// true and outItem becomes a copy of the next item in the queue, which is
// removed from the data structure.
bool FIFOQueueClass::dequeue(int &outItem)
{
  if (tail == 0)
  {
    return false;
  }
  else
  {
    LinkedNodeClass* temp = tail;
    outItem = temp -> getValue();
    if (tail -> getPrev() != 0)
    {
      tail = tail -> getPrev();
      tail -> setNextPointerToNull();
      delete temp;
    }
    else
    {
      tail = 0;
      head = 0;
      delete temp;
    }
    return true;
  }
}

// Prints out the contents of the queue. All printing is done on one line,
// using a single space to separate values, and a single newline character
// is printed at the end.
void FIFOQueueClass::print() const
{
  LinkedNodeClass* temp = head;
  if (temp == 0)
  {
    cout << "empty queue, no print out" << endl;
  }
  while (temp != 0)
  {
    cout << temp -> getValue() << " ";
    temp = temp -> getNext();
  }
  cout << endl;
}

//Clears the queue to an empty state without resulting in any memory leaks.
void FIFOQueueClass::clear()
{
  LinkedNodeClass* temp = head;
  // cTemp is used to delete the node
  if (temp == 0)
  {
    cout << "The queue is clear" << endl;
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
    cout << "The queue is clear" << endl;
  }
}














