#pragma once
#include "card.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {
    class Player{
        string name;
        int stackSize;
        int cardsTaken;
        std::vector<Card*> deck;
        string stats;

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

            // increase amount of cards this player has won.
            void takeCard();

            // check if the player's deck empty
            bool isEmpty();

            // pull card from the player's deck
            Card* drawCard();

            std::vector<Card*> getDeck();

    };

}
