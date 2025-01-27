#include<iostream>
#include"Stack.h"

using namespace std;

Node* Stack::pop()
{
  if(Stack::head == nullptr)
    {
      cout << "empty stack" << endl;
      return nullptr;
    }
  
  Node* toReturn = Stack::head;

  Stack::head = toReturn->getNext();
  
  return toReturn;
}

Node* Stack::peek()
{
  if(Stack::head == nullptr)
    {
      cout << "empty stack" << endl;
      return nullptr;
    }
  
  return Stack::head;
}

void Stack::push(Node* node)
{
  if(Stack::head != nullptr)
    {
      node->setNext(Stack::head);
    }
  Stack::head = node;
}
