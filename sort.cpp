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

//SORT part 1 (quick sort) for ID
void quickSort(int T[], string U[], int V[], int first ,int last)
{
	int cut;
	
	if (first<last)
	{
		cut = partition(T,U,V,first,last);
		quickSort(T,U,V,first,cut);
		quickSort(T,U,V,cut+1,last);
	}
}

//SORT part 2 (quick sort) for ID
int partition(int T[], string U[], int V[], int first, int last)
{
	int pivot, tempT, tempV;
	string tempU;
	int loop, cutPoint, bottom, top;
	
	pivot = T[first];
	bottom = first; 
	top = last;
	loop = 1; 
	
	while(loop) 
	{
		while (T[top]>pivot)
		{top--;}
		while(T[bottom]<pivot)
		{bottom++;}

		if (bottom<top)
		{ 
			tempT=T[bottom];
			tempU=U[bottom];
			tempV=V[bottom];
			T[bottom]=T[top];
			U[bottom]=U[top];
			V[bottom]=V[top];
			T[top]=tempT;
			U[top]=tempU;
			V[top]=tempV;
		}
		else 
		{
			loop=0;
			cutPoint = top;
		}
	} 
	
	return cutPoint;
}

//sort the boat by ID
void sortBoatID()
{
	ifstream Fin;
	string name, arrName[10];
	int id, arrID[10];
	int arrType[10];
	int i=0, task;
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
	cout << "        Sorted paddle boat list by ID" << endl;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "|    ID     |    Name    |   Type   |" << endl;
	cout << "-------------------------------------" << endl;
	
	for (i=0; i<9; i++)
	{
		cout << "|    " << arrID[i] << "    |   " << arrName[i] << "   |   " <<  determineBoatType(arrType[i]) << endl;
	}
	cout << endl;
	cout << "Press the number to sort by (1-3):" << endl;
	cout << "1. boat ID" << endl;
	cout << "2. boat name" << endl;
	cout << "3. boat type" << endl;
	cout << "4. return to main menu" << endl;
	cout << "Sort by = ";
	cin >> task;
	cout << endl;
	
	if (task==1)
	{	
		system("cls");
		sortBoatID();	
	}
	else if (task==2)
	{	
		system("cls");
		sortBoatName();	
	}
	else if (task==3)
	{
		system("cls");
		sortBoatType();
	}
	else
	{
		system("cls");
		return;
	}
	
	Fin.close();
}

//sort the boat by name
void sortBoatName()
{
	ifstream Fin;
	string name, arrName[10], temp2;
	int id, arrID[10], temp1, temp3;
	int arrType[10];
	int i=0, j, task;
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
	
	for (i=1; i < 9; ++i)
	{
		temp1 = arrID[i];
    	temp2 = arrName[i];
    	temp3 = arrType[i];
    
   		for (j=i-1; j>=0 && arrName[j] > temp2; j--)
    	{
     		arrID[j+1] = arrID[j];
     		arrName[j+1] = arrName[j];
     		arrType[j+1] = arrType[j];
   		}
   		
   		arrID[j+1] = temp1;
    	arrName[j+1] = temp2;
    	arrType[j+1] = temp3;
	}
	
	cout << endl;
	cout << "        Sorted paddle boat list by Name" << endl;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "|    ID     |    Name    |   Type   |" << endl;
	cout << "-------------------------------------" << endl;
	
	for (i=0; i<9; i++)
	{
		cout << "|    " << arrID[i] << "    |   " << arrName[i] << "   |   " <<  determineBoatType(arrType[i]) << endl;
	}
	cout << endl;
	cout << "Press the number to sort by (1-3):" << endl;
	cout << "1. boat ID" << endl;
	cout << "2. boat name" << endl;
	cout << "3. boat type" << endl;
	cout << "4. return to main menu" << endl;
	cout << "Sort by = ";
	cin >> task;
	cout << endl;
	
	if (task==1)
	{	
		system("cls");
		sortBoatID();	
	}
	else if (task==2)
	{	
		system("cls");
		sortBoatName();	
	}
	else if (task==3)
	{
		system("cls");
		sortBoatType();
	}
	else
	{
		system("cls");
		return;
	}
		
	Fin.close();	
}

void sortBoatType()
{
	ifstream Fin;
	string name, arrName[10], temp2;
	int id, arrID[10], temp1, temp3;
	int arrType[10];
	int i=0, j, task;
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
	
	for (i=1; i < 9; ++i)
	{
		temp1 = arrID[i];
    	temp2 = arrName[i];
    	temp3 = arrType[i];
    
   		for (j=i-1; j>=0 && arrType[j] > temp3; j--)
    	{
     		arrID[j+1] = arrID[j];
     		arrName[j+1] = arrName[j];
     		arrType[j+1] = arrType[j];
   		}
   		
   		arrID[j+1] = temp1;
    	arrName[j+1] = temp2;
    	arrType[j+1] = temp3;
	}
	
	cout << endl;
	cout << "        Sorted paddle boat list by Type" << endl;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "|    ID     |    Name    |   Type   |" << endl;
	cout << "-------------------------------------" << endl;
	
	for (i=0; i<9; i++)
	{
		cout << "|    " << arrID[i] << "    |   " << arrName[i] << "   |   " <<  determineBoatType(arrType[i]) << endl;
	}
	cout << endl;
	cout << "Press the number to sort by (1-3):" << endl;
	cout << "1. boat ID" << endl;
	cout << "2. boat name" << endl;
	cout << "3. boat type" << endl;
	cout << "4. return to main menu" << endl;
	cout << "Sort by = ";
	cin >> task;
	cout << endl;
	
	if (task==1)
	{	
		system("cls");
		sortBoatID();	
	}
	else if (task==2)
	{	
		system("cls");
		sortBoatName();	
	}
	else if (task==3)
	{
		system("cls");
		sortBoatType();
	}
	else
	{
		system("cls");
		return;
	}
		
	Fin.close();		
}
