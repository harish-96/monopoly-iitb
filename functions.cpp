#include <simplecpp>
#include "functions.h"
#include "classes.h"
#define endGameCriterion 55000
#include <sstream>
#define dcTimeDecrement 5
#define getTreat 500
#define giveTreat 500

using namespace std;

void movement()
{
    players[currPlayer].position = (players[currPlayer].position + diceRoll)%22;
}

void buy()
{
    players[currPlayer].money -= cells[currPosition].moneyCost;
    players[currPlayer].time -= cells[currPosition].timeCost;
    cells[currPosition].owner = currPlayer;
    turnCompleted = true;
}

void invest()
{
    players[currPlayer].money -= cells[currPosition].investMoney;
    players[currPlayer].time -= cells[currPosition].investTime;
    cells[currPosition].moneyRent += cells[currPosition].incr_moneyRent;
    cells[currPosition].timeRent += cells[currPosition].incr_timeRent;
    MessageBox(NULL,cells[currPosition].investMessage,"Invest",MB_OK);
    turnCompleted = true;

}


bool checkEndGame()
{
    if(checkIfPlaying(0)+checkIfPlaying(1)+checkIfPlaying(2)+checkIfPlaying(3)==1)
    {
        for(int i = 0;i<4;i++)
        {
            if(checkIfPlaying(i))
            winner = i;
            switch(i)
            {
            case 0:
                MessageBox(NULL,"Player 1 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
            case 1:
                MessageBox(NULL,"Player 2 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
            case 2:
                MessageBox(NULL,"Player 3 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
            case 3:
                MessageBox(NULL,"Player 4 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);
            }
        }

        return true;
    }
    bool localCheck = false;
    int j = -1;
    for(int i=0;i<4;i++)
    {
        if(players[i].money >= endGameCriterion)
        {
            localCheck = true;
            j=i;
            break;
        }
    }
    winner = j;
    switch(j)
        {
        case 0:
            MessageBox(NULL,"Player 1 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
        case 1:
            MessageBox(NULL,"Player 2 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
        case 2:
            MessageBox(NULL,"Player 3 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
        case 3:
            MessageBox(NULL,"Player 4 wins \t\t\t","Game Over",MB_OK | MB_ICONINFORMATION);break;
        }
    return localCheck;
}

void initCells_Players()
{
    for(int m =0;m<4;m++)
        players[m].setInfo(initialMoney,initialTime,0,0);

    players[0].dxCentre = -37;
    players[0].dyCentre = 31;
    players[1].dxCentre = -37;
    players[1].dyCentre = -31;
    players[2].dxCentre = 37;
    players[2].dyCentre = -31;
    players[3].dxCentre = 37;
    players[3].dyCentre = 31;

    cells[0].setInfo("START",0,0,0,-1,0,0,0,0,0);

    cells[1].setInfo("ED-Startup 1",3000,0,1000,-1,0,1000,2,800,1);
    cells[12].setInfo("ED-Startup 2",3000,0,1000,-1,0,1000,2,800,1);            //Educational startups
    cells[14].setInfo("ED-Startup 3",3000,0,1000,-1,0,1000,2,800,1);

    cells[4].setInfo("T-Startup 1",5000,0,1500,-1,0,1000,3,1000,2);         //Technological startup
    cells[7].setInfo("T-Startup 2",5000,0,1500,-1,0,1000,3,1000,2);

    cells[6].setInfo("O-Startup 1",2000,0,500,-1,0,8000,4,500,3);
    cells[15].setInfo("O-Startup 2",2000,0,500,-1,0,8000,4,500,3);
    cells[20].setInfo("O-Startup 3",2000,0,500,-1,0,8000,4,500,3);

    cells[2].setInfo("P-project 1",0,3,0,-1,1,3000,2,500,1);
    cells[10].setInfo("S-project 1",0,4,0,-1,2,1000,2,500,1);
    cells[3].setInfo("R-project 1",0,5,0,-1,2,500,2,500,1);

    cells[17].setInfo("P-project 1",0,3,0,-1,1,3000,2,500,1);
    cells[18].setInfo("S-project 1",0,4,0,-1,2,1000,2,500,1);
    cells[9].setInfo("R-project 1",0,5,0,-1,2,500,2,500,1);

    cells[21].setInfo("P-project 1",0,3,0,-1,1,3000,2,500,1);
    cells[13].setInfo("R-project 1",0,5,0,-1,2,500,2,500,1);

    cells[5].name = "Get Treat";
    cells[8].name = "Chance";
    cells[11].name = "DC++";
    cells[16].name = "Give Treat";
    cells[19].name = "Chance";

    cells[0].setGraphInfo((650-492+(0*164)),(350+230-(0*92)),164,92);
    cells[1].setGraphInfo((650-492+(0*164)),(350+230-(1*92)),164,92);
    cells[2].setGraphInfo((650-492+(0*164)),(350+230-(2*92)),164,92);
    cells[3].setGraphInfo((650-492+(0*164)),(350+230-(3*92)),164,92);
    cells[4].setGraphInfo((650-492+(0*164)),(350+230-(4*92)),164,92);
    cells[5].setGraphInfo((650-492+(0*164)),(350+230-(5*92)),164,92);
    cells[6].setGraphInfo((650-492+(1*164)),(350+230-(5*92)),164,92);
    cells[7].setGraphInfo((650-492+(2*164)),(350+230-(5*92)),164,92);
    cells[8].setGraphInfo((650-492+(3*164)),(350+230-(5*92)),164,92);
    cells[9].setGraphInfo((650-492+(4*164)),(350+230-(5*92)),164,92);
    cells[10].setGraphInfo((650-492+(5*164)),(350+230-(5*92)),164,92);
    cells[11].setGraphInfo((650-492+(6*164)),(350+230-(5*92)),164,92);
    cells[12].setGraphInfo((650-492+(6*164)),(350+230-(4*92)),164,92);
    cells[13].setGraphInfo((650-492+(6*164)),(350+230-(3*92)),164,92);
    cells[14].setGraphInfo((650-492+(6*164)),(350+230-(2*92)),164,92);
    cells[15].setGraphInfo((650-492+(6*164)),(350+230-(1*92)),164,92);
    cells[16].setGraphInfo((650-492+(6*164)),(350+230-(0*92)),164,92);
    cells[17].setGraphInfo((650-492+(5*164)),(350+230-(0*92)),164,92);
    cells[18].setGraphInfo((650-492+(4*164)),(350+230-(0*92)),164,92);
    cells[19].setGraphInfo((650-492+(3*164)),(350+230-(0*92)),164,92);
    cells[20].setGraphInfo((650-492+(2*164)),(350+230-(0*92)),164,92);
    cells[21].setGraphInfo((650-492+(1*164)),(350+230-(0*92)),164,92);

    cells[1].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 800 rupees.";
    cells[2].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";
    cells[3].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";
    cells[4].investMessage = "The time rent of this property has been incremented by 2 hour and money rent by 1000 rupees.";

    cells[6].investMessage = "The time rent of this property has been incremented by 3 hour and money rent by 500 rupees.";
    cells[7].investMessage = "The time rent of this property has been incremented by 2 hour and money rent by 1000 rupees.";

    cells[9].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";
    cells[10].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";

    cells[12].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 800 rupees.";
    cells[13].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";
    cells[14].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 800 rupees.";
    cells[15].investMessage = "The time rent of this property has been incremented by 3 hour and money rent by 500 rupees.";

    cells[17].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";
    cells[18].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";
    cells[20].investMessage = "The time rent of this property has been incremented by 3 hour and money rent by 500 rupees.";
    cells[21].investMessage = "The time rent of this property has been incremented by 1 hour and money rent by 500 rupees.";


}

void checkChance()
{
    switch(diceRoll)
    {
    case 1 :
        players[currPlayer].money -= 500;
        players[currPlayer].time += 2;
        if(!checkIfPlaying(currPlayer))
        {
            resetInfo(currPlayer);
        }
        MessageBox(NULL,"Your laptop stops working. You lose 500 rupees and gain 2 hours of time","CHANCE: Number rolled is 1.",MB_OK|MB_ICONINFORMATION);
        break;          //Laptop stops working

    case 2:

        players[currPlayer].time += 1;
        if(!checkIfPlaying(currPlayer))
        {
            resetInfo(currPlayer);
        }
        MessageBox(NULL,"You miss lectures and gain one hour of free time","CHANCE: Number rolled is 2.",MB_OK|MB_ICONINFORMATION);
        break;          //miss lectures

    case 3:
        players[currPlayer].money -=200;
        players[currPlayer].time -= 1;
        if(!checkIfPlaying(currPlayer))
        {
            resetInfo(currPlayer);
        }
        MessageBox(NULL,"You go to the canteen and waste 200 rupees and an hour of your time.","CHANCE: Number rolled is 3.",MB_OK|MB_ICONINFORMATION);
        break;      //canteen

    case 4:
        players[currPlayer].money -= 1000;
        players[currPlayer].time -= 5;
        if(!checkIfPlaying(currPlayer))
        {
            resetInfo(currPlayer);
        }
        MessageBox(NULL,"It's your Girlfriend's birthday!You lose 1000 rupees and 5 hours of time.","CHANCE: Number rolled is 4.",MB_OK|MB_ICONINFORMATION);
        break;        //GF bday!!

    case 5:
        players[currPlayer].money += 1000;
        if(!checkIfPlaying(currPlayer))
        {
            resetInfo(currPlayer);
        }
        MessageBox(NULL,"You sell your stuff and gain 1000 rupees.","CHANCE: Number rolled is 5.",MB_OK|MB_ICONINFORMATION);
        break;
              //Sell your stuff

    case 6:
        players[currPlayer].time -= 3;
        if(!checkIfPlaying(currPlayer))
        {
            resetInfo(currPlayer);
        }
        MessageBox(NULL,"It's exam time!Read for 3 hours.","CHANCE: Number rolled is 6.",MB_OK|MB_ICONINFORMATION);      //Exam time


    }
}

bool checkIfPlaying(int player)
{
    return !(players[player].money<=0||players[player].time<=0);
}

void resetInfo(int j)
{
    players[j].setInfo(0,0,0,0);

    for(int i = 0;i<22;i++)
    {
        if(cells[i].owner==j)
        {
            cells[i].owner = -1;
            switch(i)
            {
                case 0: cells[0].setInfo("START",0,0,0,-1,0,0,0,0,0);break;

                case 1: cells[1].setInfo("ED-Startup 1",3000,0,1000,-1,0,1000,2,800,1);break;
                case 12: cells[12].setInfo("ED-Startup 2",3000,0,1000,-1,0,1000,2,800,1);break;            //Educational startups
                case 14: cells[14].setInfo("ED-Startup 3",3000,0,1000,-1,0,1000,2,800,1);break;

                case 4: cells[4].setInfo("T-Startup 1",5000,0,1500,-1,0,1000,3,1000,2);break;         //Technological startup
                case 7: cells[7].setInfo("T-Startup 2",5000,0,1500,-1,0,1000,3,1000,2);break;

                case 6: cells[6].setInfo("O-Startup 1",2000,0,500,-1,0,8000,4,500,3);break;
                case 15: cells[15].setInfo("O-Startup 2",2000,0,500,-1,0,8000,4,500,3);break;
                case 20: cells[20].setInfo("O-Startup 3",2000,0,500,-1,0,8000,4,500,3);break;

                case 2: cells[2].setInfo("P-project 1",0,3,0,-1,1,3000,2,500,1);break;
                case 10: cells[10].setInfo("S-project 1",0,4,0,-1,2,1000,2,500,1);break;
                case 3: cells[3].setInfo("R-project 1",0,5,0,-1,2,500,2,500,1);break;

                case 17: cells[17].setInfo("P-project 1",0,3,0,-1,1,3000,2,500,1);break;
                case 18: cells[18].setInfo("S-project 1",0,4,0,-1,2,1000,2,500,1);break;
                case 9: cells[9].setInfo("R-project 1",0,5,0,-1,2,500,2,500,1);break;

                case 21: cells[21].setInfo("P-project 1",0,3,0,-1,1,3000,2,500,1);break;
                case 13: cells[13].setInfo("R-project 1",0,5,0,-1,2,500,2,500,1);break;
            }
        }
    }
}
void hideDiceCircles(Circle *c,int currDiceRoll);
void Engine()
{
    initCells_Players();
    Circle g_players[4];
    Rectangle playerText(650,425,150,30);
    playerText.setFill(true);
    playerText.setColor(COLOR(255,0,127));

    Circle c[7];

    Rectangle ownership[22];

    players[0].setGraphInfo(650,25,500,50,"Player 1");
    players[1].setGraphInfo(25,350,50,500,"Player 2");
    players[2].setGraphInfo(1275,350,50,500,"Player 3");
    players[3].setGraphInfo(650,675,500,50,"Player 4");

    c[0].reset(627.5,197.5,7.5);
    c[0].setColor(COLOR(0,0,0));
    c[0].setFill(true);
    c[0].hide();

    c[5].reset(672.5,242.5,7.5);
    c[5].setColor(COLOR(0,0,0));
    c[5].setFill(true);
    c[5].hide();

    c[2].reset(627.5,220,7.5);
    c[2].setColor(COLOR(0,0,0));
    c[2].setFill(true);
    c[2].hide();

    c[3].reset(672.5,220,7.5);
    c[3].setColor(COLOR(0,0,0));
    c[3].setFill(true);
    c[3].hide();

    c[4].reset(627.5,242.5,7.5);
    c[4].setColor(COLOR(0,0,0));
    c[4].setFill(true);
    c[4].hide();

    c[1].reset(672.5,197.5,7.5);
    c[1].setColor(COLOR(0,0,0));
    c[1].setFill(true);
    c[1].hide();

    c[6].reset(650,220,7.5);
    c[6].setColor(COLOR(0,0,0));
    c[6].setFill(true);
    c[6].hide();

    for(int i =0;i<4;i++)
        g_players[i].reset((650-492+(0*164))+players[i].dxCentre,(350+230-(0*92))+players[i].dyCentre,10);

    g_players[0].setColor(COLOR("red"));
    g_players[0].setFill(true);

    g_players[1].setColor(COLOR("blue"));
    g_players[1].setFill(true);

    g_players[2].setColor(COLOR("green"));
    g_players[2].setFill(true);

    g_players[3].setColor(COLOR("yellow"));
    g_players[3].setFill(true);


    Text player1Turn(650,425,"Player 1's turn");
    player1Turn.setFill(true);
    player1Turn.setColor(COLOR("red"));
    player1Turn.hide();

    Text player2Turn(650,425,"Player 2's turn");
    player2Turn.setFill(true);
    player2Turn.setColor(COLOR("blue"));
    player2Turn.hide();

    Text player3Turn(650,425,"Player 3's turn");
    player3Turn.setFill(true);
    player3Turn.setColor(COLOR("green"));
    player3Turn.hide();

    Text player4Turn(650,425,"Player 4's turn");
    player4Turn.hide();

    while(true)
    {
        hideDiceCircles(c,diceRoll);
        player1Turn.hide();
        player2Turn.hide();
        player3Turn.hide();
        player4Turn.hide();
        currPlayer = (currPlayer + 1)%4;
        if(checkEndGame()) break;
        checkClickBuy = 0;
        if(!checkIfPlaying(currPlayer)) g_players[currPlayer].hide();
        if(checkIfPlaying(currPlayer))
        {

            cout<<"The player is "<<currPlayer<<endl;
            cout<<currPlayer<<" money is : "<<players[currPlayer].money<<":"<<endl;
            cout<<currPlayer<<" time is : "<<players[currPlayer].time<<endl;

            switch(currPlayer)
            {
            case 0:
                player1Turn.show();break;
            case 1:
                player2Turn.show();break;
            case 2:
                player3Turn.show();break;
            case 3:
                player4Turn.show();
            }

            if(players[currPlayer].dcCounter!=0)
            {
                players[currPlayer].dcCounter--;
                MessageBox(NULL,"You miss a turn\t\t\t","DC++",MB_OK | MB_ICONEXCLAMATION);
                continue;
            }
            rolled = false;
            turnCompleted = false;
            checkClick();
            cout <<"Diceroll is "<< diceRoll<<":";

            if(diceRoll==1)
            {
                c[6].show();
            }
            else if(diceRoll==2)
            {
                c[0].show();
                c[5].show();
            }
            else if(diceRoll==3)
            {
                c[0].show();
                c[5].show();
                c[6].show();
            }
            else if(diceRoll==4)
            {
                c[0].show();
                c[1].show();
                c[4].show();
                c[5].show();
            }
            else if(diceRoll==5)
            {
                c[0].show();
                c[1].show();
                c[4].show();
                c[5].show();
                c[6].show();
            }
            else if(diceRoll==6)
            {
                c[0].show();
                c[1].show();
                c[4].show();
                c[5].show();
                c[2].show();
                c[3].show();
            }

            movement();
            currPosition = players[currPlayer].position;
            g_players[currPlayer].reset((cells[currPosition].xCentre)+(players[currPlayer].dxCentre),(cells[currPosition].yCentre)+(players[currPlayer].dyCentre),10);
            cout << " Current position is:  " << currPosition << endl;
            cout<<"owner of this position is : "<<cells[currPosition].owner<<endl;
            cout<<" "<<endl;
            if(currPosition<diceRoll){
                players[currPlayer].money += 3000; //change the values
                players[currPlayer].time += 5;
                MessageBox(NULL,"Your money has been incremented by 3000 and time by 2 hours","Back to Start",MB_OK|MB_ICONINFORMATION);
                turnCompleted = true;
            }
            if(checkEndGame()) break;
            switch(currPosition)
            {
            case 0:
                checkClick();
                if(endTurn) continue;
            // start startup project project startup gettreat startup startup chance project project givetreat startup project
            // startup startup dc++ project project chance startup project
            case 1:
            case 4:
            case 6:
            case 7:
            case 12:
            case 14:
            case 15:
            case 20: //startups
                if(cells[currPosition].owner == -1)
                {
                    int localCheck = MessageBox(NULL,"Do you want to buy this Startup \t\t","Question",MB_YESNO|MB_ICONQUESTION);
                    if(localCheck==IDYES)
                    {
                        buy();
                        cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                        cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                        cout<<" "<<endl;
                        ownership[currPosition].reset((cells[currPosition].xCentre)-77,cells[currPosition].yCentre,10,92);
                        switch(currPlayer)
                        {
                        case 0:
                            ownership[currPosition].setColor(COLOR("red"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 1:
                            ownership[currPosition].setColor(COLOR("blue"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 2:
                            ownership[currPosition].setColor(COLOR("green"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 3:
                            ownership[currPosition].setColor(COLOR("yellow"));
                            ownership[currPosition].setFill(true);
                            break;
                        }
                        if(!checkIfPlaying(currPlayer))
                        {
                            resetInfo(currPlayer);
                            g_players[currPlayer].hide();
                            continue;
                        }
                        continue;
                    }
                    checkClick();
                    if(checkClickBuy)
                    {
                        ownership[currPosition].reset((cells[currPosition].xCentre)-77,cells[currPosition].yCentre,10,92);
                        switch(currPlayer)
                        {
                        case 0:
                            ownership[currPosition].setColor(COLOR("red"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 1:
                            ownership[currPosition].setColor(COLOR("blue"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 2:
                            ownership[currPosition].setColor(COLOR("green"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 3:
                            ownership[currPosition].setColor(COLOR("yellow"));
                            ownership[currPosition].setFill(true);
                            break;
                        }
                    }
                    if(!checkIfPlaying(currPlayer))
                    {
                        resetInfo(currPlayer);
                        g_players[currPlayer].hide();
                        continue;
                    }

                    if(endTurn) continue;
                }
                else if(cells[currPosition].owner == currPlayer)
                {
                    int localCheck=MessageBox(NULL,"Do you want to invest time and money in this Startup","Question",MB_YESNO|MB_ICONQUESTION);
                    if(localCheck==IDYES)
                    {
                        invest();
                        cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                        cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                        cout<<" "<<endl;
                        if(!checkIfPlaying(currPlayer))
                        {
                            resetInfo(currPlayer);
                            g_players[currPlayer].hide();
                            continue;
                        }
                    }
                    checkClick();

                    if(!checkIfPlaying(currPlayer))
                    {
                        resetInfo(currPlayer);
                        g_players[currPlayer].hide();
                        continue;
                    }
                    if(endTurn) continue;
                }
                else
                {
                    MessageBox(NULL,"Paid the rent of this startup to the owner.\t\t","Payment of rent.",MB_ICONINFORMATION|MB_OK);
                    players[currPlayer].money -= cells[currPosition].moneyRent;
                    players[currPlayer].time -= cells[currPosition].timeRent;
                    players[cells[currPosition].owner].money += cells[currPosition].moneyRent;
                    players[cells[currPosition].owner].time += cells[currPosition].timeRent;
                    cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                    cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                    cout<<" "<<endl;
                    if(checkEndGame()) break;
                    checkClick();
                    if(!checkIfPlaying(currPlayer))
                    {
                        resetInfo(currPlayer);
                        g_players[currPlayer].hide();
                        continue;
                    }
                    if(endTurn) continue;
                }
            case 2:
            case 3:
            case 9:
            case 10:
            case 13:
            case 17:
            case 18:
            case 21://Project
                if(cells[currPosition].owner == -1)
                {
                    int localCheck = MessageBox(NULL,"Do you want to start this Project? \t\t","Question",MB_YESNO|MB_ICONQUESTION);
                    if(localCheck==IDYES)
                    {
                        buy();
                        cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                        cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                        cout<<" "<<endl;
                        ownership[currPosition].reset((cells[currPosition].xCentre)-77,cells[currPosition].yCentre,10,92);
                        switch(currPlayer)
                        {
                        case 0:
                            ownership[currPosition].setColor(COLOR("red")); //red
                            ownership[currPosition].setFill(true);
                            break;
                        case 1:
                            ownership[currPosition].setColor(COLOR("blue")); //blue
                            ownership[currPosition].setFill(true);
                            break;
                        case 2:
                            ownership[currPosition].setColor(COLOR("green")); //green
                            ownership[currPosition].setFill(true);
                            break;
                        case 3:
                            ownership[currPosition].setColor(COLOR("yellow"));
                            ownership[currPosition].setFill(true);
                            break;
                        }
                        if(!checkIfPlaying(currPlayer))
                        {
                            resetInfo(currPlayer);
                            g_players[currPlayer].hide();
                            continue;
                        }
                        continue;
                    }
                    checkClick();
                    if(checkClickBuy)
                    {
                        ownership[currPosition].reset((cells[currPosition].xCentre)-77,cells[currPosition].yCentre,10,92);
                        switch(currPlayer)
                        {
                        case 0:
                            ownership[currPosition].setColor(COLOR("red"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 1:
                            ownership[currPosition].setColor(COLOR("blue"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 2:
                            ownership[currPosition].setColor(COLOR("green"));
                            ownership[currPosition].setFill(true);
                            break;
                        case 3:
                            ownership[currPosition].setColor(COLOR("yellow"));
                            ownership[currPosition].setFill(true);
                            break;
                        }
                    }

                    if(!checkIfPlaying(currPlayer))
                    {
                        resetInfo(currPlayer);
                        g_players[currPlayer].hide();
                        continue;
                    }
                    if(endTurn) continue;
                }
                else if(cells[currPosition].owner == currPlayer)
                {
                    int localCheck=MessageBox(NULL,"Do you want to invest time and money in this Project","Question",MB_YESNO|MB_ICONQUESTION);
                    if(localCheck==IDYES)
                    {
                        invest();
                        cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                        cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                        cout<<" "<<endl;
                        if(!checkIfPlaying(currPlayer))
                        {
                            resetInfo(currPlayer);
                            continue;
                        }
                    }
                    checkClick();

                    if(!checkIfPlaying(currPlayer))
                    {
                        resetInfo(currPlayer);
                        g_players[currPlayer].hide();
                        continue;
                    }
                    if(endTurn) continue;
                }
                else
                {
                    MessageBox(NULL,"Paid the rent of this project to the owner.\t\t","Rent payment",MB_ICONINFORMATION|MB_OK);
                    players[currPlayer].money -= cells[currPosition].moneyRent;
                    players[currPlayer].time -= cells[currPosition].timeRent;
                    players[cells[currPosition].owner].money += cells[currPosition].moneyRent;
                    players[cells[currPosition].owner].time += cells[currPosition].timeRent;
                    cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                    cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                    cout<<" "<<endl;
                    if(checkEndGame()) break;
                    checkClick();

                    if(!checkIfPlaying(currPlayer))
                    {
                        resetInfo(currPlayer);
                        g_players[currPlayer].hide();
                        continue;
                    }
                    if(endTurn) continue;
                }

            case 11: //dc++
                players[currPlayer].dcCounter = 3;
                players[currPlayer].time -= dcTimeDecrement;
                MessageBox(NULL,"You miss three turns and lose 5 hours of time\t\t","\t\t\tDC++\t\t\t",MB_OK|MB_ICONERROR);
                checkClick();

                if(!checkIfPlaying(currPlayer))
                {
                    resetInfo(currPlayer);
                    g_players[currPlayer].hide();
                    continue;
                }
                if(endTurn) continue;
            case 5: //get treat
                {
                    MessageBox(NULL,"You receive rupees 500 from every other player.","Get Treat",MB_OK|MB_ICONINFORMATION);
                    bool localEndGameCheck5= 0;
                    for(int i=0;i<4;i++)
                    {
                        if(checkIfPlaying(i))
                        {
                            players[currPlayer].money += getTreat;
                            players[i].money -= getTreat;
                        }

                        if(checkEndGame())
                        {
                            localEndGameCheck5 = 1;
                            break;
                        }
                        if(!checkIfPlaying(i))
                        {
                            resetInfo(i);
                            g_players[i].hide();
                        }
                    }
                    if(localEndGameCheck5) break;
                    checkClick();
                    if(endTurn) continue;

                }
            case 16: // give treat
                {
                    MessageBox(NULL,"You give rupees 500 to every other player.","Give Treat",MB_OK|MB_ICONINFORMATION);
                    bool localEndGameCheck16 = 0;
                    for(int i=0;i<4;i++)
                    {
                        if(checkIfPlaying(i))
                        {
                            players[currPlayer].money -= giveTreat;
                            players[i].money += giveTreat;
                        }

                        if(checkEndGame())
                        {
                            localEndGameCheck16 = 1;
                            break;
                        }
                        if(!checkIfPlaying(i))
                            {
                                resetInfo(i);
                                g_players[i].hide();
                            }
                    }
                    if(localEndGameCheck16) break;
                    checkClick();
                    if(endTurn) continue;
                }

            case 8:
            case 19: //chance
                checkChance();
                checkClick();
                if(endTurn)
                    continue;
            }
        }
    }
    cout << winner;
}

void hideDiceCircles(Circle *c,int diceRoll)
{
    if(diceRoll==1)
            {
                c[6].hide();
            }
            else if(diceRoll==2)
            {
                c[0].hide();
                c[5].hide();
            }
            else if(diceRoll==3)
            {
                c[0].hide();
                c[5].hide();
                c[6].hide();
            }
            else if(diceRoll==4)
            {
                c[0].hide();
                c[1].hide();
                c[4].hide();
                c[5].hide();
            }
            else if(diceRoll==5)
            {
                c[0].hide();
                c[1].hide();
                c[4].hide();
                c[5].hide();
                c[6].hide();
            }
            else if(diceRoll==6)
            {
                c[0].hide();
                c[1].hide();
                c[4].hide();
                c[5].hide();
                c[2].hide();
                c[3].hide();
            }
}

