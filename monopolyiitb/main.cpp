#include <iostream>
#include "functions.h"
#include <string>
using namespace std;

Player players[4];
Cell cells[24];
int currPlayer = 3;
int currPosition;
int diceRoll;
bool checkBuy;
bool checkInvest;

int main()
{
    while(true)
    {
        currPlayer = (currPlayer + 1)%4;
        if(players[currPlayer].dcCounter!=0)
        {
            players[currPlayer].dcCounter--;
            continue;
        }
        currPosition = players[currPlayer].position;
        //diceRoll = Roll();
        movement();
        switch(currPosition)
        {
        case 0:
            players[currPlayer].money += 200;
            players[currPlayer].time += 10;
            continue;
        case 1: //say some startup
            if(cells[currPosition].owner == -1)
            {
                if(checkBuy) buy();
                continue;
            }
            else if(cells[currPosition].owner == currPlayer)
            {
                if(checkInvest) invest();
                continue;
            }
            else
            {
                players[currPlayer].money -= cells[currPosition].moneyRent;
                players[currPlayer].time -= cells[currPosition].timeRent;
                players[cells[currPosition].owner] += cells[currPosition].moneyRent;
                players[cells[currPosition].owner] += cells[currPosition].timeRent;
                continue;
            }
        case 2: //say dc++
            players[currPlayer].dcCounter = 3;
            continue;
        }
    }
}


