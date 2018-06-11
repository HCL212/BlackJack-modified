#ifndef SYMBOLCARD_H_INCLUDED
#define SYMBOLCARD_H_INCLUDED
#include "Card.h"

//symbol card, derived from Card class
class SymbolCard : public Card{
public:
    SymbolCard(char sym, int lowV, int highV); //constructor for creating a card
    int getValue(); //gets value depending on if the card is currently high or low
    int getLowValue(); //gets low value
    int getHighValue(); //gets high value
    void lowORhigh(string lowORhigh); //toggle switch values
    void setValue(int lowV, int highV); //sets value for both low/high
    char getSymbol(); //gets symbol for the card
private:
    char symbol;
    int lowValue;
    int highValue;
    string X = "low"; //default set to low as per specs
};

#endif
