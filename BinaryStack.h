#include<iostream>
#include"BinaryNode.h"

class BinaryStack
{
 private:
  BinaryNode* head;
  
 public:
  BinaryStack();
  void print();
  BinaryNode* pop();
  BinaryNode* peek();
  void push(BinaryNode* node);
};
