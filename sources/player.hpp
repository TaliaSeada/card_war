#pragma once
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel {
    class Player{
        string name;
        int numOfCards;
        int stackSize = 0;
        int cardsTaken = 0;
        Card* stack[52];

        public:
            // default constructor
            Player();
            // name constructor 
            Player(string);

            // get the player's name
            string getName();

            // set the player's name
            void setName(string);

            // add new card to the players stack and increase the size of the stack
            void addCard(Card*);

            // amount of cards left.
            int stacksize();

            // amount of cards this player has won.
            int cardesTaken();

            // check if the player's stack empty
            bool isEmpty();

            // pull card from the player's stack
            Card* drawCard();

    };

}
