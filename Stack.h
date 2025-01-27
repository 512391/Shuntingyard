#include<iostream>
#include"Node.h"

class Stack
{
 private:
  Node* head;
  
 public:
  Node* pop();
  Node* peek();
  void push(Node* node);
};
