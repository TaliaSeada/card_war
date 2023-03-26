#include <string>
#include "game.hpp"
#include <iostream>
using namespace std;

namespace ariel {
    // default constructor 
    Game::Game(){};
    // players constructor 
    Game::Game(Player p1, Player p2){
        if(!p1.getName().empty() && !p1.getName().empty()){
            (this)->p1 = p1;
            (this)->p2 = p2;
        }
        (this)->winner.setName("");
    }
    
    // returns a pointer to the winner
    Player* Game::getWinner(){
        return &(this)->winner;
    }

    // activate next turn
    int Game::playTurn(){
        return 1;
    }

    // print the last turn stats.
    void Game::printLastTurn(){

    }

    // playes the game untill the end
    int Game::playAll(){
        return 1;
    }

    // prints the name of the winning player
    void Game::printWiner(){
        string res = (this)->winner.getName();
        cout << &res << endl;
    }

    // prints all the turns played one line per turn
    void Game::printLog(){

    }

    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    void Game::printStats(){

    }
} 