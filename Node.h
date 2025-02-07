#ifndef NODE_H_NAME
#define NODE_H_NAME

#include<iostream>

class Node
{
 private:
  char data;
  //next in linked list
  Node* next;
 public:
  Node(char data);
  //returns the data
  char getData();
  //returns the next node
  Node* getNext();
  //sets the next node
  void setNext(Node* node);
};

#endif
