#ifndef WORDCARD_H_INCLUDED
#define WORDCARD_H_INCLUDED
#include "Card.h"

//word card class derived from Card class
class WordCard : public Card{
public:
    WordCard(string word); //constructor sets the values based on the word
    string getWord(); //retrieves the word of the card
private:
    int vowels;
    int consonants;
    string wordString;
};


#endif
