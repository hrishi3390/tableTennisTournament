//
//  main.cpp
//  TableTennisRunRate
//
//  Created by Hrishikesh Chaudhari on 22/11/18.
//  Copyright © 2018 Hrishikesh Chaudhari. All rights reserved.
//

#include <iostream>
#include <cmath>

#define GAMESCORE   21
using namespace std;

class Player
{
    string name;
    int score;
    bool win{false};
    double runRate{1};
    double totalRunRate{0};
    int numberOfWins{0};
    int numberOfMatchesPlayed{0};
    
    
public:
    Player(){}
    Player(string name):name(name){
    }
    Player(const Player &p){
        cout<<"Copy constructor is called:"<<endl;
    }
    double getRunRate();
    string getName();
    void setScore(int score);
    int getScore();
    void setRunRate(double runR);
    void setWin(bool flag);
    int getNumberofWins();
    void matchPlayed();
    int getnumberOfMatchesPlayed();
    
    ~Player(){
        cout<<"player desctuctor is called"<<endl;
    }
    
};

class Match{
    
    Player *p1,*p2;
    
public:
    Match(Player &P1,int scoreP1, Player &P2, int scoreP2){
        p1 = &P1;
        p2 = &P2;
        p1->setScore(scoreP1);
        p2->setScore(scoreP2);
        calculateRunRate();
        p1->matchPlayed();
        p2->matchPlayed();
    }
    ~Match(){
        cout<<"Match destructor is called"<<endl;
    }
    
    string getMatchPlayerName(Player p1){
        return p1.getName();
    }
    void calculateRunRate(){
        
        double runRate;
        runRate = fabs((p1->getScore() - p2->getScore())/(double)GAMESCORE);
        
        if( p1->getScore() > p2->getScore() )
        {
            p1->setWin(true);
            p2->setWin(false);
        }
        else{
            p2->setWin(true);
            p1->setWin(false);
        }
        
        p1->setRunRate(runRate);
        p2->setRunRate(runRate);
    }
};

string Player :: getName(){
    return name;
}

int Player :: getnumberOfMatchesPlayed(){
    return this->numberOfMatchesPlayed;
}

void Player:: matchPlayed()
{
    numberOfMatchesPlayed++;
}


int Player :: getScore()
{
    return this->score;
}
int Player :: getNumberofWins()
{
    return this->numberOfWins;
}

void Player:: setScore(int score)
{
    this->score = score;
}
void Player:: setWin(bool flag){
    win = flag;
}

void Player:: setRunRate(double runR)
{
    if(win)
    {
        totalRunRate += runR;
        numberOfWins++;
    }
    else
    {
        totalRunRate -= runR;
    }
    
        
}

double Player:: getRunRate(){
    return totalRunRate;
}

int main(int argc, const char * argv[]) {
    
    int initialP1, scoreP1, initialP2, scoreP2;
    
    
  //  cin>>initialP1>>scoreP1>>initialP2>>scoreP2;
    
    
    
//*********************** NAME OF PLAYERS IN TOURNAMENT *********************//
   
    Player H("Hrishi");
    Player A("Anil");
    Player D("Dinesh");

//************************** MATHES PLAYED **********************************//
    
    
    
    
//*******************  DATE - 10/Dec/2018  **************************************//
    
    Match T1(H,16,D,21);
//    Match T2(D,19,A,21);
//    Match T3(H,19,A,21);
//    Match T4(H,20,D,22);
//    Match T5(D,22,A,20);
//    Match T6(H,22,A,24);
//    Match T7(H,12,D,21);
//    Match T8(D,11,A,21);
//    Match T9(H,21,A,19);
//    
//    
//    
//    //*******************  DATE - 11/Dec/2018  **************************************//
//    
//    Match T10(D,18,A,21);
//    Match T11(H,12,D,21);
//    Match T12(H,26,A,24);
//    
//
//    //*******************  DATE - 12/Dec/2018  **************************************//
//    
//    Match T13(H,19,A,21);
//    Match T14(D,19,A,21);
//    Match T15(H,7,D,21);
//    Match T16(H,15,A,21);
//    Match T17(D,19,A,21);
//    Match T18(H,21,D,17);
//
//    //*******************  DATE - 12/Dec/2018  **************************************//
//    
//    Match T19(D,18,A,21);
//    Match T20(H,21,D,16);
//    Match T21(H,16,A,21);
//    Match T22(D,18,A,21);
//    Match T23(H,16,A,21);
//    Match T24(H,21,D,14);
 //******************************* RESULT ***********************************//
    
    cout<<H.getName()<<" has " <<H.getNumberofWins()<<" wins("<<H.getnumberOfMatchesPlayed()<<") with run rate of : "<<H.getRunRate()<<endl;
    cout<<A.getName()<<" has " <<A.getNumberofWins()<<" wins("<<A.getnumberOfMatchesPlayed()<<") with run rate of : "<<A.getRunRate()<<endl;
    cout<<D.getName()<<" has " <<D.getNumberofWins()<<" wins("<<D.getnumberOfMatchesPlayed()<<") with run rate of : "<<D.getRunRate()<<endl;
    
    
    return 0;
}
