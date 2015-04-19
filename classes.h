#ifndef CLASSES_H
#define CLASSES_H
#define initialMoney 50000
#define initialTime 50
#include <sstream>
#include<windows.h>

using namespace std;

extern int winner;
extern bool playersPlaying[4];


class Cell {
public:
    int moneyCost,timeCost, moneyRent,timeRent; //the parameters related to the cell
    int xCentre,yCentre,length,breadth; // graphical information
    char info[700];
    string infoString; // the info to be displayed when the cell is clicked
    string name;
    int owner = -1; // 0 for player1,1 for player2, 2 for player3, and 4 for player4
    int color;//0-nocolor 1-red 2-yellow 3-green 4-blue
    int investMoney; // amount of money to be invested
    int investTime;//amount of time to be invested
    int incr_timeRent;
    int incr_moneyRent;
    char* investMessage;

    void setInfo(string name1,int cost1,int moneyRent1,int owner,int color1,int timeRent1, int investMoney1, int investTime1, int incr_moneyRent1, int incr_timeRent1); //check again
    void setGraphInfo(int x,int y,int l,int b);
    void updateInfoString();
};

class Player {
public:
    int money;//money owned
    int time;//time owned
    int position;//position of player from 0-21
    bool propsOwned[22];
    int dcCounter; //check if player is on dc or not
    int xCentre,yCentre,length,breadth; //for setting the pawns in the graphic code
    char info[100]; //info to be displayed when the box of individual player is clicked
    string infoString;
    string name;
    int dxCentre,dyCentre;
    void setInfo(int money1,int time1,int position1,int dcCounter1); //function to set info of the player
    void setGraphInfo(int x,int y,int l,int b,string name1); //function to set the graphical info of the player for the pawns
    void updateInfoString();
};

extern Player players[4];
extern Cell cells[22];

#endif // CLASSES_H
