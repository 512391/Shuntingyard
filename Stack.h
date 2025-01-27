#include<iostream>
#include"Node.h"

class Stack
{
 private:
  Node* head;
  
 public:
  Stack();
  void print();
  Node* pop();
  Node* peek();
  void push(Node* node);
};
