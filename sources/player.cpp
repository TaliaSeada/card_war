#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;

namespace ariel {
    // default constructor
    Player::Player(){};
    // name constructor 
    Player::Player(string name){
        if(!name.empty()){
            (this)->name = name;
        }
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

    // add new card to the players stack and increase the size of the stack
    void Player::addCard(Card* c){
        (this)->stack[(this)->stackSize] = c;
        (this)->stackSize++;
    }

    // amount of cards left.
    int Player::stacksize(){
        return (this)->stackSize;
    }

    // amount of cards this player has won.
    int Player::cardesTaken(){
        return (this)->cardsTaken;
    }

    // check if the player's stack empty
    bool Player::isEmpty(){
        return (this)->stackSize == 0;
    }
        
    // pull card from the player's stack
    Card* Player::drawCard(){
        Card* res = (this)->stack[(this)->stackSize];
        (this)->stack[(this)->stackSize] = nullptr;
        return res;
    }
} 

