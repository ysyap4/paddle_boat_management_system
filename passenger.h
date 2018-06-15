#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
using namespace std;


class Passenger
{
	private:
		string passengerName;
		string passengerPhone;
		int passengerNum;
		int duration;
		int boatType;
		float price;
		
		
	public:
		Passenger ();
		Passenger (string, string, int, int, int, float);
		void setPassengerName (string x) {passengerName = x;};
		void setPassengerPhone (string x) {passengerPhone = x;};
		void setDuration (int x) {duration = x;};
		void setBoatType (int x) {boatType = x;};
		string getPassengerName () {return passengerName;};
		string getPassengerPhone () {return passengerPhone;};
		int getPassengerNum () {return passengerNum;};
		int getDuration () {return duration;};
		int getBoatType () {return boatType;};
		float getPrice() {return price;};
		string printPassengerName();
		string viewPassenger();
};

#endif
