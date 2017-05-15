//
//  shipPlacement.h
//  Battleship
//
//  Created by TEAM B on 10/14/15.
//  Copyright © 2015 TEAM B. All rights reserved.
//

#ifndef shipPlacement_h
#define shipPlacement_h
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#define PAUSE system("pause")
#define CLEAR system("cls")
#define FLUSH fflush(stdin)
#else
#include <unistd.h>
#define Sleep(s) sleep((s)/1000)
#define PAUSE printf("Pause Would go Here\n")
#define CLEAR printf("Clear happens here")//system(clear)
#define FLUSH fpurge(stdin)
#endif
#define LETTERS 10
#define NUMBERS 10
#define SEC 1000

#endif /* shipPlacement_h */

int checkIfOk(int[LETTERS][NUMBERS],int, int, int, int, int);
int checkSize(int, int, int, int);
int generateRandomNumber();
int getOrient();
int generatePosition();
void place4Ship(int[LETTERS][NUMBERS]);
void place5Ship(int[LETTERS][NUMBERS]);
void place3Ship(int[LETTERS][NUMBERS]);
void place2Ship(int[LETTERS][NUMBERS]);
void place1Ship(int[LETTERS][NUMBERS]);
void resetHiddenGrid(int[LETTERS][NUMBERS]);

void placeAllShips(int hiddenGrid[LETTERS][NUMBERS]){
	
	resetHiddenGrid(hiddenGrid);
	place5Ship(hiddenGrid);
	printf("Ship of 5 has been placed! Please hold for the next!\n");
	place4Ship(hiddenGrid);
	printf("Ship of 4 has been placed! Please hold for the next!\n");
	place3Ship(hiddenGrid);
	printf("Ship of 3 has been placed! Please hold for the next!\n");
	place2Ship(hiddenGrid);
	printf("Ship of 3 has been placed! Please hold for the next!\n");
	place1Ship(hiddenGrid);
	printf("Ship of 2 has been placed!\n\n");
	
	CLEAR;


}

void resetHiddenGrid(int hiddenGrid[LETTERS][NUMBERS]){
	int i, j;
	for (i = 0; i < LETTERS; i++) {
		for (j = 0; j < NUMBERS; j++) {
			hiddenGrid[i][j] = 0;
		}
	}
}

void place5Ship(int grid[LETTERS][NUMBERS]){
	int i, limit = 5, letter = 0, number =  0;
	int flag = 0, position = 0, orientation = 0, randomNum;
	randomNum = generateRandomNumber();
	orientation = randomNum % 2;
	position = randomNum %100;
	letter = position / 10;
	number = position % 10;
	flag = checkSize( orientation, limit, letter, number);
	if (flag == 0) {
		if (orientation == 0) {
			for( i = 0; i < limit; i++){
				grid[letter][number + i] = 5; // dont forget to change back to 1
			}
		} else {
			for( i = 0; i < limit; i++){
				grid[letter + i][number] = 5; // dont forget to change back to 1
			}
		}
	} else {
		place5Ship(grid);
	}
}

void place4Ship(int grid[LETTERS][NUMBERS]){
	int i, limit = 4, letter = 0, number =  0, max = 6;
	int flag = 0, position = 0, orientation, randomNum;
	
	
	
	do {
		randomNum = generateRandomNumber();
		orientation = randomNum % 2;
		position = randomNum %100;
		
		letter = position / 10;
		number = position % 10;
		flag = checkIfOk(grid, orientation, position, letter, number, limit);
		if (flag == 0){
			flag = checkSize( orientation, max, letter, number);
		}
	} while (flag == 1);
	if (orientation == 0) {
		for( i = 0; i < limit; i++){
			grid[letter][number + i] = 4; // dont forget to change back to 1
		}
	} else {
		for( i = 0; i < limit; i++){
			grid[letter + i][number] = 4; // dont forget to change back to 1
		}
	}
}

void place3Ship(int grid[LETTERS][NUMBERS]){
	int i, limit = 3, letter = 0, number =  0, max = 6;
	int flag = 0, position = 0, orientation, randomNum;
	
	do {
		randomNum = generateRandomNumber();
		orientation = randomNum % 2;
		position = randomNum %100;
		letter = position / 10;
		number = position % 10;
		flag = checkIfOk(grid, orientation, position, letter, number, limit);
		if (flag == 0){
			flag = checkSize( orientation, max, letter, number);
		}
	} while (flag == 1);
	if (orientation == 0) {
		for( i = 0; i < limit; i++){
			grid[letter][number + i] = 3; // dont forget to change back to 1
		}
	} else {
		for( i = 0; i < limit; i++){
			grid[letter + i][number] = 3; // dont forget to change back to 1
		}
	}
}

void place2Ship(int grid[LETTERS][NUMBERS]){
	int i, limit = 3, letter = 0, number =  0, max = 6;
	int flag = 0, position = 0, orientation, randomNum;
	
	do {
		randomNum = generateRandomNumber();
		orientation = randomNum % 2;
		position = randomNum %100;
		letter = position / 10;
		number = position % 10;
		flag = checkIfOk(grid, orientation, position, letter, number, limit);
		if (flag == 0){
			flag = checkSize( orientation, max, letter, number);
		}
	} while (flag == 1);
	if (orientation == 0) {
		for( i = 0; i < limit; i++){
			grid[letter][number + i] = 2; // dont forget to change back to 1
		}
	} else {
		for( i = 0; i < limit; i++){
			grid[letter + i][number] = 2; // dont forget to change back to 1
		}
	}
}

void place1Ship(int grid[LETTERS][NUMBERS]){
	int i, limit = 2, letter = 0, number =  0, max = 6;
	int flag = 0, position = 0, orientation, randomNum;
	
	do {
		randomNum = generateRandomNumber();
		orientation = randomNum % 2;
		position = randomNum %100;
		letter = position / 10;
		number = position % 10;
		flag = checkIfOk(grid, orientation, position, letter, number, limit);
		if (flag == 0){
			flag = checkSize( orientation, max, letter, number);
		}	} while (flag == 1);
	if (orientation == 0) {
		for( i = 0; i < limit; i++){
			grid[letter][number + i] = 1; // dont forget to change back to 1
		}
	} else {
		for( i = 0; i < limit; i++){
			grid[letter + i][number] = 1; // dont forget to change back to 1
		}
	}
}

int checkIfOk(int grid[LETTERS][NUMBERS],int orientation, int position, int letter, int number, int limit){
	int flag = 0, i;
	
	if ( orientation == 0){
		for (i = 0; i < limit; i++) {
			if (grid[letter][number + i] == 0){
				flag = 0;
			} else {
				flag = 1;
			}
		}
	} else {
		for( i = 0; i < limit; i++){
			if (grid[letter + i][number] == 0){
				flag = 0;
				
			} else {
				flag = 1;
			}
		}
	}
	return flag;
}

int checkSize(int orientation, int max, int letter, int number){
	int flag = 0;
	if (orientation == 0) {
		if (number < max){
			flag = 0;
		} else {
			flag = 1;
		}
	} else {
		if (letter < max){
			flag = 0;
		} else {
			flag = 1;
		}
	}
	return flag;
}

int generateRandomNumber() {
	Sleep(SEC);
	srand((unsigned)time(NULL));
	return rand();
} //End generateRandomNumber function


