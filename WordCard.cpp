#ifndef WORDCARD_CPP_INCLUDED
#define WORDCARD_CPP_INCLUDED
#include "WordCard.h"

//constructor sets all the variables based on the word given
WordCard::WordCard(string word)
{
    wordString = word;
    setType('W');
    vowels = 0;
    consonants = 0;
    //determines how many vowels and consonants there are
    for (unsigned int i = 0; i < word.length(); i++)
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || 
            word[i] == 'o' || word[i] == 'u')
            vowels++;
        else
            consonants++;
    }
    //sums up the value of the word card
    vowels *= 2;
    int cardValue = (vowels+consonants)%16 + 1;
    setValue(cardValue);
}

//retrieves the word of the card if needed
string WordCard::getWord()
{
    return wordString;
}

#endif
