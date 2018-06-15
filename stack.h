#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "boat.h"
using namespace std;

class NodeStack
{
	public:
		Boat boatStack;
		//int data;
		NodeStack *next;
};

class Stack
{
	private:
		
	public:	
		NodeStack *head;	
		void createStack();
		void push(Boat);
		void pop();
		string stackTop();
		Boat stackTop2();
		bool isEmpty();
};

#endif
