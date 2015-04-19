#include<simplecpp>
#include "functions.h"
#include<time.h>

void checkClick();
void board()
{
        Rectangle player1(650,25,500,50);
        player1.setColor(COLOR("red"));
        player1.setFill(true);
        Text t_player1(650,25,"Player 1");
        t_player1.setColor(COLOR("red"));
        t_player1.setFill(true);

        //rectangles of players

        Rectangle player2(25,350,50,500);
        player2.setColor(COLOR("blue"));
        player2.setFill(true);
        Text t_player2_p(25,280,"P");
        Text t_player2_l(25,300,"l");
        Text t_player2_a(25,320,"a");
        Text t_player2_y(25,340,"y");
        Text t_player2_e(25,360,"e");
        Text t_player2_r(25,380,"r");

        /*Text t_player2_g(25,400," ");*/

        Text t_player2_2(25,420,"2");
        t_player2_p.setColor(COLOR("blue"));
        t_player2_p.setFill(true);
        t_player2_l.setColor(COLOR("blue"));
        t_player2_l.setFill(true);
        t_player2_a.setColor(COLOR("blue"));
        t_player2_a.setFill(true);
        t_player2_y.setColor(COLOR("blue"));
        t_player2_y.setFill(true);
        t_player2_e.setColor(COLOR("blue"));
        t_player2_e.setFill(true);
        t_player2_r.setColor(COLOR("blue"));
        t_player2_r.setFill(true);
        t_player2_2.setColor(COLOR("blue"));
        t_player2_2.setFill(true);

        Rectangle player3(1275,350,50,500);
        player3.setColor(COLOR("green"));
        player3.setFill(true);
        Text t_player3_p(1275,280,"P");
        Text t_player3_l(1275,300,"l");
        Text t_player3_a(1275,320,"a");
        Text t_player3_y(1275,340,"y");
        Text t_player3_e(1275,360,"e");
        Text t_player3_r(1275,380,"r");

        /*Text t_player3_g(1275,400," ");*/

        Text t_player3_3(1275,420,"3");
        t_player3_p.setColor(COLOR("green"));
        t_player3_p.setFill(true);
        t_player3_l.setColor(COLOR("green"));
        t_player3_l.setFill(true);
        t_player3_a.setColor(COLOR("green"));
        t_player3_a.setFill(true);
        t_player3_y.setColor(COLOR("green"));
        t_player3_y.setFill(true);
        t_player3_e.setColor(COLOR("green"));
        t_player3_e.setFill(true);
        t_player3_r.setColor(COLOR("green"));
        t_player3_r.setFill(true);
        t_player3_3.setColor(COLOR("green"));
        t_player3_3.setFill(true);


        Rectangle player4(650,675,500,50);
        player4.setColor(COLOR("yellow"));
        player4.setFill(true);
        Text t_player4(650,675,"Player 4");
        t_player4.setColor(COLOR("yellow"));
        t_player4.setFill(true);

        // the cells outline
        /*Rectangle board_ext(650,350,1148,552);
        Rectangle board_int(650,350,820,368);*/

        //creating cells
        Rectangle cell_1((650-492+(0*164)),(350+230-(0*92)),164,92);
        Rectangle cell_2((650-492+(0*164)),(350+230-(1*92)),164,92);Text t_cell_2((650-492+(0*164)),(350+230-(1*92)),"Educational Start-Up");
        Rectangle cell_3((650-492+(0*164)),(350+230-(2*92)),164,92);Text t_cell_3((650-492+(0*164)),(350+230-(2*92)),"Personal Project");
        Rectangle cell_4((650-492+(0*164)),(350+230-(3*92)),164,92);Text t_cell_4((650-492+(0*164)),(350+230-(3*92)),"Research Project");
        Rectangle cell_5((650-492+(0*164)),(350+230-(4*92)),164,92);Text t_cell_5((650-492+(0*164)),(350+230-(4*92)),"Technological Start-Up");
        Rectangle cell_6((650-492+(0*164)),(350+230-(5*92)),164,92);
        Rectangle cell_7((650-492+(1*164)),(350+230-(5*92)),164,92);Text t_cell_7((650-492+(1*164)),(350+230-(5*92)),"Online Start-Up");
        Rectangle cell_8((650-492+(2*164)),(350+230-(5*92)),164,92);Text t_cell_8((650-492+(2*164)),(350+230-(5*92)),"Technological Start-Up");
        Rectangle cell_9((650-492+(3*164)),(350+230-(5*92)),164,92);
        Rectangle cell_10((650-492+(4*164)),(350+230-(5*92)),164,92);Text t_cell_10((650-492+(4*164)),(350+230-(5*92)),"Research Project");
        Rectangle cell_11((650-492+(5*164)),(350+230-(5*92)),164,92);Text t_cell_11((650-492+(5*164)),(350+230-(5*92)),"Summer Project");
        Rectangle cell_12((650-492+(6*164)),(350+230-(5*92)),164,92);
        Rectangle cell_13((650-492+(6*164)),(350+230-(4*92)),164,92);Text t_cell_13((650-492+(6*164)),(350+230-(4*92)),"Educational Start-Up");
        Rectangle cell_14((650-492+(6*164)),(350+230-(3*92)),164,92);Text t_cell_14((650-492+(6*164)),(350+230-(3*92)),"Research Project");
        Rectangle cell_15((650-492+(6*164)),(350+230-(2*92)),164,92);Text t_cell_15((650-492+(6*164)),(350+230-(2*92)),"Educational Start-Up");
        Rectangle cell_16((650-492+(6*164)),(350+230-(1*92)),164,92);Text t_cell_16((650-492+(6*164)),(350+230-(1*92)),"Online Start-Up");
        Rectangle cell_17((650-492+(6*164)),(350+230-(0*92)),164,92);
        Rectangle cell_18((650-492+(5*164)),(350+230-(0*92)),164,92);Text t_cell_18((650-492+(5*164)),(350+230-(0*92)),"Personal Project");
        Rectangle cell_19((650-492+(4*164)),(350+230-(0*92)),164,92);Text t_cell_19((650-492+(4*164)),(350+230-(0*92)),"Summer Project");
        Rectangle cell_20((650-492+(3*164)),(350+230-(0*92)),164,92);
        Rectangle cell_21((650-492+(2*164)),(350+230-(0*92)),164,92);Text t_cell_21((650-492+(2*164)),(350+230-(0*92)),"Online Start-Up");
        Rectangle cell_22((650-492+(1*164)),(350+230-(0*92)),164,92);Text t_cell_22((650-492+(1*164)),(350+230-(0*92)),"Personal Project");

        Text t_cell_17((650-492+(6*164)),(350+230-(0*92)),"GIVE A TREAT");
        Text t_cell_20((650-492+(3*164)),(350+230-(0*92)),"CHANCE");
        Text t_cell_1((650-492+(0*164)),(350+230-(0*92)),"START");
        Text t_cell_6((650-492+(0*164)),(350+230-(5*92)),"ENJOY A TREAT");
        Text t_cell_9((650-492+(3*164)),(350+230-(5*92)),"CHANCE");
        Text t_cell_12((650-492+(6*164)),(350+230-(5*92)),"DC++");

        // invest button
        Rectangle button_invest(650,295,200,40);
        Text t_invest(650,295,"INVEST");

        //buy button
        Rectangle button_buy(500,360,100,40);
        Text t_buy(500,360,"BUY");

        //roll button
        Rectangle button_roll(800,360,100,40);
        Text t_roll(800,360,"ROLL");

        //end turn button
        Rectangle button_turn(1215,660,100,40);
        Text t_turn(1215,660,"END TURN");

        //dice rectangle
        Rectangle dice(650,220,75,75);
        dice.setColor(COLOR(153,51,255));
        dice.setFill(true);
        Engine();
}

