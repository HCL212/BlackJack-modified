#ifndef JACKBLACKSIMULATOR_H_INCLUDED
#define JACKBLACKSIMULATOR_H_INCLUDED
#include "Player.h"

//simulates the JackBlack game
class JackBlackSimulator{
public:
    void getDeckCards(string deckData); //retrieve deck from file
    void getPlayers(string playerData); //retrieve players from file
    void playerTurn(Player* currPlayer); //plays the round for current player
    void playJB(string deckData, string playerData); //simulates the whole game
    void roundStats(); //keeps track of stats and outputs the stats of the whole game
    void determineWinner(); //figure out who won each round
    void addToWinHands(int value); //adds winning hands and # of cards in winning hands
    void addToLoseHands(int value); //adds losing hands and # of cards in losing hands
private:
    int numOfPlayers = 0; //# of players
    int rounds = 0; //# of rounds after game is over
    double winningHands = 0; //total # of winning hands
    double losingHands = 0; // total # of losing hands
    double totalCardsInWinHands = 0; //total # of cards in winning hands
    double totalCardsInLoseHands = 0; // total # of cards in losing hands
    double totalHits = 0; // total # every player hit throughout the game
    Deck JackBlackDeck; //the game deck
    vector<Player*> JackBlackPlayers; //the game's players
};

#endif
