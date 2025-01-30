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

BinaryNode* createExpressionTree(char* postfix, int length)
{
  cout << "creating ex tree\n";
  
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

	  cout << bn->getLeft()->getData() << ", " <<bn->getLeft()->getData();
	  
	  stack->push(bn);
	}
    }

  return stack->pop();
}

void goDownLeft(BinaryNode* head)
{
  if(head->getLeft() != nullptr)
    {
      cout << head->getLeft()->getData();
      goDownLeft(head->getLeft());

      if(head->getRight() != nullptr)
        {
          cout << head->getRight()->getData();
        }
    }
  else
    {
      return;
    }
}

void goDownRight(BinaryNode* head)
{
  if(head->getRight() != nullptr)
    {
      cout << head->getRight()->getData();
      goDownLeft(head->getRight());
      if(head->getLeft() != nullptr)
        {
          cout << head->getLeft()->getData();
        }
    }
  else
    {
      return;
    }
}


void printPrefix(BinaryNode* head)
{
  cout << head->getData();
  goDownLeft(head);
  goDownLeft(head->getLeft());
}

void printPostfix(BinaryNode* head)
{
}

void printInfix(BinaryNode* head)
{
}

int main()
{
  map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'(', 0}, {')', 0}};

  char test[17] = {'(','(','5','+','2',')','+','2','*','(','6','/','3',')',')','+','1'};
  char test2[7] = {'1','+','4','*','2','+','2'};
  printPrefix(createExpressionTree(infixToPostfix(test, precedence, 17), 17));
}
