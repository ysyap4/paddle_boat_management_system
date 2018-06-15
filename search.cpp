#include "sort.h"
#include "boat.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;


string determineBoatType(int type);

//SEARCH (binary search) for ID
int binary_searchID(int search_key, int array_size, const int array [])
{
	bool found = false;
	int index = -1;
	int MIDDLE, LEFT=0,	RIGHT=array_size-1;
	
	while ((LEFT<=RIGHT) && (!found))
	{
		MIDDLE = (LEFT + RIGHT) /2; 
		
		if (array[MIDDLE] == search_key)
		{
			index = MIDDLE;
			found = true;
		}
		else if (array[MIDDLE] > search_key)
			RIGHT = MIDDLE-1; 
		else
			LEFT = MIDDLE+1;
	}
	
	return index;
}

//SEARCH (binary search) for name
int sequenceSearch(string search_key, int array_size, const string array [])
{
	int p;
	int index =-1;

	for (p=0; p<array_size; p++)
	{
		if (search_key == array[p])
			{ 
				index = p;
				break; 
			}		
	} 
	
	return index;
}

void searchBoatID()
{
	ifstream Fin;
	string name, arrName[10];
	int id, arrID[10], boatID;
	int arrType[10];
	int i=0, searchIndex;
	Fin.open("boatList.dat");

	while(!Fin.eof())
	{
		Fin >> id >> name;
		Fin.ignore(100, '\n');
	
		if(Fin)
		{
			arrID[i] = id;
			arrName[i] = name;
			arrType[i] = arrID[i]/100;
			i++;
		}
	}
	
	quickSort(arrID, arrName, arrType, 0, 8);
	partition(arrID, arrName, arrType, 0, 8);
	
	cout << endl;
	cout << "     Searching for paddle boat by ID    " << endl;
	cout << endl;
	cout << "Enter the boat ID: ";
	cin >> boatID;
	cout << endl;
	
	searchIndex = binary_searchID(boatID, 9, arrID);
	
	if (searchIndex!=-1)
	{
		cout << "Result is found by searching the boat ID <" << boatID << ">." << endl;
		cout << "Boat ID: " << arrID[searchIndex] << endl;
		cout << "Boat name: " << arrName[searchIndex] << endl;
		cout << "Boat type: " << determineBoatType(arrType[searchIndex]) << endl;
		cout << endl;
	}
	else
	{
		cout << "The boat ID <" << boatID <<"> is not found, because it is just in your wildest dreams." << endl;
	}
	
	system("pause");
	system("cls");
	
	Fin.close();	
}

void searchBoatName()
{
	ifstream Fin;
	string name, arrName[10], boatName;
	int id, arrID[10];
	int arrType[10];
	int i=0, searchIndex;
	Fin.open("boatList.dat");

	while(!Fin.eof())
	{
		Fin >> id >> name;
		Fin.ignore(100, '\n');
	
		if(Fin)
		{
			arrID[i] = id;
			arrName[i] = name;
			arrType[i] = arrID[i]/100;
			i++;
		}
	}
	
	quickSort(arrID, arrName, arrType, 0, 8);
	partition(arrID, arrName, arrType, 0, 8);
	
	cout << endl;
	cout << "     Searching for paddle boat by name     " << endl;
	cout << endl;
	cout << "Enter the boat name: ";
	cin >> boatName;
	cout << endl;
	
	searchIndex = sequenceSearch(boatName, 9, arrName);
	
	if (searchIndex!=-1)
	{
		cout << "Result is found by searching the boat name <" << boatName << ">." << endl;
		cout << "Boat ID: " << arrID[searchIndex] << endl;
		cout << "Boat name: " << arrName[searchIndex] << endl;
		cout << "Boat type: " << determineBoatType(arrType[searchIndex]) << endl;
		cout << endl;
	}
	else
	{
		cout << "The boat name <" << boatName <<"> is not found, because it is just in your wildest dreams." << endl;
	}
	
	system("pause");
	system("cls");
	
	Fin.close();	
}

Boat searchForPush()
{
	ifstream Fin;
	string name, arrName[10], boatName;
	int id, arrID[10];
	int type, arrType[10];
	int i=0, searchIndex;
	Boat* tempBoat= new Boat;
	Fin.open("boatList.dat");

	while(!Fin.eof())
	{
		Fin >> id >> name;
		Fin.ignore(100, '\n');
	
		if(Fin)
		{
			arrID[i] = id;
			arrName[i] = name;
			arrType[i] = arrID[i]/100;
			i++;
		}
	}
	
	quickSort(arrID, arrName, arrType, 0, 8);
	partition(arrID, arrName, arrType, 0, 8);
	
	cout << endl;
	cout << "     Returning boat    " << endl;
	cout << endl;
	while(searchIndex!=-1||searchIndex!=0)
	{
	cout << "Enter the boat name: ";
	cin >> boatName;
	cout << endl;
	
	searchIndex = sequenceSearch(boatName, 9, arrName);
	
	if (searchIndex!=-1)
	{
		id=arrID[searchIndex];
		type=arrType[searchIndex];
		tempBoat=new Boat(boatName, id, type);
		return *tempBoat; 
	}
	else
	{
		cout << "The boat name <" << boatName <<"> is not found, because it is just in your wildest dreams." << endl;
		cout << "Please try again"<< endl;
	}
	}
	system("pause");
	system("cls");
	
	Fin.close();	
}

void searchMenu(){
	
	
	system("cls");
			cout << endl;
			cout << "      Search paddle boat" << endl;
			cout << endl;
			cout << "Press the number to search by:" << endl;
			cout << "1. boat ID" << endl;
			cout << "2. boat name" << endl;
			cout << "3. return to main menu" << endl;
			cout << "Search by = ";
	
}
