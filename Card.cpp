#ifndef DECK_CPP_INCLUDED
#define DECK_CPP_INCLUDED
#include "Card.h"

//set Card* type variable to Number, Word, or Symbol for reference
void Card::setType(char newType)
{
    type = newType;
}

//get Card* type variable
char Card::getType()
{
    return type;
}

//sets the value of the card
void Card::setValue(int newValue)
{
    value = newValue;
}

//gets value of the card
int Card::getValue()
{
    return value;
}

#endif
