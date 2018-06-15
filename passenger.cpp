#include "passenger.h"
#include <iostream>
using namespace std;

Passenger::Passenger()
{
	
}

Passenger::Passenger(string a, string b, int c, int d,  int e, float f)
{
	passengerName = a;
	passengerPhone = b;
	duration = c;
	boatType = d;
	passengerNum= e;
	price = f;
}

string Passenger::printPassengerName() 
{

}


