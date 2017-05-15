//
//  gamePlay.h
//  Battleship
//
//  Created by Raul Diaz on 10/14/15.
//  Copyright © 2015 Raul Diaz. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#define PAUSE system("pause")
#define CLEAR system("clr")
#define FLUSH fflush(stdin)
#else
#include <unistd.h>
#define PAUSE printf("Pause Would go Here\n")
#define CLEAR system(clear)
#define FLUSH fpurge(stdin)
#endif
#define LETTERS 10
#define NUMBERS 10


int getUserCoordinates(int hidGrid[LETTERS][NUMBERS], char visibleGrid[LETTERS][NUMBERS],int *hitCounter){
	int numberInput = 0, letterConv = 0, result = 0;
	char letterInput ;
	
	printf("Enter your letter coordinate: ");
	scanf("%c%i", &letterInput, &numberInput); FLUSH;
	letterInput = toupper(letterInput);
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
	if (hidGrid[letterConv][numberInput - 1] == 0) {
		visibleGrid[letterConv][numberInput - 1] = 'M';
	} else {
		visibleGrid[letterConv][numberInput - 1] = 'H';
		(*hitCounter)++;
		result = hidGrid[letterConv][numberInput - 1];
	}
	printf("\n");
	return result;
}

void shipCounter(int n, int ships[5]){
	
	switch(n){
		case 1:
			if (ships[0] == 2){
				printf("Ship with 2 has been sunk!!");
			} else {
				ships[0]++;
			}
			break;
		case 2:
			if (ships[1] == 3){
				printf("Ship with 3A has been sunk!!");
			} else {
				ships[1]++;
			}
			break;
		case 3:
			if (ships[2] == 3){
				printf("Ship with 3B has been sunk!!");
			} else {
				ships[2]++;
			}
			break;
		case 4:
			if (ships[3] == 4){
				printf("Ship with 4 has been sunk!!");
			} else {
				ships[3]++;
			}
			break;
		case 5:
			if (ships[4] == 5){
				printf("Ship with 5 has been sunk!!");
			} else {
				ships[4]++;
			}
			break;
		default:
			break;
	}
}