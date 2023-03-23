#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;

namespace ariel {
    Player::Player() {
        deck.resize(52, nullptr);
    }

    Player::Player(std::string name) {
        if (!name.empty()) {
            this->name = name;
        }
        deck.resize(52, nullptr);
    }


    // get the player's name
    string Player::getName(){
        return (this)->name;
    }

    // set the player's name
    void Player::setName(string newName){
        if(!newName.empty()){
            (this)->name = newName;
        }
        else{
            std::cout << "Enter valid name" << std::endl; 
        }
    }

    // add new card to the players deck and increase the size of the deck
    void Player::addCard(Card* c) {
        deck.push_back(c);
    }


    // amount of cards left.
    int Player::stacksize(){
        return (this)->stackSize;
    }

    // amount of cards this player has won.
    int Player::cardesTaken(){
        return (this)->cardsTaken;
    }

    // check if the player's deck empty
    bool Player::isEmpty(){
        return (this)->stackSize == 0;
    }
        
    // pull card from the player's deck
    Card* Player::drawCard() {
        Card* res = deck.back();
        deck.pop_back();
        return res;
    }
}

