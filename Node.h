#ifndef NODE_H_NAME
#define NODE_H_NAME

#include<iostream>

class Node
{
 private:
  char data;
  Node* next;
 public:
  Node(char data);
  char getData();
  Node* getNext();
  void setNext(Node* node);
};

#endif
