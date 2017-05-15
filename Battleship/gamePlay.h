//
//  gamePlay.h
//  Battleship
//
//  Created by TEAM B on 10/14/15.
//  Copyright © 2015 TEAM B. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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


void getUserCoordinates(int hidGrid[LETTERS][NUMBERS], char visibleGrid[LETTERS][NUMBERS], int *quitGame, int *hitCounter2, int *hitCounter3, int *hitCounter4, int *hitCounter5){
	int numberInput = 0, letterConv = 0, hitCounter = 0;
	char letterInput;
	printf("Enter your coordinates (Type Q1 to QUIT) : ");
	scanf("%c%i", &letterInput, &numberInput); FLUSH;
	letterInput = toupper(letterInput);

	if (letterInput == 'Q'){
		*quitGame = 1;
	}
	
	switch (letterInput) {
		case 'A':
			letterConv = 0;
			break;
		case 'B':
			letterConv = 1;
			break;
		case 'C':
			letterConv = 2;
			break;
		case 'D':
			letterConv = 3;
			break;
		case 'E':
			letterConv = 4;
			break;
		case 'F':
			letterConv = 5;
			break;
		case 'G':
			letterConv = 6;
			break;
		case 'H':
			letterConv = 7;
			break;
		case 'I':
			letterConv = 8;
			break;
		case 'J':
			letterConv = 9;
			break;
	}
	if (visibleGrid[letterConv][numberInput - 1] == '-') {
		if (hidGrid[letterConv][numberInput - 1] == 0) {
			visibleGrid[letterConv][numberInput - 1] = 'M';
		}
		else {
			visibleGrid[letterConv][numberInput - 1] = 'H';
		}
	} else {
		printf("Try a different Cordinate, you already tried that one!!\n");
		getUserCoordinates(hidGrid, visibleGrid, quitGame, hitCounter2, hitCounter3, hitCounter4, hitCounter5);
	}
	//================================================================
	
	if (hidGrid[letterConv][numberInput - 1] == 2){
		*hitCounter2 = *hitCounter2 + 1;
		if (*hitCounter2 == 2){
			printf("You have sunk Ship 2! \n");
			PAUSE;
		}// end if
	}// end if
	else if (hidGrid[letterConv][numberInput - 1] == 3){
		*hitCounter3 = *hitCounter3 + 1;
		if (*hitCounter3 == 3){
			printf("You have sunk Ship 3 #1! \n");
			PAUSE;
		}// end if
		else if (*hitCounter3 == 6){
			printf("You have sunk Ship 3 #2! \n");
			PAUSE;
		}// end else if
	}// end if
	else if (hidGrid[letterConv][numberInput - 1] == 4){
		*hitCounter4 = *hitCounter4 + 1;
		if (*hitCounter4 == 4){
			printf("You have sunk Ship 4! \n");
			PAUSE;
		}// end if
	}// end else if
	else if (hidGrid[letterConv][numberInput - 1] == 5){
		*hitCounter5 = *hitCounter5 + 1;
		if (*hitCounter5 == 5){
			printf("You have sunk Ship 5! \n");
			PAUSE;
		}// end if
	}// end else if
	hitCounter = *hitCounter2 + *hitCounter3 + *hitCounter4 + *hitCounter5;
	if (hitCounter == 17){
		*quitGame = 2;
	}
	printf("\n");
}// end getUserCoordinates

void showSunkenShips(int hitCounter2, int hitCounter3, int hitCounter4, int hitCounter5){
	printf("Sunk Ships: ");
	if (hitCounter2 >= 2){
		printf("Ship 2, ");
	}// end if
	if (hitCounter3 >= 3 && hitCounter3 < 6){
		printf("Ship 3 #1, ");
	}// end if
	else if (hitCounter3 >= 6){
		printf("Ship 3 #1, Ship 3 #2, ");
	}// end else if
	if (hitCounter4 >= 4){
		printf("Ship 4, ");
	}//end if
	if (hitCounter5 >= 5){
		printf("Ship 5");
	}//end if
	printf("\n\n");
}// end showSunkenShips