#include "boat.h"
#include <iostream>
using namespace std;

Boat::Boat()
{
	
}

Boat::Boat(string a, int b, int c)
{
	boatName = a;
	boatID = b;
	boatType = c;
}

string Boat::printBoatName() 
{
	if (boatID==101) 	  boatName="Heartbeat";
	else if (boatID==102) boatName="Sugar";
	else if (boatID==103) boatName="Babe";
	else if (boatID==201) boatName="Diamond";
	else if (boatID==202) boatName="Amethyst";
	else if (boatID==203) boatName="Ruby";
	else if (boatID==301) boatName="Aluminium";
	else if (boatID==302) boatName="Titanium";
	else if (boatID==303) boatName="Uranium";	
	
	return boatName;
}

string determineBoatType(int type){
   string typeS;
   if (type==2) typeS="Couple";
		else if (type==4) typeS="Family";
		else if (type==6) typeS="Deluxe Family";
 return typeS;
}


