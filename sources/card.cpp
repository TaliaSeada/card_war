#include <string>
#include <iostream>
#include "card.hpp"

namespace ariel {
    // default constructor
    Card::Card(){};
    // value ans sign constructor
    Card::Card(std::string value, std::string suit){
        if(!value.empty()){ 
            (this)->value = value;
        }
        if(!suit.empty()){
            (this)->suit = suit;
        }
    } 

    void Card::setCard(std::string value, std::string suit){
        (this)->value = value;
        (this)->suit = suit;
    }

    // print the card value and suit
    void Card::printCard(){
        std::cout << "[" << (this)->value << ", " << (this)->suit << "]" << std::endl;
    }

    // get the card value
    int Card::getValue(){
        std::string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        for(int i = 0; i < 13; i++){
            if((this)->value.compare(values[i])){
                return i+1;
            }
        }
        return -1;
    }
}
