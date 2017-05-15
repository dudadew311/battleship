//
//  visible.h
//  Battleship
//
//  Created by TEAM B on 10/14/15.
//  Copyright © 2015 TEAM B. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
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
#define NUMBERS 10

void fillVisibleGrid(char visibleGrid[][NUMBERS]){
	int i, j;
	for (i = 0; i < NUMBERS; i++) {
		for (j = 0; j < NUMBERS; j++) {
			visibleGrid[i][j] = '-';
		}
	}
}


void showVisibleGrid(char visGrid[][NUMBERS], int hitCounter2, int hitCounter3, int hitCounter4, int hitCounter5, int t){
	int i, j;
	printf("\n");
	char letter[10] = {'A','B','C','D','E','F','G','H','I','J'};
	printf("\t  ");
	for (i = 0; i < NUMBERS; i++) {
		printf(" %i ", i + 1);
	}
	for (j = 0; j < NUMBERS;j++ ){
		printf("\n\t%c ", letter[j]);
		for (i = 0; i < NUMBERS; i++){
			printf(" %c ", visGrid[j][i]);
		}
	}
	printf("\n\n\tYou have had %i tries so far\n", t);

	printf("\n\n");
}