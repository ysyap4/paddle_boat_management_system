#ifndef BOAT_H
#define BOAT_H
#include <iostream>
using namespace std;


class Boat
{
	private:
		string boatName;
		int boatID;
		int boatType;
		
	public:
		Boat ();
		Boat (string, int, int);
		void setBoatName (string x) {boatName = x;};
		void setBoatID (int x) {boatID = x;};
		void setBoatType (int x) {boatType = x;};
		string getBoatName () {return boatName;};
		int getBoatID () {return boatID;};
		int getBoatType () {return boatType;};
		string printBoatName();
		string viewBoat();
		string determineBoatType(int);
};

#endif
