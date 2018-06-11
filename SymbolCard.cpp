#ifndef SYMBOLCARD_CPP_INCLUDED
#define SYMBOLCARD_CPP_INCLUDED
#include "SymbolCard.h"

//constructor retrieves the symbol, low value, and high value
SymbolCard::SymbolCard(char sym, int lowV, int highV)
{
    setType('S');
    symbol = sym;
    setValue(lowV, highV);
}

//gets the value of the symbol card depending on if the card is set to low or high
int SymbolCard::getValue()
{
    if (X == "low")
        return lowValue;
    else if (X == "high")
        return highValue;
    else
        return 0;
}

//get low value
int SymbolCard::getLowValue()
{
    return lowValue;
}

//get high value
int SymbolCard::getHighValue()
{
    return highValue;
}

//toggles the card value between low and high
void SymbolCard::lowORhigh(string lowORhigh)
{
    if (lowORhigh == "low")
        X = lowORhigh;
    if (lowORhigh == "high")
        X = lowORhigh;
}

//store the values in the variables
void SymbolCard::setValue(int lowV, int highV)
{
    lowValue = lowV;
    highValue = highV;
}

//returns the symbol of the card
char SymbolCard::getSymbol()
{
    return symbol;
}

#endif
