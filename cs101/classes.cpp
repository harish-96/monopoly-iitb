#include "classes.h"

void Cell::setInfo(string name1,int moneyCost1,int timeCost1,int moneyRent1,int owner1,int timeRent1, int investMoney1, int investTime1, int incr_moneyRent1, int incr_timeRent1)
{
    moneyCost = moneyCost1;
    timeCost = timeCost1;
    moneyRent = moneyRent1;
    timeRent = timeRent1;
    name = name1;
    owner = owner1;
    investMoney = investMoney1;
    investTime = investTime1;
    incr_moneyRent = incr_moneyRent1;
    incr_timeRent = incr_timeRent1;
}

void Cell::setGraphInfo(int x,int y,int l,int b)
{
    xCentre = x;
    yCentre = y;
    length = l;
    breadth = b;
}

void Cell::updateInfoString()
{
    if(name=="START"||name=="Get Treat"||name=="Chance"||name=="DC++"||name=="Give Treat")
    {
       if(name=="START")
           infoString = "\t\t\t"+name+"\t\t\t\t\nYour money gets incremented by rupees 3000 and time by 2 hours everytime you cross this point.";
        if(name=="Get Treat")
            infoString = "\t\t\t"+name+"\t\t\t\t\n\tYou get a treat worth rupees 1000 from every other player.";
        if(name=="Give Treat")
            infoString = "\t\t\t"+name+"\t\t\t\t\n\tYou must give a treat to every other player (Rupees 1000 per player).";
        if(name=="Chance")
            infoString = "\t\t\t"+name+"\t\t\t\t\nIf the number rolled by the player is :\n1. Laptop stops working\t\ttime+2 money-500\n2. Miss lectures\t\t\ttime+1\n3. Canteen\t\t\tmoney-200 time-1\n4. Girlfriend's birthday!!!!\t\ttime -5 money-1000\n5. Sell your stuff\t\t\tmoney +1000\n6. Last night before exam. study!!!\ttime -3";
        if(name=="DC++")
            infoString = "\t\t\t"+name+"\t\t\t\t\n\tYou miss three turns when you come here.";
    }

    else if(owner==-1)
    {
        stringstream tc;
        tc << timeCost;
        string s_timeCost = tc.str();
        stringstream mc;
        mc << moneyCost;
        string s_moneyCost = mc.str();
        infoString = "\t\t\t"+name+"\t\t\t\t\nNobody owns this property\nPrice of this property is rupees "+s_moneyCost+"\nTime cost of this property is "+s_timeCost+"hours.";
    }

    else if(owner>-1&&owner<4)
    {
        stringstream tr;
        tr << timeRent;
        string s_timeRent = tr.str();
        stringstream mr;
        mr << moneyRent;
        string s_moneyRent = mr.str();
        stringstream own;
        own << owner+1;
        string s_owner = own.str();
        infoString = "\t\t\t"+name+"\t\t\t\t\nThe owner of this property is player "+s_owner+"\nTime Rent of this property is "+s_timeRent+"hours\nMoney Rent of this property is rupees "+s_moneyRent+".";
    }
    int i=0;
    while(infoString[i]!='\0')
    {
        info[i]=infoString[i];
        i++;
    }
    info[i]=infoString[i];
}
void Player::setInfo(int money1,int time1,int position1,int dcCounter1)
{
    money = money1;
    time = time1;
    position = position1;
    dcCounter = dcCounter1;
    //numofProps = numofProps1;
}

void Player::setGraphInfo(int x,int y,int l,int b,string name1)
{
    xCentre = x;
    yCentre = y;
    length = l;
    breadth = b;
    name = name1;
}

void Player::updateInfoString()
{
    stringstream t;
    t << time;
    string s_time = t.str();

    stringstream m;
    m << money;
    string s_money = m.str();

    infoString = "\t\t\t"+name+"\t\t\t\nTime : "+s_time+"\nMoney : "+s_money;
    int i = 0;
    while(infoString[i]!='\0')
    {
        info[i]=infoString[i];
        i++;
    }
    info[i]=infoString[i];
}

