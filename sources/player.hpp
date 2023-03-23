#pragma once
#include "card.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {
    class Player{
        string name;
        int numOfCards;
        int stackSize = 0;
        int cardsTaken = 0;
        std::vector<Card*> deck;

        public:
            // default constructor
            Player();
            // name constructor 
            Player(string);

            // get the player's name
            string getName();

            // set the player's name
            void setName(string);

            // add new card to the players deck and increase the size of the deck
            void addCard(Card*);

            // amount of cards left.
            int stacksize();

            // amount of cards this player has won.
            int cardesTaken();

            // check if the player's deck empty
            bool isEmpty();

            // pull card from the player's deck
            Card* drawCard();

    };

}
