#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include<cstring>
#include<map>

using namespace std;

char* infixToPostfix(char* equation, map<char, int> precedence)
{
  int length = 7;

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
	      //stack->print();
	      if(equation[i] == ')')
		{
		  while(stack->peek()->getData() != '(')
		    {
		      postfix[postfixIndex] = stack->pop()->getData();
		      postfixIndex++;
		    }
		  
		   postfix[postfixIndex] = stack->pop()->getData();
		   postfixIndex++;
		}
	      else
		{
	          while(stack->peek() != nullptr && precedence.at(stack->peek()->getData()) >= precedence.at(equation[i]))
		    {
		      postfix[postfixIndex] = stack->pop()->getData();
		      ++postfixIndex;
		    }
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

int main()
{
  map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'(', 4}, {')', 4}};

  char test[17] = {'(','(','2','+','3',')','+','2','*','(','6','/','3',')',')','+','1'};
  char test2[7] = {'1','+','4','*','2','+','2'};
  cout << infixToPostfix(test, precedence);
}
