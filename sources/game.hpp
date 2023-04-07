#pragma once
#include "player.hpp"

namespace ariel {
    class Game{
        Player* p1;
        Player* p2;
        Player* winner;
        int drawRate;
        std::vector<string> log;
        std::vector<Card*> stack;

        public:
            // default constructor 
            Game();
            // players constructor 
            Game(Player&, Player&);

            // set new game
            void set();
            
            // returns a pointer to the winner
            Player* getWinner();

            // activate next turn
            void playTurn();

            // print the last turn stats.
            void printLastTurn();

            // playes the game untill the end
            int playAll();

            // prints the name of the winning player
            void printWiner();

            // prints all the turns played one line per turn
            void printLog();

            // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
            // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws)
            void printStats();

            string War(Card*, Card*, int);
    };
}