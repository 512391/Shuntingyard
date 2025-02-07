#include<iostream>
#include"Node.h"

/*
  author: jay williamson
  date: 2/5/25
  this is a basic stack it stacks stuff
 */

class Stack
{
 private:
  Node* head;
  
 public:
  Stack();
  //prints the stack
  void print();
  //gets the top of the stack and removes it
  Node* pop();
  //looks at the top of the stack but does not remove it
  Node* peek();
  //pushes a nde onto the stack
  void push(Node* node);
};
