#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "passenger.h"
using namespace std;

struct nodeQueue{
	Passenger person;
	nodeQueue *next;
};

class Queue
{
	
	public:
		nodeQueue *backPtr;
		void createQueue();
		void destroyQueue();
		bool isEmpty();
		void enQueue(Passenger);
		void deQueue();
		Passenger getFront();
		Passenger getRear();
		int countNode();
	
	
};

#endif
