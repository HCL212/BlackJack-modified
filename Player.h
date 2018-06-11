#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Hand.h"

//keeps track of player statistics, self explanatory
class Player{
public:
    Player(string N, int mH);
    string getName();
    void addWin();
    void addTie();
    void addLoss();
    int getMaxHit();
    int getWins();
    int getTies();
    int getLosses();
    Hand playerHand;
private:
    string name;
    int wins;
    int ties;
    int losses;
    int maxHit;
};

#endif
