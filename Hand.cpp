#ifndef HAND_CPP_INCLUDED
#define HAND_CPP_INCLUDED
#include "Hand.h"

//add card to a hand from the deck
void Hand::addCardToHand(Card* Card)
{
    PlayerHand.push_back(Card);
}

//clears hand of all cards
void Hand::clearHand()
{
    //check if player's hand is empty first
    //if not, remove card from the back of the hand
    while (!PlayerHand.empty())
        PlayerHand.pop_back();
}

//set all SYMBOL cards to their high value
void Hand::toggleToHigh()
{
    //check if player's hand is empty, then execute loop if not
    if (!PlayerHand.empty())
    {
        //loops the hand and switches all SYMBOL cards to high
        for (unsigned int i = 0; i < PlayerHand.size(); i++)
        {
            if (PlayerHand.at(i)->getType() == 'S')
                PlayerHand.at(i)->lowORhigh("high");
        }
    }
}

//set all SYMBOL cards to their low value
void Hand::toggleToLow()
{
    //check if player's hand is empty, then execute loop if not
    if (!PlayerHand.empty())
    {
        //loops the hand and switches all SYMBOL cards to low
        for (unsigned int i = 0; i < PlayerHand.size(); i++)
        {
            if (PlayerHand.at(i)->getType() == 'S')
                PlayerHand.at(i)->lowORhigh("low");
        }
    }
}

//retrieve all individual card values from player's hand
//function used for the outputting portion of the game
void Hand::getIndividualCardValues()
{
    //loop iterates through player's hand and gives out value of each card
    //depending on their type
    for (unsigned int i = 0; i < PlayerHand.size(); i++)
    {
        if (PlayerHand.at(i)->getType() == 'N')
            cout << PlayerHand.at(i)->getValue();
        if (PlayerHand.at(i)->getType() == 'W')
        {
            cout << PlayerHand.at(i)->getWord() << " (" << 
            PlayerHand.at(i)->getValue() << ")";
        }     
        if (PlayerHand.at(i)->getType() == 'S')
        {
            cout << PlayerHand.at(i)->getSymbol() << " (";
            cout << PlayerHand.at(i)->getLowValue() << "/";
            cout << PlayerHand.at(i)->getHighValue() << " --> " ;
            cout << PlayerHand.at(i)->getValue() << ")";
        }
        if (i != PlayerHand.size()-1)
            cout << ", ";
        else
            cout << ". ";
    }
}

//get TOTAL hand value
int Hand::getHandValue()
{
    handValue = 0;
    //check if player's hand is empty
    //if not, loop through and add all the values together
    if (!PlayerHand.empty())
    {
        for (unsigned int i = 0; i < PlayerHand.size(); i++)
        {
            handValue += PlayerHand.at(i)->getValue();
        }
    }
    return handValue;
}

//gets the number of cards in a player's hand
int Hand::getNumOfCards()
{
    numOfCards = 0;
    //if hand isn't empty, loops through and counts how many cards
    if (!PlayerHand.empty())
    {
        for (unsigned int i = 0; i < PlayerHand.size(); i++)
        {
            numOfCards++;
        }
    }
    return numOfCards;
}

#endif
