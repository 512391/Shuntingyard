#include<iostream>
#include"Stack.h"

using namespace std;

Stack::Stack()
{
  Stack::head = nullptr;
}

void Stack::print()
{
  if(Stack::head == nullptr)
    {
      return;
    }
  Node* current = Stack::head;
  
  while(current->getNext() != nullptr)
    {
      cout << current->getData() << endl;
    }
  cout << current->getData() << endl;
}

Node* Stack::pop()
{
  if(Stack::head == nullptr)
    {
      cout << "empty stack" << endl;
      return nullptr;
    }
  
  Node* toReturn = Stack::head;

  if(Stack::head->getNext() == nullptr)
    {
      Stack::head = nullptr;
    }
  else
    {
      Stack::head = toReturn->getNext();
    }
  
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
