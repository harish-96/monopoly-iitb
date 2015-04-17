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
    int moneyCost,timeCost, moneyRent,timeRent;
    int xCentre,yCentre,length,breadth;
    char info[700];
    string infoString;
    string name;
    int owner = -1;
    int color;//0-nocolor 1-red 2-yellow 3-green 4-blue
    int investMoney;
    int investTime;
    int incr_timeRent;
    int incr_moneyRent;
    char* investMessage;

    void setInfo(string name1,int cost1,int moneyRent1,int owner,int color1,int timeRent1, int investMoney1, int investTime1, int incr_moneyRent1, int incr_timeRent1); //check again
    void setGraphInfo(int x,int y,int l,int b);
    void updateInfoString();
};

class Player {
public:
    int money;
    int time;
    int position;
    bool propsOwned[22];
    int dcCounter;
    int xCentre,yCentre,length,breadth;
    char info[100];
    string infoString;
    string name;
    int dxCentre,dyCentre;
    void setInfo(int money1,int time1,int position1,int dcCounter1);
    void setGraphInfo(int x,int y,int l,int b,string name1);
    void updateInfoString();
};

extern Player players[4];
extern Cell cells[22];

#endif // CLASSES_H
