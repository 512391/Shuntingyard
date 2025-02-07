#include<iostream>
#include"Node.h"


Node::Node(char data)
{
  Node::data = data;
  Node::next = nullptr;
}

char Node::getData()
{
  //returns the data
  return Node::data;
}

Node* Node::getNext()
{
  //returns the next
  return Node::next;
}

void Node::setNext(Node* node)
{
  //sets the next based on the paramx
  Node::next = node;
}
