#include<iostream>
#include"BinaryStack.h"

using namespace std;

BinaryStack::BinaryStack()
{
  BinaryStack::head = nullptr;
}

void BinaryStack::print()
{
  if(BinaryStack::head == nullptr)
    {
      return;
    }
  BinaryNode* current = BinaryStack::head;
  
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
      cout << "empty stack" << endl;
      return nullptr;
    }
  
  BinaryNode* toReturn = BinaryStack::head;

  if(BinaryStack::head->getNext() == nullptr)
    {
      BinaryStack::head = nullptr;
    }
  else
    {
      BinaryStack::head = toReturn->getNext();
    }
  
  return toReturn;
}

BinaryNode* BinaryStack::peek()
{
  if(BinaryStack::head == nullptr)
    {
      cout << "empty stack" << endl;
      return nullptr;
    }
  
  return BinaryStack::head;
}

void BinaryStack::push(BinaryNode* node)
{
  if(BinaryStack::head != nullptr)
    {
      node->setNext(BinaryStack::head);
    }
  BinaryStack::head = node;
}
