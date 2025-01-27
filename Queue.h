#ifndef QUEUE_H_NAME
#define QUEUE_H_NAME

#include<iostream>
#include"Node.h"

class Queue
{
 public:
  void enqueue(Node* node);
  Node* dequeue();
  
 private:
  Node* head;
};

#endif
