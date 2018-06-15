#include "stack.h"
#include "queue.h"
#include "boat.h"
#include "display.h"
#include "sort.h"
#include "search.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;


//declare early
//void quickSort(int T[], string U[], int V[], int first ,int last);
//int partition(int T[], string U[], int V[], int first, int last);
int binary_search(int search_key, int array_size, const int array []);
void enterSystem();
string determineBoatType(int type);
void sortBoatName();
void sortBoatType();


//view the boat in a list
void viewList(){
	
	ifstream Fin;
	string name;
	int id;
	char type;
	Fin.open("boatList.dat");
	
	cout << setw(26) << "List of Paddle Boat" << endl;
	cout << setw(6) << "ID"
		<< setw(12) << "Name"
		<< setw(10) << "Type"
		<< endl;
	
	while(!Fin.eof())
	{
	type = Fin.peek();
	Fin >> id >> name;
	Fin.ignore(100, '\n');
	
	if(Fin){
		cout << setw(6) << id 
			<< setw(12) << name
			<< setw(15);
			cout << determineBoatType(type-48)
			<< endl;
	}
	
	}
	
	cout << endl;
	

	
	
	Fin.close();
}

//load boat list
void load_boat(Stack *T1, Stack *T2, Stack *T3)
{
	T1->createStack();
	T2->createStack();
	T3->createStack();
	
	ifstream Fin;
	string name;
	int id;
	int type;
	Fin.open("boatList.dat");
	
	Boat* boatTemp;
	//delete boatTemp; 
	
	while(!Fin.eof())
	{
	Fin >> id >> name;
	type = id /100; // derived boat type from id;
	Fin.ignore(100, '\n');
	
	if(Fin){
		boatTemp = new Boat(name, id, type);
		if (type==2) T1->push(*boatTemp);
		else if (type==4) T2->push(*boatTemp);
		else if (type==6) T3->push(*boatTemp);
		delete boatTemp;
	}
	
	}
	
}

void enterSystem()
{
	cout << endl;
	cout << "Welcome to ATLAS RIVER sports club!" << endl;
	cout << "This is the ATLAS RIVER paddle boat system." << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;
	cout << "Enter the number to perform the management task (1-8): " << endl;
	cout << "1. View the paddle boat list (unsorted)" << endl;
	cout << "2. Sort the paddle boat" << endl;
	cout << "3. Search the paddle boat" << endl;
	cout << "4. View the dock status (stack)" << endl;
	cout << "5. View the renter queue (queue)" << endl;
	cout << "6. Rent a paddle boat" << endl;
	cout << "7. Return a paddle boat" << endl;
	cout << "8. Clear paddle boat stack for maintenance" << endl;
	cout << "0. Exit" << endl;
	cout << "Task: ";
}

int determineBoat(int num){
	
	int type;
	if (num<=2) type=2;
		else if (num<=4) type=4;
		else if (num>4) type=6
		;
return type;
}

int determineDuration(){
	
	int x;
	bool status=false;
	while(status==false){
	
	cout << "|The time of renting:                           |" << endl
			<< "|1. 15 minutes                                  |" << endl
			<< "|2. 30 minutes                                  |" << endl
			<< "|3. 45 minutes                                  |" << endl
			<< "|4. 60 minutes                                  |" << endl;
	cout << "|Enter the option (1-4): ";
		cin >> x;
		
		if(x>0 && x<5) 
			status=true;
	 	if(status==false)
	 	{
	 		cout << "|Invalid option. Try again.                     |" << endl;
	 		cout << "|                                               |" << endl;
		}
	}
	
	if(x== 1) return 15;
	else if(x== 2) return 30;
	else if(x==3) return 45;
	else if(x==4) return 60;
}

float determinePrice(int duration, int type){
	
	float tPrice, dPrice;
	
	if(type== 2) tPrice=1;
	else if(type== 4) tPrice=2;
	else if(type==6) tPrice=3;

	if(duration== 15) dPrice=5.00;
	else if(duration== 30) dPrice=9.00;
	else if(duration==45) dPrice=12.00;
	else if(duration==60) dPrice=15.00;
	
	return tPrice*dPrice;
}



