// Written by...: TEAM B
// Date written.: October 1 , 2015
// Purpose......: Exam 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "shipPlacement.h"
#include "gamePlay.h"
#include "menu.h"
#include "visible.h"
#ifdef _WIN32
#include <windows.h>
#define PAUSE system("pause")
#define CLEAR system("clr")
#define FLUSH fflush(stdin)
#else
#include <unistd.h>
#define Sleep(s) sleep((s)/1000)
#define PAUSE printf("Pause Would go Here\n")
#define CLEAR system(clear)
#define FLUSH fpurge(stdin)
#endif
#define LETTERS 10
#define NUMBERS 10
#define SEC 1000


int main () {
	int hiddenGrid[LETTERS][NUMBERS] = {0};
	char visibleGrid[LETTERS][NUMBERS];
	int userChoice, hitCounter = 0, ships[5] = {0}, missile = 0;
	
	welcomeScreen();
	do{
		
		userChoice = displayMenu();
		switch (userChoice){
			case 1:
				fillVisibleGrid(visibleGrid);
				placeAllShips(hiddenGrid);
				do {
					showVisibleGrid(visibleGrid);
					missile = getUserCoordinates(hiddenGrid, visibleGrid, &hitCounter);
					
					shipCounter(missile, ships);
					
				} while (hitCounter < 17);
				break;
			case 2:
				exitPogram();
				break;
			default:
				printf("INVALID SELECTION\n");
				break;
		} // end switch
		PAUSE;
	} while (userChoice != 2 ) ;
	
	return 0;
} // end main
