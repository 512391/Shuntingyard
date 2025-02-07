#include<iostream>
#include"BinaryStack.h"

using namespace std;

BinaryStack::BinaryStack()
{
  //sets head to null
  BinaryStack::head = nullptr;
}

void BinaryStack::print()
{
  if(BinaryStack::head == nullptr)
    {
      return;
    }
  BinaryNode* current = BinaryStack::head;

  //prints and gets next until it cant
  while(current->getNext() != nullptr)
    {
      cout << current->getData() << endl;
      current = current->getNext();
    }
  cout << current->getData() << endl;
}

BinaryNode* BinaryStack::pop()
{
  if(BinaryStack::head == nullptr)
    {
       return nullptr;
    }
  
  BinaryNode* toReturn = BinaryStack::head;

  //sets new head
  if(BinaryStack::head->getNext() == nullptr)
    {
      BinaryStack::head = nullptr;
    }
  else
    {
      BinaryStack::head = toReturn->getNext();
    }

  //returns old head
  return toReturn;
}

BinaryNode* BinaryStack::peek()
{
  if(BinaryStack::head == nullptr)
    {
      return nullptr;
    }

  //returns head
  return BinaryStack::head;
}


void BinaryStack::push(BinaryNode* node)
{
  //pushes if not null
  if(BinaryStack::head != nullptr)
    {
      node->setNext(BinaryStack::head);
    }
  //sets it to head if nothing in stack
  BinaryStack::head = node;
}
