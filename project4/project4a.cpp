#include <iostream>
using namespace std;

#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"

// Programmer: Dongxu Li
// Date: Nov 16, 2017
// Purpose: Construct 3 data structure classes: Sorted double linked list class,
// Queue class and stack class. And a test main function.

// Do NOT remove any of the preprocessor directives in this file.
// They should not affect your ability to write test code in your
// main function below, and they must be in your submitted main
// file exactly as provided to you with the project.

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
void testStack();
void testQueue();
void testLinkedList();

int main()
{
  // This is just a placeholder main function - it does exceptionally
  // little actual testing, so you'll want to add your own tests here.
  // Feel free to leave your tests in the version of this file you
  // submit, but we will not be running your main function, so the
  // output, etc., of your main doesn't need to match anything from
  // a sample output, etc.
  testLinkedList();
  testQueue();
  testStack();
  return 0;
}

void testLinkedList()
{
  cout << endl;
  cout << "/////////////////////////////////////////////////////////////////"
  << "list test";
  cout << endl;
  SortedListClass testList;
  testList.insertValue(42);
  testList.insertValue(13);
  testList.insertValue(15);
  testList.insertValue(14);
  testList.insertValue(8);
  testList.insertValue(20);
  testList.insertValue(60);
  testList.insertValue(13);
  testList.insertValue(13);

  SortedListClass copylist(testList);
  cout << "#######################" << endl;
  cout << "copy list test" << endl;
  copylist.printForward();

  cout << "#######################" << endl;
  cout << "clear() test" << endl;
  copylist.clear();
  copylist.printBackward();

  cout << "#######################" << endl;
  cout << "removeFront test" << endl;
  SortedListClass copylist1(testList);
  int number = copylist1.getNumElems();
  int val;
  for (int i = 0; i < number; i++)
  {
    copylist1.removeFront(val);
    cout << ".............." << val << endl;
  }
  copylist1.printForward();

  cout << "#######################" << endl;
  cout << "removeLast test" << endl;
  SortedListClass copylist2(testList);
  copylist2.printForward();
  for (int i = 0; i < number; i++)
  {
    copylist2.removeLast(val);
    cout << ".............." << val << endl;
  }
  copylist2.printForward();

  cout << "#######################" << endl;
  cout << "index get val test" << endl;
  SortedListClass copylist3(testList);
  for (int i = 0; i < number; i++)
  {
    copylist3.getElemAtIndex(i, val);
    cout << ".............." << val << endl;
  }
}

void testQueue()
{
  cout << endl;
  cout << "/////////////////////////////////////////////////////////////////"
  << "queue test";
  cout << endl;
  FIFOQueueClass testList;
  testList.enqueue(42);
  testList.enqueue(13);
  testList.enqueue(15);
  testList.enqueue(14);
  testList.enqueue(8);
  testList.enqueue(20);
  testList.enqueue(60);
  testList.enqueue(13);
  testList.enqueue(13);
  int outItem;
  for (int i = 0; i < 9; i++)
  {
    testList.dequeue(outItem);
    testList.print();
  }
  FIFOQueueClass testList1;
  testList1.enqueue(42);
  testList1.enqueue(13);
  testList1.enqueue(15);
  testList1.enqueue(14);
  testList1.enqueue(8);
  testList1.enqueue(20);
  testList1.enqueue(60);
  testList1.enqueue(13);
  testList1.enqueue(13);
  testList1.clear();
  testList1.print();
}

void testStack()
{
  cout << endl;
  cout << "/////////////////////////////////////////////////////////////////"
  << "stack test";
  cout << endl;
  LIFOStackClass testList;
  testList.push(42);
  testList.push(13);
  testList.push(15);
  testList.push(14);
  testList.push(8);
  testList.push(20);
  testList.push(60);
  testList.push(13);
  testList.push(13);
  int outItem;
  for (int i = 0; i < 9; i++)
  {
    testList.pop(outItem);
    testList.print();
  }
  LIFOStackClass testList1;
  testList1.push(42);
  testList1.push(13);
  testList1.push(15);
  testList1.push(14);
  testList1.push(8);
  testList1.push(20);
  testList1.push(60);
  testList1.push(13);
  testList1.push(13);
  testList1.clear();
  testList1.print();
}

#endif