// Written by...: TEAM B
// Date written.: October 18 , 2015
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
#include "scoring.h"
#ifdef _WIN32
#include <windows.h>
#define PAUSE system("pause")
#define CLEAR system("cls")
#define FLUSH fflush(stdin)
#else
#include <unistd.h>
#define PAUSE printf("Pause Would go Here\n")
#define CLEAR printf("Clear Happens herer\n") //system(clear)
#define FLUSH fpurge(stdin)
#endif
#define LETTERS 10
#define NUMBERS 10
#define SEC 1000


int main () {
	int hiddenGrid[LETTERS][NUMBERS] = {0};
	char visibleGrid[LETTERS][NUMBERS];
	int userChoice, quitGame = 2, hitCounter2 = 0, hitCounter3 = 0, hitCounter4 = 0, hitCounter5 = 0;
	int tries = 96;
	welcomeScreen();
	do{
		if (quitGame == 2){
			showScores(tries);
			PAUSE;
		}
		quitGame = 0;
		userChoice = displayMenu();
		switch (userChoice){
			case 1:
				tries = 0;
				fillVisibleGrid(visibleGrid);
				placeAllShips(hiddenGrid);
				do {
					showVisibleGrid(visibleGrid, hitCounter2, hitCounter3, hitCounter4, hitCounter5, tries);
					showSunkenShips(hitCounter2, hitCounter3, hitCounter4, hitCounter5);
					getUserCoordinates(hiddenGrid, visibleGrid, &quitGame, &hitCounter2, &hitCounter3, &hitCounter4, &hitCounter5);
					tries++;
					CLEAR;
				} while (quitGame == 0);
				printf("You Quit! \n");
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
