#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;

namespace ariel {
    Player::Player() {
        (this)->stackSize = 0;
        (this)->cardsTaken = 0;
    }

    Player::Player(std::string name) {
        if (!name.empty()) {
            this->name = name;
        }
        (this)->stackSize = 0;
        (this)->cardsTaken = 0;
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
        (this)->stackSize++;
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

    void Player::takeCard(){
        (this)->cardsTaken++;
    }

    // check if the player's deck empty
    bool Player::isEmpty(){
        return (this)->stackSize == 0;
    }
        
    // pull card from the player's deck
    Card* Player::drawCard() {
        Card* res = ((this)->deck.back());
        (this)->deck.pop_back();
        (this)->stackSize--;
        return res;
    }

    std::vector<Card*> Player::getDeck(){
        return (this)->deck;
    }
}

