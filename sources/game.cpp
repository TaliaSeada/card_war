#include <string>
#include "game.hpp"
#include "card.hpp"
#include <algorithm> 
#include <cstdlib>   
#include <ctime>     
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
        (this)->set();
        (this)->winner.setName("No Winner Yet");
    }
    
    // set new game
    void Game::set(){
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                (this)->stack.push_back(new Card(values[j], suits[i]));
            }
        }

        // shuffle the deck
        srand(time(0)); // seed the random number generator with current time
        random_shuffle((this)->stack.begin(), (this)->stack.end());

        // deal the cards to the players
        for (int i = 0; i < 26; i++) {
            (this)->p1.addCard((this)->stack.back()); 
            (this)->stack.pop_back(); 

            (this)->p2.addCard((this)->stack.back()); 
            (this)->stack.pop_back();
        }
    }

    // returns a pointer to the winner
    Player* Game::getWinner(){
        return &(this)->winner;
    }

    // activate next turn
    int Game::playTurn(){
        if(p1.stacksize() > 0 && p2.stacksize() > 0){
            // draw card from each and play
            Card* p1_c = p1.drawCard();
            Card* p2_c = p2.drawCard();

            cout << p1_c->getValue() << endl;
            cout << p2_c->getValue() << endl;
            
            if(p1_c->getValue() > p2_c->getValue()){
                // cout << "P1" << endl;
                // p1 wins the turn
                p1.addCard(p1_c);
                p1.addCard(p2_c);
            }
            else if(p1_c->getValue() < p2_c->getValue()){
                // cout << "P2" << endl;
                // p2 wins the turn
                p2.addCard(p1_c);
                p2.addCard(p2_c);
            }
            else{
                // war
                (this)->War();
            }
        }
        else if(p1.stacksize() == 0){
            cout << p1.getName() << " lost" << endl;
            return 0;
        }
        else if(p2.stacksize() == 0){
            cout << p2.getName() << " lost" << endl;
            return 0;
        }

        return 1;
    }

    // print the last turn stats.
    void Game::printLastTurn(){

    }
    
    void Game::War(){
        cout<<"WAR"<<endl;


    }

    // playes the game untill the end
    int Game::playAll(){
        // play all turns
        int res = 1;
        while((res) != 0){
            res = (this)->playTurn();
        }

        // set winner
        if(p1.stacksize() == 0){
            (this)->winner = p2;
        }
        else if(p2.stacksize() == 0){
            (this)->winner = p1;
        }
        else{
            cout << "Tie!" << endl;
        }

        // delete all allocated memory
        for (int i = 0; i < (this)->winner.getDeck().size(); i++) {
            Card* card = (this)->getWinner()->drawCard();
            delete card;
        }
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