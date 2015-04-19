#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "classes.h"
#include <windows.h>
#include "graphics.h"
#include <time.h>
#include <stdlib.h>
#include<windows.h>

extern int currPlayer;
extern int currPosition;
extern int diceRoll;
extern bool rolled;
extern bool checkBuy;
extern bool checkInvest;
extern bool playerPlaying[4];
extern bool endTurn;
extern bool turnCompleted;
extern bool checkClickBuy;
void movement(); // moves the player by the number on dice
void buy(); // changes owner of that property to current player and subtracts from his money
void invest(); // increments rent and decrements owner's money and time
void nextTurn(); // interface: displays the next player's name
void checkClick(); // checks the click position and performs corresponding operation
bool checkEndGame(); //checks if the game has ended according to a pre-decided criterion
void initCells_Players(); // sets the initial values of member variables of class objects
void checkChance(); // game proceeds according to diceroll
bool checkIfPlaying(int player);// check if the player is playing
void resetInfo(int j,Rectangle *ownership);// resets the info of properties owned by current player
void Engine();
#endif // FUNCTIONS_H
