#include "display.h"
#include <iomanip>

void Display::createDisplay(string header){
	this->printC(5, ' ');
	cout << setw(7) << left << header << endl;
	this->printC(1, ' ');
	this->printC(24, '=');
	this->printC(1, ' ');
	cout << endl;
	width=25;	
	
}

int Display::printC(int x, char y){
	
	if(x==0){
		return 0;
	}
	cout << setw(1) <<  y;
	return printC(x-1, y);
	
}

void Display::topBottom(){
	
	this->printC(1, ' ');
	this->printC(2, '|');
	this->printC(3, ' ');
	this->printC(13, '-');
	this->printC(3, ' ');
	this->printC(2, '|');
	cout << endl;
	
}

void Display::middle(string content){

	this->printC(1, ' ');
	this->printC(2, '|');
	this->printC(3, ' ');
	this->printC(1, '|');
	cout << setw(11) << content;
	this->printC(1, '|');
	this->printC(3, ' ');
	this->printC(2, '|');
	this->printC(1, ' ');
	cout << endl;

	
}
void Display::divider(){
	this->printC(1, ' ');
	this->printC(2, '|');
	cout << setw(19) << " ";
	this->printC(2, '|');
	this->printC(1, ' ');
	cout << endl;
}

void Display::content(string z){
	
	this->topBottom();
	this->middle(" ");
	this->middle(z);
	this->middle(" ");
	this->topBottom();
	this->divider();	
}
void Display::content2(string z){
	
	this->printC(15, ' ');
	this->topBottom();
	this->printC(15, ' ');
	this->middle(" ");
	this->printC(15, ' ');
	this->middle(z);
	this->printC(15, ' ');
	this->middle(" ");
	this->printC(15, ' ');
	this->topBottom();
	this->printC(15, ' ');
	this->divider();	
}

void Display::arrow(){
	this->printC(3, ' ');
   this->printC(1, '<');
   this->printC(6, '-');
   this->printC(3, ' ');
}

void Display::wall(){
	
	this->printC(16, '=');
}

void Display::smiley1(){
	cout << "  >_<  ";
}

void Display::smiley2(){
	cout << "  -_-  ";
}
void Display::dock(){
	
		for(int x=0;x<20; x++){
		this->printC(2,' ');
	if(x%2)this->printC(3,' ');
	for(int i=0; i<8; i++)
	{
		this->printC(1, '~');
		this->printC(6, ' ');
		
	}
	cout << endl;
	}
	wall();
	this->printC(23, ' ');
	wall();
	cout << endl;
	
}
void Display::boat(string z, int x, int y){
	
	this->printC(x+1, ' ');
	this->printC(13, '-');
	this->printC(0, ' ');
	cout << endl;
	this->printC(x+1, ' ');
	this->printC(1, '|');
	this->printC(11, ' ');
	this->printC(1, '|');
	this->printC(5, ' ');
	cout << endl;
	this->printC(x+1, ' ');
	this->printC(1, '|');
	cout << setw(11) << z;
	this->printC(1, '|');
	this->printC(5, ' ');
	cout << endl;
	this->printC(x+1, ' ');
	this->printC(1, '|');
	this->printC(11, ' ');
	this->printC(1, '|');
	this->printC(5, ' ');
	cout << endl;
	this->printC(x+1, ' ');
	this->printC(13, '-');
	this->printC(0, ' ');
	cout << endl;
	
}

void Display::moveOut(){
	
}
//final output
int Display::printPattern(Stack* boat){
	
	
	string x = "None";
	string b1 = "Heartbeat";
	string b2 = "Sugar";
	string b3 = "Babe";
	Stack sTemp;
	sTemp.createStack();
	Boat* boatTemp;
	
	if(boat->isEmpty()){
		return 0;
	}
	
	if (boat->head->boatStack.getBoatType()==2) {x = "Couple paddle boat";}
	else if (boat->head->boatStack.getBoatType()==4) {x = "Family paddle boat"; }
	else if (boat->head->boatStack.getBoatType()==6) {x = "Deluxe Family paddle boat";}
	
	

	this->createDisplay(x);
	
	while(!boat->isEmpty())
	{
	
	string boatName = boat->stackTop2().getBoatName();
	int boatID = boat->stackTop2().getBoatID();	
	int boatType = boat->stackTop2().getBoatType();
	boatTemp = new Boat(boatName, boatID, boatType);
	sTemp.push (*boatTemp);
	delete boatTemp;
	boat->pop();
	this->content(boatName);
	}
	
	while(!sTemp.isEmpty())
	{
	string boatName = sTemp.stackTop2().getBoatName();
	int boatID = sTemp.stackTop2().getBoatID();	
	int boatType = sTemp.stackTop2().getBoatType();
	boatTemp = new Boat(boatName, boatID, boatType);
	boat->push (sTemp.stackTop2());
	delete boatTemp;
	sTemp.pop();
	}
	
	cout << endl << endl;
}