//for checking the clicks on the canvas

void checkClick()
{

    while(true)
    {
        endTurn = false;

        int clickbox=getClick(); //storing the click position as 65536*Xposition + Yposition
        int p=clickbox/65536;
        int q=clickbox%65536;

        if(p>550 && p<750 && q>275 && q<315 && rolled && (cells[currPosition].owner==currPlayer) && !turnCompleted
           && currPosition!=0 && currPosition!=5&& currPosition!=8&& currPosition!=11&& currPosition!=16&& currPosition!=19)
            /*Invest is clicked*/
        {
            Rectangle temp(650,295,200,40);
            // a temporary rectangle to indicate that
            //the box has been clicked
            temp.setColor(COLOR(160,160,160));
            temp.setFill(true);
            wait(0.1);
            temp.hide();
            int localCheck = MessageBox(NULL,"Do you want to invest in this Property \t\t","Question",MB_YESNO|MB_ICONQUESTION);
            if(localCheck==IDYES)
            {
                invest();
                cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                cout<<" "<<endl;
                endTurn = 1;
                break;
            }
        }

        else if(p>450 && p<550 && q>340 && q<380 && rolled && cells[currPosition].owner==-1 && !turnCompleted
                && currPosition!=0 && currPosition!=5&& currPosition!=8&& currPosition!=11&& currPosition!=16&& currPosition!=19)
                    /*Buy is clicked*/
        {
            Rectangle temp(500,360,100,40);
            // a temporary rectangle to indicate that
            //the box has been clicked
            temp.setColor(COLOR(160,160,160));
            temp.setFill(true);
            wait(0.1);
            temp.hide();

            // displays message box
            int localCheck = MessageBox(NULL,"Do you want to buy this Property \t\t","Question",MB_YESNO|MB_ICONQUESTION);
            if(localCheck==IDYES)
            {
                buy();
                checkClickBuy = true;
                cout<<currPlayer<<" money is: "<<players[currPlayer].money<<endl;
                cout<<currPlayer<<" time is: "<<players[currPlayer].time<<endl;
                cout<<" "<<endl;
                endTurn = 1;
                break;
            }
        }

        else if(p>750 && p<850 && q>340 && q<380 && (!rolled))/*Roll is clicked*/
        {
            Rectangle temp(800,360,100,40);
            // a temporary rectangle to indicate that
            //the box has been clicked
            temp.setColor(COLOR(160,160,160));
            temp.setFill(true);
            wait(0.1);
            temp.hide();

            rolled = true;
            srand(time(NULL));
            diceRoll = (rand()%6)+1;
            break;
        }

        else if(p>1165 && p<1265 && q>640 && q<680 && rolled)/*End Turn is clicked*/
        {
            Rectangle temp(1215,660,100,40);
            // a temporary rectangle to indicate that
            //the box has been clicked
            temp.setColor(COLOR(160,160,160));
            temp.setFill(true);
            wait(0.1);
            temp.hide();

            endTurn = true;break;
        }

        else
        {
            for(int i=0;i<22;i++)
            {
                if(p>cells[i].xCentre-(cells[i].length)/2 && p<cells[i].xCentre+(cells[i].length)/2
                   && q>cells[i].yCentre-(cells[i].breadth)/2 && q<cells[i].yCentre+(cells[i].breadth)/2)
                // evaluates to true if the click position is inside the i'th cell
                {
                    Rectangle temp(cells[i].xCentre,cells[i].yCentre,cells[i].length,cells[i].breadth);
                    temp.setColor(COLOR(160,160,160));
                    // a temporary rectangle to indicate that
                    //the box has been clicked
                    temp.setFill(true);
                    wait(0.1);
                    temp.hide();

                    cells[i].updateInfoString();
                    MessageBox(NULL,cells[i].info,"Information",MB_OK);
                }
            }
            for(int i=0;i<4;i++)
            {
                if(p>players[i].xCentre-(players[i].length)/2 && p<players[i].xCentre+(players[i].length)/2
                   && q>players[i].yCentre-(players[i].breadth)/2 && q<players[i].yCentre+(players[i].breadth)/2)
                   {
                        //evaluates to true if the click position is inside a player's box
                        Rectangle temp(players[i].xCentre,players[i].yCentre,players[i].length,players[i].breadth);
                        // a temporary rectangle to indicate that
                        //the box has been clicked
                        temp.setColor(COLOR(160,160,160));
                        temp.setFill(true);
                        wait(0.1);
                        temp.hide();

                        if(checkIfPlaying(i))
                        {
                            players[i].updateInfoString();
                            MessageBox(NULL,players[i].info,"Information",MB_OK);
                        }
                        else MessageBox(NULL,"This Player is out of the game","Information",MB_OK|MB_ICONERROR);
                   }
            }
        }
    }
}


