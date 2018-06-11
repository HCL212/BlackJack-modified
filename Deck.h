#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include "Card.h"
#include "NumberCard.h"
#include "WordCard.h"
#include "SymbolCard.h"

//functions for the game deck
class Deck{
public:
    void addCard(Card* card); //adds a Card to the deck
    void dealCard(Card* &nextCard); //deals Card out to a player
    bool isEmpty(); //checks if Deck is empty
private:
    stack<Card*> DeckOfCards; //stack used for deck
};



#endif
