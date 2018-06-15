#ifndef SORT_H
#define SORT_H

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
void sortBoatID();
void sortBoatName();
void sortBoatType();


#endif
