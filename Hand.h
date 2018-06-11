#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED
#include "Deck.h"

//functions for the player's hand
class Hand{
public:
    void addCardToHand(Card* Card); //add card to hand from deck
    void clearHand(); //make hand empty
    void toggleToHigh(); //set SYMBOL card value to high
    void toggleToLow(); //set SYMBOL card value to low
    void getIndividualCardValues(); //retrieve all card values from hand
    int getHandValue(); //get TOTAL hand value
    int getNumOfCards(); //get number of cards in hand currently
private:
    vector<Card*> PlayerHand; //vector of cards for the player's hand
    int handValue; //hand's value
    int numOfCards; //number of cards in hand

};

#endif
