#include<iostream>
#include"BinaryNode.h"

/*
  author: jay williamson
  date: 2/5/25
  this is a stack of binary ndes it just stacks nodes
 */

class BinaryStack
{
 private:
  BinaryNode* head;
  
 public:
  BinaryStack();
  //prints the nodes
  void print();
  //removes and returns top node
  BinaryNode* pop();
  //return top node doesnt remove
  BinaryNode* peek();
  //pushes a node onto the stack
  void push(BinaryNode* node);
};
