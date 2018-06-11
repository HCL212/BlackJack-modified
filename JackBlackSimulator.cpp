#ifndef JackBlackDeckSIMULATOR_CPP_INCLUDED
#define JackBlackDeckSIMULATOR_CPP_INCLUDED
#include "JackBlackSimulator.h"

//retrieve cards from file and store in a stack
void JackBlackSimulator::getDeckCards(string deckData)
{
    string card;
    ifstream inputfile;
    inputfile.open(deckData);
    if (!inputfile.is_open())
    {
        cout << "ERROR" << endl;
    }

    //reads from the inputfile, and creates correct cards for the deck
    //based on the file
    while(getline(inputfile,card))
    {
        if (card[0] == 'N')
        {
            //parses the card string and gathers the values
            string number;
            unsigned int pos = 2;
            while(pos < card.length())
            {
                number += card[pos];
                pos++;
            }
            //creates a number card to store in the deck
            int value = stoi(number);
            NumberCard* nCard = new NumberCard(value);
            JackBlackDeck.addCard(nCard);
        }
        if (card[0] == 'W')
        {
            string word;
            unsigned int pos = 2;
            while(pos < card.length())
            {
                word += card[pos];
                pos++;
            }
            //creates a word card to store in the deck
            //values determined from the word constructor
            WordCard* wCard = new WordCard(word);
            JackBlackDeck.addCard(wCard);
        }
        if (card[0] == 'S')
        {
            //parses the string card and splits it up accordingly
            char symbol = card[2];
            string number1;
            string number2;
            unsigned int pos = 4;
            while(card[pos] != ' ' && pos < card.length())
            {
                number1 += card[pos];
                pos++;
            }
            pos++;
            while(pos < card.length())
            {
                number2 += card[pos];
                pos++;
            }
            //creates a symbol card and stores the symbol, low value, and high value
            int lowValue = stoi(number1);
            int highValue = stoi(number2);
            SymbolCard* sCard = new SymbolCard(symbol, lowValue, highValue);
            JackBlackDeck.addCard(sCard);
        }
    }
    //closes the file
    inputfile.close();
}

//retrieve players from file
void JackBlackSimulator::getPlayers(string playerData)
{
    string player;
    string numPlayers;
    string name;
    string maxHit;
    ifstream inputfile;
    inputfile.open(playerData);
    if (!inputfile.is_open())
    {
        cout << "ERROR" << endl;
    }

    //reads first line to get number of players
    if (getline(inputfile,numPlayers))
    {
        numOfPlayers = stoi(numPlayers);
    }
             
    //continues reading the file
    while(getline(inputfile,player))
    {
        //parses the string and gathers player names and max hit #'s
        if (player[0] >= 'A' && player[0] <= 'Z')
        {
            unsigned int pos = 0;
            while (player[pos] != ' ' && pos < player.length())
            {
                name += player[pos];
                pos++;
            }
            pos++;
            while (pos < player.length())
            {
                maxHit += player[pos];
                pos++;
            }
            int maxValue = stoi(maxHit);
            Player* PlayerData = new Player(name, maxValue);
            JackBlackPlayers.push_back(PlayerData);
            name = "";
            maxHit = "";
        }
    }
    //closes the file
    inputfile.close();
}

//plays a round for the player
void JackBlackSimulator::playerTurn(Player* currPlayer)
{
    //while loop keeps hitting for the player until they reach their max hit
    //or they bust
    while (currPlayer->playerHand.getHandValue() <= currPlayer->getMaxHit())  
    {
        Card* temp;
        JackBlackDeck.dealCard(temp);
        //error checking to make sure game doesn't continue if we're out of cards
        if (JackBlackDeck.isEmpty())
        {
            //total hits deduct by 1 to correct for error at the end of the loop
            totalHits--;
            return;
        }
        //logic to determine what values of symbol cards to use
        currPlayer->playerHand.addCardToHand(temp);
        currPlayer->playerHand.toggleToHigh();
        if (currPlayer->playerHand.getHandValue() > 31)
            currPlayer->playerHand.toggleToLow();

        //stat tracker
        totalHits++;
    }
}

