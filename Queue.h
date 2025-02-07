#ifndef QUEUE_H_NAME
#define QUEUE_H_NAME

#include<iostream>
#include"Node.h"

/*
  author: jay williamson
  date: 2/5/25
  this is a basic queue itd oes its thing
 */

class Queue
{
 public:
  Queue();
  //puts something in the queue
  void enqueue(Node* node);
  //gets something from the queue
  Node* dequeue();
  //checks if it has anything in it
  bool hasHead();
  
 private:
  Node* head;
};

#endif
