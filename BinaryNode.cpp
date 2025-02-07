#include<iostream>
#include"BinaryNode.h"

BinaryNode::BinaryNode(char i)
{
  //sets data in constructot
  BinaryNode::data = i;
}

void BinaryNode::setNext(BinaryNode* node)
{
  //sets the next
  BinaryNode::next = node;
}

BinaryNode* BinaryNode::getNext()
{
  //returns the next
  return BinaryNode::next;
}

void BinaryNode::setData(char i)
{
  //sets the data
  BinaryNode::data = i;
}
char BinaryNode::getData()
{
  //returns the data
  return BinaryNode::data;
}
void BinaryNode::setLeft(BinaryNode* node)
{
  //sets the left
  BinaryNode::left = node;
}
void BinaryNode::setRight(BinaryNode* node)
{
  //sets the right
  BinaryNode::right = node;
}
BinaryNode* BinaryNode::getRight()
{
  //gets the right
  return BinaryNode::right;
}
BinaryNode* BinaryNode::getLeft()
{
  //gets the left
  return BinaryNode::left;
}