//simulates the whole game
void JackBlackSimulator::playJB(string deckData, string playerData)
{
    //retrieve deck data and player data
    this->getDeckCards(deckData);
    this->getPlayers(playerData);

    //lets user know who is playing and their max hit
    cout << "Running simulation with players:" << endl;
    for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
    {
        cout << JackBlackPlayers.at(i)->getName();
        cout << " (Max Hit: " << JackBlackPlayers.at(i)->getMaxHit() << ")"<< endl;
    }

    cout << endl;
    
    //plays the game while the deck is not empty
    while (!JackBlackDeck.isEmpty())
    {
        //distribute one card to each person first as per the rules
        for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
        {
            Card* temp;
            JackBlackDeck.dealCard(temp); 
            JackBlackPlayers.at(i)->playerHand.addCardToHand(temp);
        } 

        //play the game for each player until the round is over
        for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
        {
            playerTurn(JackBlackPlayers.at(i));
            //break out of loop when deck is empty
            if (JackBlackDeck.isEmpty())
            {
                //when deck is empty, we output stats
                roundStats();
                return;
            } 
        }

        rounds++;
        cout << "ROUND " << rounds << endl;

        //outputs the round statistics of each player
        for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
        {
            cout << JackBlackPlayers.at(i)->getName() << ": ";
            JackBlackPlayers.at(i)->playerHand.getIndividualCardValues();
            cout << "TOTAL: " << JackBlackPlayers.at(i)->playerHand.getHandValue();
            if (JackBlackPlayers.at(i)->playerHand.getHandValue() > 31)
                cout << " (BUST).";
            else
                cout << ".";
            cout << endl; 
        }

        //function to determine who the winners/losers/tie's are, explained further down
        determineWinner();

        //clear each player's hand for the next round
        for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
        {
            JackBlackPlayers.at(i)->playerHand.clearHand();
        }
        cout << endl;
    }
}

//keeps track of stats and outputs the stats of the game
void JackBlackSimulator::roundStats()
{
    //outputs wins/losses/ties for each player
    cout << "FINAL TALLY" << endl;
    for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
    {
        cout << JackBlackPlayers.at(i)->getName() << ". ";
        cout << "WINS: " << JackBlackPlayers.at(i)->getWins() << ". ";
        cout << "LOSSES: " << JackBlackPlayers.at(i)->getLosses() << ". ";
        cout << "TIES: " << JackBlackPlayers.at(i)->getTies() << "." << endl;
    }

    cout << endl;
    double avgWinCards = totalCardsInWinHands/winningHands;
    double avgLoseCards = totalCardsInLoseHands/losingHands;
    
    //outputs the averages/statistics of the game
    cout << "GAME ANALYSIS" << endl;
    cout << "Average number of hits per player per round: ";
    cout << setprecision(2) << fixed << totalHits/rounds/numOfPlayers << endl;
    cout << "Average number of cards in winning hands: "; 
    cout << setprecision(2) << fixed << avgWinCards << "." << endl;
    cout << "Average number of cards in losing hands: ";
    cout << setprecision(2) << fixed << avgLoseCards << "." << endl;
}

//figure out who won each round
void JackBlackSimulator::determineWinner()
{
    //check if deck is empty, if so, break
    if (JackBlackDeck.isEmpty())
        return;

    string winnerName;
    unsigned int winnerIndex;
    int tieCount = 0;
    int winningValue = 0;

    //loops to determine who won, and who tied
    for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
    {
        if (JackBlackPlayers.at(i)->playerHand.getHandValue() <= 31
            && JackBlackPlayers.at(i)->playerHand.getHandValue() > winningValue)
        {
            tieCount = 0;
            winnerIndex = i;
            winnerName = JackBlackPlayers.at(i)->getName();
            winningValue = JackBlackPlayers.at(i)->playerHand.getHandValue();
        }

        else if (JackBlackPlayers.at(i)->playerHand.getHandValue() == winningValue)
        {
            tieCount++;
            winnerName += ", ";
            winnerName += JackBlackPlayers.at(i)->getName();
        }
    }

    //if/else statements to add wins/losses/ties to each player
    //decided by the previous loops
    //also adds # of cards to the totalCardsInWin/LoseHands variables to stat track
    if (tieCount == 0)
    {
        cout << "WINNER: " << winnerName << endl;
        for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
        {
            if (i == winnerIndex)
            {
                JackBlackPlayers.at(i)->addWin();
                addToWinHands(JackBlackPlayers.at(i)->playerHand.getNumOfCards());
            }
            else
            {
                JackBlackPlayers.at(i)->addLoss();
                addToLoseHands(JackBlackPlayers.at(i)->playerHand.getNumOfCards());
            }
        }
    }   
    else
    {
        cout << "TIED: " << winnerName << endl;
        for (unsigned int i = 0; i < JackBlackPlayers.size(); i++)
        {
            if (JackBlackPlayers.at(i)->playerHand.getHandValue() == winningValue)
                JackBlackPlayers.at(i)->addTie();
            else
            {
                JackBlackPlayers.at(i)->addLoss();
                addToLoseHands(JackBlackPlayers.at(i)->playerHand.getNumOfCards());
            }
        }
    }   
}

//adds winning hands stats to the variables
void JackBlackSimulator::addToWinHands(int value)
{
    winningHands++;
    totalCardsInWinHands += value;
}

//adds losing hands stats to the variables
void JackBlackSimulator::addToLoseHands(int value)
{
    losingHands++;
    totalCardsInLoseHands += value;
}

#endif
