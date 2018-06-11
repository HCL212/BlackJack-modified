#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

//base class for cards, virtual functions used so derived classes can override and use
class Card{
public:
    virtual ~Card(){}
    virtual void setType(char newType); //set Card* type
    virtual char getType(); //get Card* type
    virtual void setValue(int newValue); //set Card* value
    virtual int getValue(); //get Card* value
    virtual int getLowValue(){return 0;} //made for SYMBOL card
    virtual int getHighValue(){return 0;} //made for SYMBOL card
    virtual void lowORhigh(string lowORhigh){} //made for SYMBOL card
    virtual string getWord(){ return "none";} //made for WORD card
    virtual char getSymbol(){ return 'a';} //made for SYMBOL card
private:
    int value; //value of the card
    char type; //type of the card
};

#endif
