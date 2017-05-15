//
//  scoring.h
//  Battleship
//
//  Created by Raul Diaz on 10/18/15.
//  Copyright © 2015 Raul Diaz. All rights reserved.
//



#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#define PAUSE system("pause")
#define CLEAR system("clr")
#define FLUSH fflush(stdin)
#else
#include <unistd.h>
#define PAUSE printf("Pause Would go Here\n")
#define CLEAR printf("Clear Happens herer\n") //system(clear)
#define FLUSH fpurge(stdin)
#endif
#define SIZE 10
#define SSIZE 30

typedef struct {
	char name[SSIZE];
	int score;
} PLAYER;

void displayPlayers(PLAYER[]);
void sort(PLAYER[], char[], int);



int showScores(int score) {
	FILE *scores;
	PLAYER p[SIZE]; //t[SIZE];// = {{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100},{"Score1", 100}};
	char tempName[SSIZE] = {' '};
	int i;
	
	
	scores = fopen("scores.bin", "rb");
	if (scores == NULL){
		scores = fopen("scores.bin", "wb");

		for (i = 0; i < SIZE; i++) {
			p[i].score = 100;
			strcpy(p[i].name, "name");
		}
		fwrite(p, sizeof(PLAYER), 10, scores);
	} else
		fread(p, sizeof(PLAYER), 10, scores);
	fclose(scores);
	if (score < p[9].score){
		printf("Enter a name: ");
		scanf("%[^\n]", tempName); FLUSH;
		sort(p, tempName, score);
		
	}
	scores = fopen("scores.bin", "wb");
	fwrite(p, sizeof(PLAYER), 10, scores);
	displayPlayers(p);
	fclose(scores);
	return 0;
}

void displayPlayers(PLAYER p[]){
	int i;
	printf("Our Top Scores:\n\n");
	printf("Name:\tScore:\n");
	for (i = 0; i < SIZE; i++) {
		
		printf("%s\t%i \n", p[i].name, p[i].score);
	}
}

void sort(PLAYER p[SIZE], char name[SSIZE], int score){
	int i;
	PLAYER temp, temp2;
	temp.score = score;
	strcpy(temp.name, name);
	for (i = 0; i < SIZE; i++) {
		if (temp.score <= p[i].score) {
			temp2 = p[i];
			p[i].score = temp.score;
			strcpy(p[i].name, temp.name);
			temp = temp2;
		}
	}
}