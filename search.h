#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;

void quickSort(int T[], string U[], int V[], int first ,int last);
int partition(int T[], string U[], int V[], int first, int last);

int binary_searchID(int search_key, int array_size, const int array []);
int sequenceSearch(string search_key, int array_size, const string array []);
void searchBoatID();
void searchBoatName();
Boat searchForPush();
void searchMenu();


#endif
