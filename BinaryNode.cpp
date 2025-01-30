#include<iostream>
#include"BinaryNode.h"

BinaryNode::BinaryNode(char i)
{
  BinaryNode::data = i;
}

void BinaryNode::setNext(BinaryNode* node)
{
  BinaryNode::next = node;
}

BinaryNode* BinaryNode::getNext()
{
  return BinaryNode::next;
}

void BinaryNode::setData(char i)
{
  BinaryNode::data = i;
}
char BinaryNode::getData()
{
  return BinaryNode::data;
}
void BinaryNode::setLeft(BinaryNode* node)
{
  BinaryNode::left = node;
}
void BinaryNode::setRight(BinaryNode* node)
{
  BinaryNode::right = node;
}
BinaryNode* BinaryNode::getLeft()
{
  return BinaryNode::right;
}
BinaryNode* BinaryNode::getRight()
{
  return BinaryNode::left;
}