int rentBoat(Queue *Q1, Queue *Q2, Queue *Q3, Queue *Q4)
{
	int passengerNum, boatType, duration;
	float price;
	char durationC;
	Passenger *queueTemp;
	string passengerName, passengerPhone;
	
	
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|            Paddle Boat Rental Form            |" << endl;
	cout << "|                                               |" << endl;
	cout << "|Enter the following details.                   |" << endl;
	cout << "|                                               |" << endl;
	cout << "|The number of passenger: ";
	cin >> passengerNum;
	boatType = determineBoat(passengerNum);
	cout << "|                                               |" << endl;
	cout << "|The system has chosen the boat type:           |" << endl;
	cout << "|" << determineBoatType(boatType) << endl;
	cout << "|                                               |" << endl;
	cout << "|The renter's name: ";
	cin >> passengerName;
	cout << "|                                               |" << endl;
	cout << "|The renter's phone number: ";
	cin >> passengerPhone;
	cout << "|                                               |" << endl;
	duration = determineDuration();
	price = determinePrice(duration, boatType);
	queueTemp = new Passenger(passengerName, passengerPhone, duration, boatType, passengerNum, price);
	if(boatType==2)	Q1->enQueue(*queueTemp);
	else if(boatType==4) Q2->enQueue(*queueTemp);
	else if(boatType==6) Q3->enQueue(*queueTemp);
	Q4->enQueue(*queueTemp);
	delete queueTemp;
	
	cout << "|                                               |" << endl;
	cout << "|The request has been sucessfully entered the   |" << endl;
	cout << "|queue.                                         |" << endl;
	cout << "-------------------------------------------------" << endl;
	
	system("pause");
	system("cls");
	return boatType;
}

boatOut(int boatType,Stack* couple, Stack* family,Stack* familyDeluxe, Queue *Q1, Queue *Q2, Queue *Q3 ){
	
	if(boatType==2){
		if(!couple->isEmpty())
		{
			Q1->deQueue();
			couple->pop();
		}else {
			
			cout << "Couple boat"; 
		}
		}
		
	
	else if(boatType==4) {
		if(!family->isEmpty()){
			Q2->deQueue();
			family->pop();
		} else {
			
			cout << "Family boat"; 
		}
	}
	else if(boatType==6) {
		if(!familyDeluxe->isEmpty())
		{	Q3->deQueue();
			familyDeluxe->pop();
		} else{
			
			cout << "Family Deluxe boat"; 
		}
	}
	
	if(!(boatType!=2||boatType!=4||boatType!=6))
	cout << " is currently not available." << endl
		<< "You will be notify once your boat is ready." << endl;
	else cout << "Your boat is ready. Please proceed to the dock."<< endl;
	system("pause");
}

