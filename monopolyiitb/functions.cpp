#include <iostream>
#include "functions.h"
#include "classes.h"
using namespace std;

void movement()
{
    players[currPlayer].position = (players[currPlayer].position + diceRoll)%24;
}

void buy()
{
    players[currPlayer].money -= cells[currPosition].cost;
    cells[currPosition].owner = currPlayer;
}

void invest()
{

}

int Roll()
{
    int roll;
    //body of function
    return roll;
}

bool checkInvest()
{
    //check whether money or time is to be invested
}

bool checkBuy()
{

}
