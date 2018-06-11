#ifndef DECK_CPP_INCLUDED
#define DECK_CPP_INCLUDED
#include "Player.h"

//everything below is to keep track of player statistics
Player::Player(string N, int mH)
{
    name = N;
    maxHit = mH;
}

string Player::getName()
{
    return name;
}

void Player::addWin()
{
    wins += 1;
}

void Player::addTie()
{
    ties += 1;
}

void Player::addLoss()
{
    losses += 1;
}

int Player::getMaxHit()
{
    return maxHit;
}

int Player::getWins()
{
    return wins;
}

int Player::getTies()
{
    return ties;
}

int Player::getLosses()
{
    return losses;
}


#endif
