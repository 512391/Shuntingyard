#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include<cstring>
#include<cmath>
#include<map>
#include"BinaryStack.h"
using namespace std;

char* infixToPostfix(char* equation, map<char, int> precedence, int size)
{
  int length = size;

  cout << length << endl;
  
  char* postfix = new char[length];
  Stack* stack = new Stack();

  int postfixIndex = 0;
  
  for(int i = 0; i < length; i++)
    {
      cout << postfix <<endl;
      if((int)equation[i]>47 &&(int)equation[i]<58)
	{
	  postfix[postfixIndex] = equation[i];
	  ++postfixIndex;
	}
      else
	{
	  if(stack->peek() != nullptr)
	    {
	      cout<<"in stack" << endl;
	      
	      if(equation[i] == ')')
		{
		  while(stack->peek()->getData() != '(')
		    {
		      postfix[postfixIndex] = stack->pop()->getData();
		      postfixIndex++;
		    }
		  stack->pop();
		}
	      else if(equation[i] != '(')
		{
	          while(stack->peek() != nullptr && precedence.at(stack->peek()->getData()) >= precedence.at(equation[i]))
		    {
		      postfix[postfixIndex] = stack->pop()->getData();
		      ++postfixIndex;
		    }
		  stack->push(new Node(equation[i]));
		}
	      else
		{
		  cout << "adding to stack \n";

		  stack->push(new Node(equation[i]));

		}
      	    }
	  else
	    {
	      cout << "adding to stack \n";
	      
	      stack->push(new Node(equation[i]));
	    }
	}
    }

  Node* current = stack->peek();
  while(current->getNext() != nullptr)
    {
      postfix[postfixIndex] = current->getData();
      postfixIndex++;
       
      current = current->getNext();
    }
  
  postfix[postfixIndex] = current->getData();
    
  delete stack;
  
  return postfix;
}

int evaluatePostfix(char* equation, int length)
{
  Stack* numberStack = new Stack();

  cout << equation << endl;
  for(int i = 0; i < length; i++)
    {
      if((int)equation[i]>47 &&(int)equation[i]<58)
        {
          numberStack->push(new Node(equation[i]));
        }
      else if(equation[i] != NULL)
	{
	  int number = 0;

	  int second = (int)(numberStack->pop()->getData()-48);
      int first = (int)(numberStack->pop()->getData()-48);
      
	  if(equation[i] == '+')
	    {
	      number = first + second;
	    }
	  if(equation[i] == '-')
            {
              number = first - second;
            }
          if(equation[i] == '*')
            {
              number = first * second;
            }
          if(equation[i] == '/')
            {
              number = first / second;
            }
          if(equation[i] == '^')
            {
              number = pow(first, second);
            }

	  cout << first;
	  cout << equation[i];
	  cout << second << "=";
	  cout << number << endl;

	  numberStack->push(new Node((char)(number+48)));
	}
    }
  
      return (int)numberStack->pop()->getData()-48;
}

BinaryNode* createExpressionTree(char* postfix)
{
  cout << "creating ex tree\n";

  int length = strlen(postfix);
  
  BinaryStack* stack = new BinaryStack();

  for(int i = 0; i < length; i++)
    {
      if((int)postfix[i]>47 &&(int)postfix[i]<58)
	{
	  stack->push(new BinaryNode(postfix[i]));
	}
      else
	{
	  BinaryNode* bn = new BinaryNode(postfix[i]);
	  cout << "evaling: ";
	  bn->setLeft(stack->pop());
	  bn->setRight(stack->pop());

	  cout << bn->getLeft()->getData() << ", " <<bn->getRight()->getData();
	  
	  stack->push(bn);
	}
    }

  return stack->pop();
}

void printExpressionTree(int amountOfNodes, BinaryNode** nodes)
{
  BinaryNode** newNodes = new BinaryNode*[amountOfNodes*2];
  int newArraySize = 0;

  if(nodes[0] == NULL)
    {
      return;
    }

  for(int i = 0; i< amountOfNodes; i++)
    {
      cout << nodes[i]->getData() << " ";
       if(nodes[i]->getLeft() != nullptr)
            {
       newNodes[newArraySize] = nodes[i]->getLeft();
       newArraySize++;
	    }
        if(nodes[i]->getRight() != nullptr)
            {
       newNodes[newArraySize] = nodes[i]->getRight();
       newArraySize++;
	    }
     
    }
  cout << endl;

  
  printExpressionTree(newArraySize, newNodes);
    
}

void printPrefix(BinaryNode* head)
{
  if(head == nullptr)
    {
      return;
    }
  cout << head->getData();
  printPrefix(head->getLeft());
  printPrefix(head->getRight());
}

void printPostfix(BinaryNode* head)
{
  if(head == nullptr) {
        return;
    }
  printPostfix(head->getLeft());
    printPostfix(head->getRight());
    cout << head->getData();
}

void printInfix(BinaryNode* head)
{
  if(head == nullptr)
    {
      return;
    }
  printInfix(head->getLeft());
  cout << head->getData();
  printInfix(head->getRight());
}

void getInput()
{
  cout << "enter expression: ";
  char* input = new char[40];
  cin>>input;
  
  char* editedInput = new char[40];

  int len = strlen(input);
  
  int currentIndex = 0;
  for(int i =0; i < len;i++)
    {
      if(input[i]!=' ')
	{
	  editedInput[currentIndex]=input[i];
	  currentIndex++;
	}
    }

  int length = strlen(editedInput);
  
  map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'(', 0}, {')', 0}};
  
  cout << endl;
  BinaryNode* node = createExpressionTree(infixToPostfix(editedInput, precedence, length));

  cout << "press 1 for infix, 2 for postfix, 3 for prefix, 4 for all";
  char in;
  cin>>in;

  if(in == '1')
    {
      printInfix(node);
      cout <<endl;
    }
  else if(in == '2')
    {
      printPostfix(node);
      cout << endl;
    }
  else if(in == '3')
    {
      printPrefix(node);
      cout << endl;
    }
  else if(in == '4')
    {
      printInfix(node);
      cout << endl;
      printPostfix(node);
      cout<<endl;
      printPrefix(node);
      cout << endl;
    }
  getInput();
}

int main()
{
  getInput();
}
