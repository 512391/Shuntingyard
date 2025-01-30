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
  void setNext(BinaryNode* node);
  BinaryNode* getNext();
  void setData(char i);
  char getData();
  void setLeft(BinaryNode* node);
  void setRight(BinaryNode* node);
  BinaryNode* getLeft();
  BinaryNode* getRight();
};

#endif
