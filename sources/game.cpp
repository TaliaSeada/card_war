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
        (this)->drawRate = 0;
        (this)->set();
        (this)->winner = nullptr;
    }
    
    // set new game
    void Game::set(){
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                (this)->stack.push_back(Card(values[j], suits[i]));
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
    void Game::playTurn(){
        if(p1==p2){
            throw std::runtime_error("One Player");
        }
        string turnWinner = "";
        if(p1->stacksize() > 0 && p2->stacksize() > 0){
            // draw card from each and play
            Card p1_c = p1->drawCard();
            Card p2_c = p2->drawCard();

            // Ace wins all except 2
            if((p1_c.getValue() == 1 && p2_c.getValue() != 2) || (p1_c.getValue() > p2_c.getValue())){
                turnWinner = p1->getName();
                p1->winrate()++;
                p1->takeCard();
                p1->takeCard();
            }
            else if((p2_c.getValue() == 1 && p1_c.getValue() != 2) || (p1_c.getValue() < p2_c.getValue())){
                turnWinner = p2->getName();
                p2->winrate()++;
                p2->takeCard();
                p2->takeCard();
            }
            else{
                // war
                (this)->drawRate++;
                int cards = 2; // #cards on the desk
                turnWinner = (this)->War(p1_c, p2_c, cards);
            }
            // add winner to log
            (this)->log.push_back(p1->getName() + " played " + p1_c.stringValue() + " of " + p1_c.stringSuit()
            + " " + p2->getName() + " played " + p2_c.stringValue() + " of " + p2_c.stringSuit()
            + ". " + turnWinner + " wins.");

        }
        else{
            throw std::runtime_error("No More Turns");
        }
    }

    // print the last turn stats.
    void Game::printLastTurn(){
        cout << log.back() << endl;
    }
    
    string Game::War(Card p1_c, Card p2_c, int cards){
        string turnWinner = "";
        while(p1_c.getValue() == p2_c.getValue()){
            if(p1->stacksize() > 1 && p2->stacksize() > 1){
                // upside down card
                p1->drawCard();
                p2->drawCard();
                cards += 2; // add 2 cards

                // draw card from each and play
                p1_c = p1->drawCard();
                p2_c = p2->drawCard();
                cards += 2; // add 2 cards
                
                if(p1_c.getValue() > p2_c.getValue()){
                    // p1 wins the war - need to take in all the cards that on the desk 
                    for(int i = 0; i < cards; i++){
                        p1->takeCard();
                    }
                    turnWinner = p1->getName();
                    p1->winrate()++;
                }
                else if(p1_c.getValue() < p2_c.getValue()){
                    // p2 wins the war - need to take in all the cards that on the desk 
                    for(int i = 0; i < cards; i++){
                        p2->takeCard();
                    }
                    turnWinner = p2->getName();
                    p2->winrate()++;
                }
                else{
                    (this)->drawRate++;
                    continue; // the war is still going
                }
            }
            else{ // each player takes his/hers cards
                for(int i = 0; i < cards/2; i++){
                    p1->takeCard();
                    p2->takeCard();
                }
                cout << "Run out of cards" << endl;
                return turnWinner;
            }
        }
        return turnWinner;
    }

    // playes the game untill the end
    int Game::playAll(){
        // play all turns
        while(p1->stacksize() > 0 && p2->stacksize() > 0){
            (this)->playTurn();
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
            // cout << "The Winner Is: " << res << endl;
            cout << res << endl;
        }
        else{
            cout << "Tie!" << endl;
        }
    }

    // prints all the turns played one line per turn
    void Game::printLog(){
        for (std::vector<std::string>::size_type i = 0; i < log.size(); i++) {
            std::cout << log.at(i) << endl;
        }
    }

    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    void Game::printStats(){
        cout << "\n" << p1->getName() << ":\n" 
        << "win rate: " << ((double)p1->winrate()/(p1->winrate()+p2->winrate())*100) << "%\n" 
        << "cards won: " << p1->cardesTaken()
        << endl;  

        cout << "\n" << p2->getName() << ":\n" 
        << "win rate: " << ((double)p2->winrate()/(p1->winrate()+p2->winrate())*100) << "%\n" 
        << "cards won: " << p2->cardesTaken()
        << endl;  

        cout << "\ndraw rate: " << ((double) (this)->drawRate/(p1->winrate()+p2->winrate()))*100 << "%\n" 
        << "amount of draws: " << (this)->drawRate
        << endl; 
        
    }
} 