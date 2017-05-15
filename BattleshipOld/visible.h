//
//  visible.h
//  Battleship
//
//  Created by Raul Diaz on 10/14/15.
//  Copyright © 2015 Raul Diaz. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
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
#define NUMBERS 10

void fillVisibleGrid(char visibleGrid[][NUMBERS]){
	int i, j;
	for (i = 0; i < NUMBERS; i++) {
		for (j = 0; j < NUMBERS; j++) {
			visibleGrid[i][j] = '-';
		}
	}
}


void showVisibleGrid(char visGrid[][NUMBERS]){
	int i, j;
	
	//CLEAR;
	printf("\n");
	char letter[10] = {'A','B','C','D','E','F','G','H','I','J'};
	printf("  ");
	for (i = 0; i < NUMBERS; i++) {
		printf(" %i ", i + 1);
	}
	for (j = 0; j < NUMBERS;j++ ){
		printf("\n%c ", letter[j]);
		for (i = 0; i < NUMBERS; i++){
			printf(" %c ", visGrid[j][i]);
		}
	}
	printf("\n\n");
}