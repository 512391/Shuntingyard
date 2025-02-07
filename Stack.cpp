#include<iostream>
#include"Stack.h"

using namespace std;

Stack::Stack()
{
  //sets head to null
  Stack::head = nullptr;
}

void Stack::print()
{
  if(Stack::head == nullptr)
    {
      return;
    }
  Node* current = Stack::head;

  //gets the next node and prints it until it cant
  while(current->getNext() != nullptr)
    {
      cout << current->getData() << endl;
      current = current->getNext();
    }
  cout << current->getData() << endl;
}

Node* Stack::pop()
{
  if(Stack::head == nullptr)
    {
      return nullptr;
    }
  
  Node* toReturn = Stack::head;

  //sets new head
  if(Stack::head->getNext() == nullptr)
    {
      Stack::head = nullptr;
    }
  else
    {
      Stack::head = toReturn->getNext();
    }

  //return old head
  return toReturn;
}

Node* Stack::peek()
{
  if(Stack::head == nullptr)
    {
      return nullptr;
    }

  //just gets the head if not null
  return Stack::head;
}

void Stack::push(Node* node)
{
  //puts node onto the top of the stack
  if(Stack::head != nullptr)
    {
      node->setNext(Stack::head);
    }
  Stack::head = node;
}
