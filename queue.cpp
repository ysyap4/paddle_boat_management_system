#include "queue.h"
#include <iostream>
using namespace std;


void Queue::createQueue(){
	backPtr = NULL;	
}


void Queue::destroyQueue(){
	nodeQueue *temp = backPtr->next;
	while(temp)
	{
		backPtr->next = temp->next;
		delete temp;
		temp=backPtr->next;
	}
}

bool Queue::isEmpty(){
	return(backPtr==NULL);	
}

void Queue::enQueue(Passenger x){
	nodeQueue *newPtr = new nodeQueue;
	
	newPtr->person=x;
	
	if(isEmpty()){
	newPtr->next =newPtr;
	backPtr= newPtr;
	}
	else{
	newPtr->next = backPtr->next;
	backPtr->next = newPtr;
	backPtr = newPtr;		
	}
	
}


void Queue::deQueue(){
	
	nodeQueue *deletePtr  = new nodeQueue;
	deletePtr = backPtr->next;
	if(deletePtr==backPtr){
		backPtr = NULL;	
		delete deletePtr;
	}
	else{

		backPtr->next = deletePtr->next;
		delete deletePtr;
	}
	
}


Passenger Queue::getFront(){
	if (isEmpty())
	{
		cout << "Sorry,Queue is still empty!" << endl;
	}
	else if(backPtr->next== NULL) return backPtr->person;
	else return backPtr->next->person;
}

Passenger Queue::getRear(){
	if (isEmpty())
	{
		cout << "Sorry,Queue is still empty!" << endl;
	}
	return backPtr->person;
	
}

int Queue::countNode(){
	int num = 1;
	nodeQueue* currNode = backPtr->next;
	if(backPtr==NULL){
		num=0;
	}else{
	while(currNode!= backPtr){
		num++;
		currNode= currNode->next;
		
	}
	}
	
	return num;
	
}
