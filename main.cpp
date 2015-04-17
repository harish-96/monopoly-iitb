#include <simplecpp>
#include "functions.h"

using namespace std;

Player players[4];
Cell cells[22];
int currPlayer = 3;
int currPosition;
int winner;
int diceRoll;
bool rolled;
bool checkBuy;
bool checkInvest;
bool playerPlaying[4];
bool endTurn;
bool turnCompleted;
bool checkClickBuy;

int main()
{
    layout();
}