void layout() // the initial screen
{
    initCanvas("IITB Monopoly",1300,700);

    Rectangle start(650,200,500,70); // start button
    Text start1(650,200,"Game On!");

    start1.setColor(COLOR("blue"));
    start1.setFill(true);

    Rectangle instr(650,500,500,70); // instruction button
    Text instr1(650,500,"How to Play??");

    instr1.setColor(COLOR("red"));
    instr1.setFill(true);

    int clickpos=getClick();
    //stores click position as 65536*Xposition + Yposition
    int a=clickpos/65536;
    int b=clickpos%65536;

    while(!(a<900 && a>400 && b<235 && b>165) && !(a>400 && a<900 && b>465 && b<535))/*when clicked outside the boxes the canvas does not close*/
    {
        clickpos=getClick();
        //stores click position as 65536*Xposition + Yposition
        a=clickpos/65536;
        b=clickpos%65536;
    }

    if(a<900 && a>400 && b<235 && b>165)
    {

        Rectangle temp1(650,200,500,70);
        temp1.setColor(COLOR(160,160,160));
        temp1.setFill(true);
        wait(0.1);
        temp1.hide();

        start.hide();
        start1.hide();
        instr.hide();
        instr1.hide();

        Rectangle canvas(650,350,1300,700);

        canvas.setColor(COLOR(255,255,204));
        canvas.setFill(true);

        board();

    }

    else if(a>400 && a<900 && b>465 && b<535)
    {
        Rectangle temp1(650,500,500,70);
        temp1.setColor(COLOR(160,160,160));
        temp1.setFill(true);
        wait(0.1);
        temp1.hide();

        start.hide();
        start1.hide();
        instr.hide();
        instr1.hide();

        Rectangle canvas(650,350,1300,700);

        canvas.setColor(COLOR(255,255,204));
        canvas.setFill(true);

        //Instructions

        Text t_instr_1(650,20,"INSTRUCTIONS");
        Text t_instr_2(330,80,"1. The game consists of four players where each one starts with 50 hours of time and an amount of");
        Text t_instr_3(90,96,"Rs 50,000 with him.");
        Text t_instr_4(293,114,"2. The board consists different cells within which the player's pawn will move and land.");
        Text t_instr_5(329,132,"3. The cells consist of a Start Box, Start-Ups, Projects, Chance Boxes, a DC++ Box, a 'Enjoy a Tre'");
        Text t_instr_6(125,148,"-at box and a 'Give a Treat' box.");
        Text t_instr_7(251,166,"4. The various jobs to be done when u land on these boxes are as follows:");
        Text t_instr_8(280,182,"(a) Start Box :- Each time you cross this box, collect Rs 5000 and earn 5 hours.");
        Text t_instr_9(281,200,"(b) Start-Ups :- There are three types of start-ups which are defined as follows :-");
        Text t_instr_10(330,218,"(i) Educational Start-Up :- There are three of these and consist of the following details -");
        Text t_instr_11(360,234,"Buy => Money -3000 ; Invest => Time -2 & Money -1000 ; Initial Rent => Money +1000 ;");
        Text t_instr_12(360,250,"After each Investment, Rent => Time ++1 & Money ++800");
        Text t_instr_13(330,268,"(ii) Technological Start-Up :- There are two of these and consist of the following details -");
        Text t_instr_14(360,284,"Buy => Money -5000 ; Invest => Time -3 & Money -1500 ; Initial Rent => Money +1500 ;");
        Text t_instr_15(360,300,"After each Investment, Rent => Time ++2 & Money ++1000");
        Text t_instr_16(313,318,"(iii) Online Start-Up :- There are three of these and consist of the following details -");
        Text t_instr_17(350,334,"Buy => Money -2000 ; Invest => Time -4 & Money -800 ; Initial Rent => Money +500 ;");
        Text t_instr_18(358,350,"After each Investment, Rent => Time ++3 & Money ++500");
        Text t_instr_19(275,368,"(c) Projects :- There are three types of projects which are defined as follows :-");
        Text t_instr_20(315,386,"(i) Personal Project :- There are three of these and consist of the following details -");
        Text t_instr_21(319,402,"Buy => Time -3 ; Invest => Time -2 & Money -3000 ; Initial rent => Time +1 ;");
        Text t_instr_22(360,418,"After each Investment, Rent => Time ++1 & Money ++500");
        Text t_instr_23(310,436,"(ii) Summer Project :- There are two of these and consist of the following details -");
        Text t_instr_24(319,452,"Buy => Time -4 ; Invest => Time -2 & Money -1000 ; Initial Rent => Time +2 ;");
        Text t_instr_25(360,468,"After each Investment, Rent => Time ++1 & Money ++500");
        Text t_instr_26(318,486,"(iii) Research Project :- There are three of these and consist of the following details -");
        Text t_instr_27(315,502,"Buy => Time -5 ; Invest => Time -2 & Money -500 ; Initial Rent => Time +2 ;");
        Text t_instr_28(360,518,"After each Investment, Rent => Time ++1 & Money ++500");
        Text t_instr_29(305,536,"(d) Chance :- Pick the point no. depending upon the no. on the dice and do as follows :-");
        Text t_instr_30(337,554,"1. Laptop stops working => Time +2 & Money -500");
        Text t_instr_31(337,572,"2. Miss lectures => Time+1");
        Text t_instr_32(337,590,"3. Canteen => Time -1 & Money -200");
        Text t_instr_33(337,608,"4. Girlfriend's bday!!!! => Time -5 & Money -1000");
        Text t_instr_34(337,626,"5. Sell your stuff => Money +1000");
        Text t_instr_35(337,644,"6. Last night before exam. Study!!! => Time -3");
        Text t_instr_36(960,80,"(e) DC++ :- When you land at this place you have to do the following :-");
        Text t_instr_37(960,96,"Skip 3 Turns");
        Text t_instr_38(937,114,"(f) Enjoy A Treat :- When you land here you gain the following :-");
        Text t_instr_39(937,130,"(Money +1000) from each player");
        Text t_instr_40(935,148,"(g) Give a Treat :- When you land here you lose the following :-");
        Text t_instr_41(935,164,"(Money -1000) to each player");
        Text t_instr_42(970,182,"5. To gain information about any cell or block, click onto it and the info pops-up");
        Text t_instr_43(1010,200,"6. In order to get the amount of money and time left with a player, click on the block that the");
        Text t_instr_44(790,216,"player belongs to.");
        Text t_instr_45(900,234,"7. End of the Game is defined in the following two ways :-");
        Text t_instr_46(928,252,"(a) When any of the players crosses the amount of Rs 80,000");
        Text t_instr_47(904,270,"(b) When all the players except one become bankrupt.");


        Rectangle start_game(1230,670,100,40);
        Text t_start_game(1230,670,"START GAME");



        while(true)
        {
            int clickpos2=getClick();
            //stores click position as 65536*Xposition + Yposition
            int x=clickpos2/65536;
            int y=clickpos2%65536;

            if(x>1180 && x<1280 && y>650 && y<690)
            {
                Rectangle temp2(1230,670,100,40);
                temp2.setColor(COLOR(160,160,160));
                temp2.setFill(true);
                wait(0.1);
                temp2.hide();

                start_game.hide();
                t_start_game.hide();
                t_instr_1.hide();
                t_instr_2.hide();
                t_instr_3.hide();
                t_instr_4.hide();
                t_instr_5.hide();
                t_instr_6.hide();
                t_instr_7.hide();
                t_instr_8.hide();
                t_instr_9.hide();
                t_instr_10.hide();
                t_instr_11.hide();
                t_instr_12.hide();
                t_instr_13.hide();
                t_instr_14.hide();
                t_instr_15.hide();
                t_instr_16.hide();
                t_instr_17.hide();
                t_instr_18.hide();
                t_instr_19.hide();
                t_instr_20.hide();
                t_instr_21.hide();
                t_instr_22.hide();
                t_instr_23.hide();
                t_instr_24.hide();
                t_instr_25.hide();
                t_instr_26.hide();
                t_instr_27.hide();
                t_instr_28.hide();
                t_instr_29.hide();
                t_instr_30.hide();
                t_instr_31.hide();
                t_instr_32.hide();
                t_instr_33.hide();
                t_instr_34.hide();
                t_instr_35.hide();
                t_instr_36.hide();
                t_instr_37.hide();
                t_instr_38.hide();
                t_instr_39.hide();
                t_instr_40.hide();
                t_instr_41.hide();
                t_instr_42.hide();
                t_instr_43.hide();
                t_instr_44.hide();
                t_instr_45.hide();
                t_instr_46.hide();
                t_instr_47.hide();
                board(); // calls the main board
            }


        }

    }

}
//end of graphics code

