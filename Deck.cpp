#ifndef DECK_CPP_INCLUDED
#define DECK_CPP_INCLUDED
#include "Deck.h"

//add a Card to the deck
void Deck::addCard(Card* card)
{
    DeckOfCards.push(card); //pushes card to the top of the stack
}

//deals Card out to a player using pass by reference parameter
void Deck::dealCard(Card* &nextCard)
{
    //check if Deck is empty first, otherwise accessing invalid memory
    //break from function if empty
    if (DeckOfCards.empty())
        return;
    else
    {
        //Card reference will be updated with card on top of deck
        //then deck will pop card from top
        nextCard = DeckOfCards.top();
        DeckOfCards.pop();
    }
}

//checks if deck is empty
bool Deck::isEmpty()
{
    return DeckOfCards.empty();
}

#endif
