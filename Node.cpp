#include<iostream>
#include"Node.h"


Node::Node(char data)
{
  Node::data = data;
  Node::next = nullptr;
}

char Node::getData()
{
  return Node::data;
}

Node* Node::getNext()
{
  return Node::next;
}

void Node::setNext(Node* node)
{
  Node::next = node;
}
