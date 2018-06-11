#include "JackBlackSimulator.h"

int main(int argc, char* argv[]){

    string fileName;
    string playerData = "defaultPlayers.data";
    string deckData = "defaultDeck.data";

    //if statements to determine which variable to store the argv[] file names
    if (argc > 1)
    {
        fileName = argv[1];
        for (unsigned int i = 0; i < fileName.size(); i++)
        {
           if (fileName[i] == 'p' || fileName[i] == 'P')
           {
                if (fileName[i+1] == 'l' || fileName [i+1] == 'L')
                    playerData = fileName;
           }
        }
        for (unsigned int i = 0; i < fileName.size(); i++)
        {
            if (fileName[i] == 'd' || fileName[i] == 'D')
            {
                if (fileName[i+1] == 'e' || fileName[i+1] == 'E')
                    deckData = fileName;
            }
        }
    }
    if (argc > 2)
    {
        fileName = argv[2];
        for (unsigned int i = 0; i < fileName.size(); i++)
        {
           if (fileName[i] == 'p' || fileName[i] == 'P')
           {
                if (fileName[i+1] == 'l' || fileName [i+1] == 'L')
                    playerData = fileName;
           }
        }
        for (unsigned int i = 0; i < fileName.size(); i++)
        {
            if (fileName[i] == 'd' || fileName[i] == 'D')
            {
                if (fileName[i+1] == 'e' || fileName[i+1] == 'E')
                    deckData = fileName;
            }
        }
    }

    if (deckData == "defaultDeck.data")
        cout << "No deck file provided. Using default deck file instead." << endl;
    if (playerData == "defaultPlayers.data")
        cout << "No players file provided.  Using default players file instead." << endl;

    //plays the whole game
    JackBlackSimulator timeToPlay;
    timeToPlay.playJB(deckData, playerData);

}
