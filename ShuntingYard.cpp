#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include<cstring>
#include<cmath>
#include<map>
#include"BinaryStack.h"
using namespace std;

/*
  author jay williamson
  date 2/5/25
  this class converts expressions to infix prefix and postfix and can evaluate them
 */

//this converts the origional infix to postfix
char* infixToPostfix(char* equation, map<char, int> precedence, int size)
{
  int length = size;

  char* postfix = new char[length];
  Stack* stack = new Stack();
  Queue* queue = new Queue();
  
  int postfixIndex = 0;

  //goes through all of the equation
  for(int i = 0; i < length; i++)
    {
      //checs if it is an operand if so it us puts it in the answer queue
       if((int)equation[i]>47 &&(int)equation[i]<58)
	{
	  queue->enqueue(new Node(equation[i]));
	}
      else
	{
	  //checks that there is somethin in th stack
	  if(stack->peek() != nullptr)
	    {
	      //checks if it is a closing parentheses
	      if(equation[i] == ')')
		{
		  //if it is a closing parenth then it goes to the nearest opening parentheses
		  while(stack->peek()->getData() != '(')
		    {
		      //puts everything between the parentheses in the answer queue
		      queue->enqueue(new Node(stack->pop()->getData()));
		    }
		  stack->pop();
		}//checks if it is not a parentheses
	      else if(equation[i] != '(')
		{
		  //pops everthing that is above the current opeators precedence into the answer queue then pushes this operator onto the stack
	          while(stack->peek() != nullptr && precedence.at(stack->peek()->getData()) >= precedence.at(equation[i]))
		    {
		      queue->enqueue(new Node(stack->pop()->getData()));
		    }
		  stack->push(new Node(equation[i]));
		}
	      else
		{
		  //pushes open pareth into stack
		  stack->push(new Node(equation[i]));

		}
      	    }
	  else
	    {
	      //if nothing is in the stack it pushes the operator in
	      stack->push(new Node(equation[i]));
	    }
	}
    }

  Node* current = stack->peek();
  //this just clears the stack at the end
  while(current->getNext() != nullptr)
    {
      queue->enqueue(new Node(current->getData()));
       
      current = current->getNext();
    }
  
  queue->enqueue(new Node(current->getData()));

  //converts the answer stack into the char array answer
  while(queue->hasHead())
    {
      postfix[postfixIndex] = queue->dequeue()->getData();
      ++postfixIndex;
    }

  //cleans up
  delete stack;
  delete queue;
  
  return postfix;
}

//this creates an expression tree based on the postfix
BinaryNode* createExpressionTree(char* postfix)
{
  int length = strlen(postfix);
  
  BinaryStack* stack = new BinaryStack();

  //goes through the postfix
  for(int i = 0; i < length; i++)
    {
      //pushes operands onto the stack
      if((int)postfix[i]>47 &&(int)postfix[i]<58)
	{
	  stack->push(new BinaryNode(postfix[i]));
	}
      else
	{
	  //otherwise it just pops 2 things off the stac and attaces them to the operator
	  BinaryNode* bn = new BinaryNode(postfix[i]);
	  
	  bn->setRight(stack->pop());
	  bn->setLeft(stack->pop());

	  //pushes the operator back onto the stack
	  stack->push(bn);
	}
    }

  return stack->pop();
}

//this very confusingly prints the expression tree line by line
void printExpressionTree(int amountOfNodes, BinaryNode** nodes)
{
  BinaryNode** newNodes = new BinaryNode*[amountOfNodes*2];
  int newArraySize = 0;

  if(nodes[0] == NULL)
    {
      return;
    }

  //goes through all the nodes
  for(int i = 0; i< amountOfNodes; i++)
    {
      //prints the data in the current row and makes the next row
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

  //prints the next line of the tree
  printExpressionTree(newArraySize, newNodes);
    
}

//this prints the prefix based on the tree
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

//this prints the postfix based on the tree
void printPostfix(BinaryNode* head)
{
  if(head == nullptr) {
        return;
    }
  printPostfix(head->getLeft());
    printPostfix(head->getRight());
    cout << head->getData();
}

//this prints the infix based on the tree
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
//this deals with the input
void getInput()
{
  //this section gets an expression based on your input
  cout << "enter expression: ";
  char* input = new char[100];
  cin >> input;
  
  char* editedInput = new char[100];

  int len = strlen(input);

  int currentIndex = 0;
  //this removes spaces
  for(int i =0; i < len;i++)
    {
      if(input[i] != ' ')
	{
	  editedInput[currentIndex]=input[i];
	  ++currentIndex;
	}
    }

  int length = strlen(editedInput);

  //map of how important the operatrs are PEDMAS
  map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'(', 0}, {')', 0}};
  
  cout << endl;
  //makes the expression tree
  BinaryNode* node = createExpressionTree(infixToPostfix(editedInput, precedence, length));

  cout << "press 1 for infix, 2 for postfix, 3 for prefix, 4 for all\n";
  char in;
  cin>>in;

  //does whatever based on the input
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
      cout << "infix: ";
      printInfix(node);
      cout << endl;
      cout << "postfix: ";
      printPostfix(node);
      cout<<endl;
      cout << "prefix: ";
      printPrefix(node);
      cout << endl;
    }

  delete input;
  delete editedInput;
  
  //gets the input again
  getInput();
}

int main()
{
  //gets input
  getInput();
}
