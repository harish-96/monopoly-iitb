#ifndef CLASSES_H
#define CLASSES_H
#define initialMoney 5000
#define initialTime 100
#include <sstream>
using namespace std;

class Cell {
public:
    int cost, moneyRent,timeRent;
    string name;
    int owner = -1;
    int color;//0-nocolor 1-red 2-yellow 3-green 4-blue
    void setInfo(string name,int cost,int moneyRent1,int owner,int color,int timeRent);
};

class Player {
public:
    int money = initialMoney;
    int time = initialTime;
    int position = 0;
    int propOwned[22];
    int dcCounter = 0;
};

extern Player players[4];
extern Cell cells[22];

#endif // CLASSES_H