bool compareStack(Stack boat, string name){
	
	Stack sTemp;
	sTemp.createStack();
	Boat* boatTemp;
	bool status=true;

	
	if(boat.isEmpty()){
		return true;
	}
	
	while(!boat.isEmpty())
	{
	
	string boatName = boat.stackTop2().getBoatName();
	int boatID = boat.stackTop2().getBoatID();	
	int boatType = boat.stackTop2().getBoatType();
	boatTemp = new Boat(boatName, boatID, boatType);
	sTemp.push (*boatTemp);
	delete boatTemp;
	boat.pop();
	if(name==boatName){
		status=false;
		cout << "The Boat already in the stack" << endl;
	}
	}
	
	while(!sTemp.isEmpty())
	{
	string boatName = sTemp.stackTop2().getBoatName();
	int boatID = sTemp.stackTop2().getBoatID();	
	int boatType = sTemp.stackTop2().getBoatType();
	boatTemp = new Boat(boatName, boatID, boatType);
	boat.push (sTemp.stackTop2());
	delete boatTemp;
	sTemp.pop();
	
	}
	return status;
}
void boatIn(Stack* couple, Stack* family, Stack* familyDeluxe, Queue* customer){
		
		viewList();	
		string name, customerName;
		int passengerNum, duration;
		float price;
		bool status;
		Boat *tempBoat = new Boat;
		*tempBoat=searchForPush();
		name=tempBoat->getBoatName();
		int type = tempBoat->getBoatType();
		if(type==2){
			if(compareStack(*couple, name))	{
			couple->push(*tempBoat);
			status=true;
			}
		}
		else if (type==4){
			if(compareStack(*family, name)){
			status=true;
			family->push(*tempBoat);
			}
		}
		else if (type==6){
			if(compareStack(*familyDeluxe, name))
			{
				status=true;
			familyDeluxe->push(*tempBoat);
			}
		}
		delete tempBoat;
		
		if(status){
	
		passengerNum=customer->getFront().getPassengerNum();
		customerName=customer->getFront().getPassengerName();
		duration=customer->getFront().getDuration();
		price = determinePrice(duration, type);
		type = determineBoat(passengerNum);
		
			cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|           ATLAS RIVER SPORTS CLUB             |" << endl;
	cout << "|          Paddle Boat Rental Receipt           |" << endl;
	cout << "|-----------------------------------------------|" << endl;
	cout << "|                                               |" << endl;
	cout << "|  Details:                                     |" << endl;
	cout << "|                                               |" << endl;
	cout << "|  The number of passenger:                     |" << endl;
	cout << "|	" << passengerNum  << endl;
	cout << "|                                               |" << endl;
	cout << "|  The boat type:                               |" << endl;
	cout << "|	" << determineBoatType(type)  << endl;
	cout << "|                                               |" << endl;
	cout << "|  The renter's name:                           |" << endl;
	cout << "|	"  << customerName<< endl;
	cout << "|                                               |" << endl;
	cout << "|  The renter's phone number:                   |" << endl;
	cout << "|	"  << customer->getFront().getPassengerPhone()  << endl;
	cout << "|                                               |" << endl;
	cout << "|  Duration:                                    |" << endl;
	cout << "|  " << duration << " minutes"  << endl;
	cout << "|                                               |" << endl;
	cout << "|  Total Payment:                               |" << endl;
	cout << "|    RM "  << price  << endl;
	cout << "|                                               |" << endl;
	cout << "|  Thank you.                                   |" << endl;
	cout << "|  Please come again.                           |" << endl;
	cout << "-------------------------------------------------" << endl;
	
	customer->deQueue();
		}
}
int main()
{
	Stack couple, family, familyDeluxe; //linked list stack
	Display one;
	load_boat(&couple, &family, &familyDeluxe);
	Queue renter1, renter2, renter3, serveQueue; //linked list circular queue
	renter1.createQueue();
	renter2.createQueue();
	renter3.createQueue();
	serveQueue.createQueue();
	bool boatStatus=false;
	int systemC=99, task, boatType=0;

	
	while(systemC==99)
	{
		//one.printPattern3(&couple);
		enterSystem();
		cin >> systemC;
	
		while (systemC!=1 && systemC!=2 && systemC!=3 && systemC!=4 && systemC!=5 && systemC!=6 && systemC!=7 && systemC!=8 && systemC!=0)
		{
			cout << endl;
			cout << "What? Adele's hello from the other side, she can't recognise the task number you entered." << endl;
			cout << "Enter the appropriate task number in next." << endl;
		
			system("pause");
			system("cls");
		
			enterSystem();
			cin >> systemC;
		}
	
		system("cls");
	
		if (systemC==1) 
		{
			viewList();
			system("pause");
			system("cls");
			
			systemC=99;
		}
		else if (systemC==2)
		{	
			sortBoatID();
			systemC=99;
		}
		else if (systemC==3)
		{
			searchMenu();
			cin >> task;
			
			if (task==1) searchBoatID();
			else if (task==2) searchBoatName();
			else system("cls"); 
			systemC=99;
		}
		else if(systemC==4)
		{
			if(couple.isEmpty()&&family.isEmpty() && familyDeluxe.isEmpty())
				cout <<"There is currently no stack available"<< endl; 
			else{
			one.printPattern(&couple);
			cout << endl;
			one.printPattern(&family);
			cout << endl;
			one.printPattern(&familyDeluxe);
			cout << endl;
			}
			system("pause");
			system("cls");
			systemC=99;
		}
		else if(systemC==5)
		{	
			if(renter1.isEmpty()&&renter2.isEmpty() && renter3.isEmpty())
				cout <<"There is currently no queue available"<< endl; 
			else{
				one.printPattern2(&renter1);
				one.printPattern2(&renter2);
				one.printPattern2(&renter3);
			}
			systemC=99;
		}
		else if(systemC==6)
		{
			boatType=rentBoat(&renter1, &renter2, &renter3, &serveQueue);
			boatOut(boatType, &couple, &family, &familyDeluxe, &renter1, &renter2, &renter3);
			
			systemC=99;
		}
		
		else if(systemC==7){
			system("cls");
			boatIn(&couple, &family, &familyDeluxe, &serveQueue);
			system("pause");
			system("cls");
			systemC=99;
		}
		
		else if(systemC==8)
		{
			system("cls");
			cout << endl;
			cout << "      Maintenance Menu" << endl;
			cout << endl;
			cout << "Key in the number to execute:" << endl;
			cout << "1. Restart and Reload Boat (collect ALL boats into dock)" << endl;
			cout << "2. Couple boat's maintainance (send all couple boats out of dock to repair)" << endl;
			cout << "3. Family boat's maintainance (send all family boats out of dock to repair)" << endl;
			cout << "4. Deluxe Family boat's maintennace (send all deluxe family boats out of dock to repair)" << endl;
			cout << "5. Maintainance for all boats (send ALL boats out of dock to repair)" << endl;
			cout << "0. Return to main menu" << endl;
			cout << "Command >>";
			cin >> task;
			
			// this line for boat maintenanace
			switch (task){
				
				case 5:	
				case 2:
					while(!couple.isEmpty())couple.pop();
					if(task==2) break;
				case 3:
					while(!family.isEmpty())family.pop();
					if(task==3) break;
				case 4:
					while(!familyDeluxe.isEmpty())familyDeluxe.pop();
					if(task==4) break;
				case 1:
					if(task==1)	load_boat(&couple, &family, &familyDeluxe);
					cout << "Request Successful" << endl;
				case 0:
					;
	
							
			}	
			
			system("pause");
			system("cls");
			task=0;
			systemC=99;
			
			
		}
		else if (systemC==0)
		{
			return 0;
		}
	}
	
	return 0;
}
