/*
*    MONOPOLY-IITB
*    Modified version of Monopoly pertaining to the life of a student at IIT-B
*
*   Made by Harish Murali
*           Kirtish Badwe
*           Avijit Srivastava
*           Archit Katare
*           supported by our TA Vitoba
*
*    Harish and Kirtsih handled the main game code
*    Archit and Avijit handled the graphics code
*    The connection of graphics and main game code was done by all of us.
*/


#include <simplecpp>
#include "functions.h"

using namespace std;

Player players[4]; // an array of 4 objects of class Player
Cell cells[22];// an array of 22 objects of class Cell
int currPlayer = 3; // global variable which stores the player who is playing
int currPosition; // global variable storing the current player's location
int winner; // global variable storing the game's winner
int diceRoll; // storing the number rolled in the present iteration
bool rolled; // boolean variable-stores if the player has rolled or not
bool checkBuy;//checks if buy has been clicked
bool checkInvest;//checks if invest has been clicked
bool playerPlaying[4]; // boolean array-true if player is playing
bool endTurn; // true if end turn is clicked
bool turnCompleted;
bool checkClickBuy;

int main()
{
    layout(); //layout calls board which calls the main engine
}
