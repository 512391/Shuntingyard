#include<iostream>
#include"Queue.h"

using namespace std;

Queue::Queue()
{
  //just sets the head to null
  Queue::head = nullptr;
}

void Queue::enqueue(Node* node)
{
  //checs if the head is null
  if(Queue::head == nullptr)
    {
      //if so just make it the head
      Queue::head = node;
      return;
    }
  
  Node* currentNode = Queue::head;
  //goes to the end on the queue
  while(currentNode->getNext() != nullptr)
    {
      //gets the node at the end
      currentNode = currentNode->getNext();
    }

  //enqueues the node
  currentNode->setNext(node);
}

Node* Queue::dequeue()
{
  Node* toReturn = Queue::head;

  //sets the new head
  if(toReturn->getNext() != nullptr)
    {
      Queue::head = toReturn->getNext();
    }
  else
    {
      Queue::head = nullptr;
    }
  return toReturn;
}

bool Queue::hasHead()
{
  //checks if the head is null
  if(Queue::head != nullptr)
    {
      return true;
    }
  return false;
}
