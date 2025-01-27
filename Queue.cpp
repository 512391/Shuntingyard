#include<iostream>
#include"Queue.h"

using namespace std;

void Queue::enqueue(Node* node)
{
  if(Queue::head == nullptr)
    {
      Queue::head = node;
      return;
    }
  
  Node* currentNode = Queue::head;
  while(currentNode->getNext() != nullptr)
    {
      currentNode = currentNode->getNext();
    }

  currentNode->setNext(node);
}

Node* Queue::dequeue()
{
  Node* toReturn = Queue::head;

  Queue::head = toReturn->getNext();

  return toReturn;
}
