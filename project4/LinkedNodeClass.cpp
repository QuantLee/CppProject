#include "LinkedNodeClass.h"

// The ONLY constructor for the linked node class - it takes in the newly
// created node's previous pointer, value, and next pointer, and assigns
// them. Input: Address of node that comes before this one, Value to be
// contained in this node, Address of node that comes after this one.
LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev, const int &inVal,
  LinkedNodeClass *inNext)
{
  prevNode = inPrev;
  nextNode = inNext;
  nodeVal = inVal;
}

// Returns the value stored within this node.
int LinkedNodeClass::getValue() const
{
  return nodeVal;
}

// Returns the address of the node that follows this node.
LinkedNodeClass* LinkedNodeClass::getNext() const
{
  return nextNode;
}

// Returns the address of the node that comes before this node.
LinkedNodeClass* LinkedNodeClass::getPrev() const
{
  return prevNode;
}

// Sets the object’s next node pointer to NULL.
void LinkedNodeClass::setNextPointerToNull()
{
  nextNode = 0;
}

// Sets the object's previous node pointer to NULL.
void LinkedNodeClass::setPreviousPointerToNull()
{
  prevNode = 0;
}

// This function DOES NOT modify "this" node. Instead, it uses the pointers
// contained within this node to change the previous and next nodes so that
// they point to this node appropriately. In other words, if "this" node is
// set up such that its prevNode pointer points to a node (call it "A"),
// and "this" node's nextNode pointer points to a node (call it "B"), then
// calling setBeforeAndAfterPointers results in the node we're calling "A"
// to be updated so its "nextNode" points to "this" node, and the node we're
// calling "B" is updated so its "prevNode" points to "this" node, but
// "this" node itself remains unchanged.
void LinkedNodeClass::setBeforeAndAfterPointers()
{
  if (prevNode != 0)
  {
    prevNode -> nextNode = this;
  }
  if (nextNode != 0)
  {
    nextNode -> prevNode = this;
  }
}












