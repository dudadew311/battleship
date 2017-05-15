//
//  menu.h
//  Battleship
//
//  Created by Raul Diaz on 10/14/15.
//  Copyright © 2015 Raul Diaz. All rights reserved.
//

//#ifndef menu_h
//#define menu_h
//#endif /* menu_h */
//#define _CRT_SECURE_NO_WARNINGS
//# include <stdio.h>
//# include <stdlib.h>
//# define PAUSE system ("pause")
//# define CLEAR system ("cls")
//#define FLUSH fflush (stdin)
int displayMenu();
void exitPogram();
void welcomeScreen();

int displayMenu() {
	int userChoice;
	//CLEAR;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+++++++++++++ WELCOME TO BATTLESHIP ++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t\t 1. PLAY \n");
	printf("\t\t 2. QUIT \n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	
	printf("What do you want to do: ");
	scanf("%i", &userChoice); FLUSH;
	return userChoice;
}//End function displayMenu

void exitPogram (){
	printf("Thank you for playing Battleship!!!\n");
} //End function exitPogram

void welcomeScreen(){
	printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX   \n");
	printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX \n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX   \n");
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX     \n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX     \n");
	//CLEAR;
	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.\n");
	printf ("2. Player 1 is you and Player 2 is the computer.\n");
	printf ("3. Player 1 will be prompted if user wants to manually input coordinates\n");
	printf ("   for the game board or have the computer randomly generate a game board\n");
	printf ("4. There are five types of ships to be placed by longest length to the\n");
	printf ("   shortest; .............................................................\n");
	
	
	printf ("5. The computer randomly selects which player goes first\n");
	printf ("6. The game begins as each player tries to guess the location of the ships\n");
	printf ("   of the opposing player's game board; [H] hit and [O] miss\n");
	printf ("7. First player to guess the location of all ships wins\n\n");
}//End function welcomeScreen



