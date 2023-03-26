#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
using namespace std;


TEST_CASE("empty decks") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    // both stackes should be empty
    CHECK(p1.stacksize() == 0); 
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(game.playTurn() == 0); // should return 0 since their stacks are empty 
    game.printWiner(); // There should be no winner
    // CHECK(game.getWinner()->getName() == ""); // There should be no winner
}

TEST_CASE("one player has all cards") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    CHECK(p1.stacksize() == 52); //check that Alice got all the cards
    CHECK(p2.stacksize() == 0); //check that Bob didnt get any card
    CHECK(game.playTurn() == 0); // should return 0 since Bob's stack is empty  
    CHECK(p2.cardesTaken() == 0);
    game.printWiner(); // Alice should be the winner
    // CHECK(game.getWinner()->getName() == p1.getName()); // Alice should be the winner
}

TEST_CASE("Both players have the same number of cards") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    // should have the same amount of cards
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(game.playTurn() == 1); // check if they can play
    // CHECK(game.getWinner()->getName() == ""); // no one is the winner yet
    game.printWiner();
    CHECK(game.playAll() == 1);
    // CHECK(game.getWinner()->getName() != ""); // there is a winner 
    game.printWiner();
}

TEST_CASE("One player has no cards") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    CHECK(p1.stacksize() == 52); //check that Alice got all the cards
    CHECK(p2.stacksize() == 0); //check that Bob didnt get any card
    CHECK(game.playTurn() == 1); // check if they can play
    game.playAll(); // should end immediately since Bob's stack is empty 
    CHECK(p2.cardesTaken() == 0);
    // CHECK(game.getWinner()->getName() == p1.getName()); // Alice should be the winner
    game.printWiner(); // Alice should be the winner
}

TEST_CASE("War") {
    Player p1("Alice");
    Player p2("Bob");

    // Card cP1_1(12, 2); // value of 12
    // p1.addCard(&cP1_1);
    // Card cP1_2(1, 4); // value of 1 - upside down
    // p1.addCard(&cP1_2); 
    // Card cP1_3(13, 1); // value of 13
    // p1.addCard(&cP1_3);

    // Card cP2_1(12, 3); // value of 12
    // p2.addCard(&cP2_1);
    // Card cP2_2(6, 1); // value of 6 - upside down
    // p2.addCard(&cP2_2);
    // Card cP2_3(8, 3); // value of 8
    // p2.addCard(&cP2_3); 

    Game game(p1, p2);
    // should have the same amount of cards
    CHECK(p1.stacksize() == 3);
    CHECK(p2.stacksize() == 3);
    CHECK(game.playTurn() == 1); // should go to war 
    CHECK(game.playAll() == 1); // make the war
    game.printWiner(); // Alice should be the winner - 13 is bigger than 8
    CHECK(p1.cardesTaken() > 0); // alice should win the war

    // CHECK(game.getWinner()->getName() == p1.getName()); // Alice should be the winner - 13 is bigger than 8
}

TEST_CASE("Players have only one card each") {
    Player p1("Alice");
    Player p2("Bob");
    
    // Card cP1(13, 1); // value of 13
    // p1.addCard(&cP1);
    // Card cP2(4, 2); // value of 4
    // p2.addCard(&cP2);

    Game game(p1, p2);
    // should have the same amount of cards
    CHECK(p1.stacksize() == 1);
    CHECK(p2.stacksize() == 1);
    CHECK(game.playTurn() == 1);
    // CHECK(game.getWinner()->getName() != ""); // there is a winner
    game.printWiner();
    // CHECK(game.getWinner()->getName() == p1.getName()); // Alice should be the winner - 13 is bigger than 4
    CHECK(p1.cardesTaken() > 0); // alice should win the war
}