int Display::printPattern2(Queue* renter){
	
	string x = "None";
	string passengerName, passengerPhone;
	int duration, boatType, passengerNum, count, loop=0;
	float price;
	Queue temp;
	temp.createQueue();
	Passenger *queueTemp = new Passenger;
	bool exit = false;

    while(exit == false)
    {
        
    
	if(!renter->isEmpty()){
	
	int type = renter->getFront().getBoatType();
	if (type==2) {x = "Couple paddle boat Queue";}
	else if (type==4) {x = "Family paddle boat Queue"; }
	else if (type==6) {x = "Deluxe Family paddle boat Queue";}
	
	this->printC(5, ' ');
   cout << '|' << x << '|' << endl;
   count = renter->countNode();
   this->printC(15, ' ');
   this->printC(15*count, '=');
   cout << endl << endl;
   arrow();
	while(!renter->isEmpty())
	{
		passengerName = renter->getFront().getPassengerName();
		passengerPhone = renter->getFront().getPassengerPhone();
		duration = renter->getFront().getDuration();
		boatType = renter->getFront().getBoatType();
		passengerNum = renter->getFront().getPassengerNum();
		price = renter->getFront().getPrice();
		
		queueTemp = new Passenger(passengerName, passengerPhone, duration, boatType, passengerNum, price);
		temp.enQueue(*queueTemp);
		delete queueTemp;
		renter->deQueue();
		
		if(loop%2){
			smiley1();
		}else smiley2();
		
		cout << setw(10) << left << passengerName;
		
	}
	loop++;
	arrow();
	cout << endl << endl;
	this->printC(15, ' ');
	this->printC(15*count, '=');
   cout << endl <<endl;
   cout<< endl << "Press any esc to return... "<<endl;
	while(!temp.isEmpty())
	{
		passengerName = temp.getFront().getPassengerName();
		passengerPhone = temp.getFront().getPassengerPhone();
		duration = temp.getFront().getDuration();
		boatType = temp.getFront().getBoatType();
		passengerNum = temp.getFront().getPassengerNum();
		price = temp.getFront().getPrice();
		queueTemp = new Passenger(passengerName, passengerPhone, duration, boatType, passengerNum, price);
		renter->enQueue(*queueTemp);
		delete queueTemp;
		temp.deQueue();
	}
	}
	 if (GetAsyncKeyState(VK_ESCAPE))
        {
        	//MessageBox(NULL, "Redirecting","Shift",0);
            exit = true;
            system("cls");
            return 0;
        }
	Sleep( 300 );
	system("cls");

	}

}


int Display::printPattern3(Stack* boat){
	
	Stack sTemp;
	sTemp.createStack();
	Boat* boatTemp;
	system("cls");

	dock();
	if(boat->isEmpty()){
		this->content2("No boat in the dock");
		return 0;
	}
	
	while(!boat->isEmpty())
	{
	
	string boatName = boat->stackTop2().getBoatName();
	int boatID = boat->stackTop2().getBoatID();	
	int boatType = boat->stackTop2().getBoatType();
	boatTemp = new Boat(boatName, boatID, boatType);
	sTemp.push (*boatTemp);
	delete boatTemp;
	boat->pop();
	
	}
	
	while(!sTemp.isEmpty())
	{
	string boatName = sTemp.stackTop2().getBoatName();
	int boatID = sTemp.stackTop2().getBoatID();	
	int boatType = sTemp.stackTop2().getBoatType();
	boatTemp = new Boat(boatName, boatID, boatType);
	boat->push (sTemp.stackTop2());
	delete boatTemp;
	sTemp.pop();
	this->content2(boatName);
	}
	cout << endl <<endl;
	this->boat("test", 20, 0);
	
cout << "     ~      ~      ~       ~      ~      ~       ~     " << endl;
	cout << "  ~      ~      ~      ~      ~       ~      ~      ~  " << endl;
	cout << "     ~      ~      ~       ~      ~      ~       ~     " << endl;
	cout << "  ~      ~      ~      ~      ~       ~      ~      ~  " << endl;
	cout << "     ~      ~      ~       ~      ~      ~       ~     " << endl;
	cout << "  ~      ~      ~      ~      ~       ~      ~      ~  " << endl;
	cout << "     ~      ~      ~       ~      ~      ~       ~     " << endl;
	cout << "  ~      ~      ~      ~      ~       ~      ~      ~  " << endl;
	cout << "     ~      ~      ~       ~      ~      ~       ~     " << endl;
	cout << "===============                      ==================" << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	cout << "              |                      |                 " << endl;
	
	
}


