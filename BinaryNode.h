#ifndef BINARY_H
#define BINARYNODE_H

#include<iostream>

class BinaryNode
{
  private:
  char data;
  BinaryNode* left;
  BinaryNode* right;
  BinaryNode* next;
  
public:
  BinaryNode(char i);
  //sets next for stacks and queues
  void setNext(BinaryNode* node);
  //gets the next in stacks in queues
  BinaryNode* getNext();
  //sets the data
  void setData(char i);
  //gets the data
  char getData();
  //sets the left
  void setLeft(BinaryNode* node);
  //sets the right
  void setRight(BinaryNode* node);
  //gets the left
  BinaryNode* getLeft();
  //gets the right
  BinaryNode* getRight();
};

#endif
