#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include "stack.h"
#include "queue.h"
#include <windows.h>
using namespace std;

class Display{
	private:
		int height;
		int width;
		
	public:
		void createDisplay(string);
		int printC(int, char);
		void content(string);
		void content2(string);
		void topBottom();
		void middle(string);
		void divider();
		int printPattern(Stack*);
		int printPattern2(Queue*);
		int printPattern3(Stack*);
		void arrow();
		void smiley1();
		void smiley2();
		void wall();
		void dock();
		void boat(string, int, int);
		void moveOut();
		
	
	
};



#endif
