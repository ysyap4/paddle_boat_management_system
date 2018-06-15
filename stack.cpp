#include "stack.h"
#include <iostream>
using namespace std;


void Stack::createStack()
{
	head = NULL;
}

bool Stack::isEmpty()
{
	return (head==NULL);
}

void Stack::push(Boat newItem)
{
	NodeStack *newNode;
	newNode = new (NodeStack);
	
	if (newNode == NULL)
	{
		cout << "cannot allocate memory." << endl;
	}
	else
	{
		newNode->boatStack = newItem;
		newNode->next = head;
		head = newNode;
	}
}

void Stack::pop()
{
	NodeStack *deleteNode;
	
	if (isEmpty())
	{
		cout << "Sorry, Cannot pop item from stack. Stack is still empty!" << endl;
	}
	else
	{
		deleteNode = head;
		//cout << "Item to be popped from stack is: " << stackTop() << endl;
		
		head = deleteNode->next;
		delete (deleteNode);
	}
}

string Stack::stackTop()
{
	if (isEmpty())
	{
		cout << "Sorry,Stack is still empty!" << endl;
	}
	else
	{
		return head->boatStack.getBoatName();	
	}

}

Boat Stack::stackTop2()
{
	if (isEmpty())
	{
		cout << "Sorry,Stack is still empty!" << endl;
	}
	else
	{
		return head->boatStack;	
	}

}


