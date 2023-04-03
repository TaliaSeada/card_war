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
    Game::Game(Player& p1, Player& p2){
        if(!p1.getName().empty() && !p1.getName().empty()){
            (this)->p1 = &p1;
            (this)->p2 = &p2;
        }
        (this)->set();
        (this)->winner = nullptr;
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
            (this)->p1->addCard((this)->stack.back()); 
            (this)->stack.pop_back(); 

            (this)->p2->addCard((this)->stack.back()); 
            (this)->stack.pop_back();
        }

    }

    // returns a pointer to the winner
    Player* Game::getWinner(){
        return (this)->winner;
    }

    // activate next turn
    int Game::playTurn(){
        if(p1->stacksize() > 0 && p2->stacksize() > 0){
            // draw card from each and play
            Card* p1_c = p1->drawCard();
            Card* p2_c = p2->drawCard();

            // Ace wins all except 2
            if(p1_c->getValue() == 1 && p2_c->getValue() != 2){
                p1->takeCard();
                p1->takeCard();
            }
            else if(p2_c->getValue() == 1 && p1_c->getValue() != 2){
                p2->takeCard();
                p2->takeCard();
            }
            // all other cases the bigger value wins
            else if(p1_c->getValue() > p2_c->getValue()){
                // cout << "P1" << endl;
                // p1 wins the turn
                p1->takeCard();
                p1->takeCard();
            }
            else if(p1_c->getValue() < p2_c->getValue()){
                // cout << "P2" << endl;
                // p2 wins the turn
                p2->takeCard();
                p2->takeCard();
            }
            else{
                // war
                int cards = 2; // #cards on the desk
                (this)->War(p1_c, p2_c, cards);
            }
            delete p1_c;
            delete p2_c;
        }
        else{
            return 0;
        }
        return 1;
    }

    // print the last turn stats.
    void Game::printLastTurn(){

    }
    
    void Game::War(Card* p1_c, Card* p2_c, int cards){
        // cout<<"WAR!"<<endl;
        while(p1_c->getValue() == p2_c->getValue()){
            if(p1->stacksize() > 1 && p2->stacksize() > 1){
                // upside down card
                delete (p1->drawCard());
                delete (p2->drawCard());
                cards += 2; // add 2 cards

                // draw card from each and play
                p1_c = p1->drawCard();
                p2_c = p2->drawCard();
                cards += 2; // add 2 cards
                
                if(p1_c->getValue() > p2_c->getValue()){
                    // p1 wins the war - need to take in all the cards that on the desk 
                    for(int i = 0; i < cards; i++){
                        p1->takeCard();
                    }
                }
                else if(p1_c->getValue() < p2_c->getValue()){
                    // p2 wins the war - need to take in all the cards that on the desk 
                    for(int i = 0; i < cards; i++){
                        p2->takeCard();
                    }
                }
                else{
                    continue; // the war is still going
                }
            }
            else{
                if(p1->stacksize() == 1 && p2->stacksize() == 1){
                    p1->takeCard();
                    p2->takeCard();
                }
                cout << "Run out of cards" << endl;
                return;
            }
        }

    }

    // playes the game untill the end
    int Game::playAll(){
        // play all turns
        int res = 1;
        while((res) != 0){
            res = (this)->playTurn();
        }

        // set winner
        if(p1->cardesTaken() < p2->cardesTaken()){
            (this)->winner = p2;
        }
        else if(p2->cardesTaken() < p1->cardesTaken()){
            (this)->winner = p1;
        }
        return 1;
    }

    // prints the name of the winning player
    void Game::printWiner(){
        if((this)->winner != nullptr){
            string res = (this)->winner->getName();
            cout << "The Winner Is: " << res << endl;
        }
        else{
            cout << "Tie!" << endl;
        }
    }

    // prints all the turns played one line per turn
    void Game::printLog(){

    }

    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    void Game::printStats(){

    }
} 