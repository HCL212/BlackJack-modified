## BlackJack-modified (JackBlack)

JackBlack is a game similar to Blackjack.  The goal is to keep getting cards from the deck without going over 31.  Each player has their own risk in their max hit limit.  There are a varied amount of cards in each deck, and each deck has 3 types of cards.  
  
First is a number card which is just a simple card with a value.  Next up is word cards where their value is determined by how many vowels and consonants they have vowels x 2 + consonants%16 + 1.  Last is a symbol card which has a symbol, and a low value or a high value.  The kicker is that all your symbol cards in your hand must be ALL low or ALL high.    
At the beginning of each round, every player gets one card first, and then each player gets to hit (retrieve a card from the deck) until they are satisfied or they bust (going over 31), until the round is over.  
  
If no deck file and/or player files are provided, the default files will be used.  
  
[Relevant files]  
Card.h/cpp
Deck.h/cpp    
Hand.h/cpp    
JackBlackSimulator.h/cpp  
main.cpp  
makefile  
NumberCard.h  
Player.h/cpp  
SymbolCard.h/cpp  
WordCard.h/cpp  
defaultDeck.data  
defaultPlayers.data  
  
cmd: ./JackBlack  
cmd: ./JackBlack <Deck filename> <Player filename>  
  
The card class is the basis of the whole game.  The card class is the base class for the other card classes (number, word, card).  Virtual functions are created in the base class in order to use inheritance/polymorphism with the other card classes.  
  
The deck class uses the stack data structure to store the cards from the deck data file.  Since the deck data file's top line is the bottom of the deck, it makes it easy to use the pop function for the stack to store all the cards in the deck.  It uses the card class in order to have a stack of pointer cards.  
  
Next is the hand class which also relies on the Card class.  The hand is simply a vector of card pointers, because it's easy to iterate through to grab any valuable information, and easy to add/remove cards as needed.  It also relies on the deck class to retrieve cards from when a player decides to hit.  
  
The player class is a rather simple class that stores all the players statistics such as wins/losses/ties along with their name and their risk value.  The most important part of this class is their hand which relies on the hand class.  Players are stored in a vector to easily keep track of them and iterate through for them to play their turn.
  
The JackBlackSimulator class is where everything happens.  It relies heavily on the other classes.  The deck is created here, the players are also created here within a vector.  This is where the game is played, where each player gets dealt their cards, and statistics are kept track of.  
