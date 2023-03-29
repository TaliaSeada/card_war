#pragma once
#include <string>

namespace ariel {
    class Card{
        std::string value;
        std::string suit;

        public:
            // default constructor
            Card();
            // value and sign constructor
            Card(std::string, std::string);

            // set card value and suit
            void setCard(std::string, std::string);

            // print the card value and suit
            void printCard();

            // get the card value
            int getValue();

    };
}

