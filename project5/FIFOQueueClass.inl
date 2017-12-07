#include<iostream>
#include "FIFOQueueClass.h"
using namespace std;

// Default Constructor. Will properly initialize a queue to be an empty
// queue, to which values can be added.
template < class T >
FIFOQueueClass< T >::FIFOQueueClass()
{
  head = 0;
  tail = 0;
}

// Inserts the value provided (newItem) into the queue.
template < class T >
void FIFOQueueClass< T >::enqueue(const T &newItem)
{
  if (head == 0)
  {
    head = new LinkedNodeClass< T >(0, newItem, 0);
    tail = head;
  }
  else
  {
    head = new LinkedNodeClass< T >(0, newItem, head);
    head -> setBeforeAndAfterPointers();
  }
}

// Attempts to take the next item out of the queue.  If the queue is empty,
// the function returns false and the state of the reference parameter
// (outItem) is undefined. If the queue is not empty, the function returns
// true and outItem becomes a copy of the next item in the queue, which is
// removed from the data structure.
template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
  if (tail == 0)
  {
    return false;
  }
  else
  {
    LinkedNodeClass< T >* temp = tail;
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
template < class T >
void FIFOQueueClass< T >::print() const
{
  LinkedNodeClass< T >* temp = head;
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
template < class T >
void FIFOQueueClass< T >::clear()
{
  LinkedNodeClass< T >* temp = head;
  // cTemp is used to delete the node
  if (temp == 0)
  {
    //cout << "The queue is clear" << endl;
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
    // cout << "The queue is clear" << endl;
  }
}

// Destructor, which will free up all dynamic memory associated with this
// queue when the list is destroyed (i.e when a statically allocated queue
// goes out of scope or a dynamically allocated queue is deleted).
template < class T >
FIFOQueueClass< T >::~FIFOQueueClass()
{
  clear();
}












