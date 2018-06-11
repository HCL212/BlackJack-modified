#ifndef NUMBERCARD_H_INCLUDED
#define NUMBERCARD_H_INCLUDED
#include "Card.h"

//number card class, constructor sets type and value
//derived from Card class
class NumberCard : public Card{
public:
    NumberCard(int cardValue)
    {
        setType('N');
        setValue(cardValue);
    }
};


#endif
