#include "doctest.h"
#include <string>
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"

using namespace ariel;

TEST_CASE("check players"){ //4
    // check players
    CHECK_NOTHROW(Player p1);
    CHECK_NOTHROW(Player p2);
    CHECK_NOTHROW(Player p1("Alice"));
    CHECK_NOTHROW(Player p2("Bob"));
}

TEST_CASE("check card"){ //2
    // check card
    CHECK_NOTHROW(Card());
    CHECK_NOTHROW(Card("4", "Spades"));
}

TEST_CASE("check game"){ //2
    // check game
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game game(p1,p2));
    CHECK_NOTHROW(Game game);
}

TEST_CASE("check game functions throws"){ //5
    // Create two players with their names
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p2.stacksize());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(p1.cardesTaken());
    CHECK_NOTHROW(p2.cardesTaken());
}

TEST_CASE("check game functions"){ //8
    // Create two players with their names
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    // didnt play yet so should have 0
    CHECK_FALSE(p1.cardesTaken() > 0);
    CHECK_FALSE(p2.cardesTaken() > 0);
    // should have 26 each
    CHECK_FALSE(p1.stacksize() == 0); 
    CHECK_FALSE(p2.stacksize() == 0);

    game.playAll();
    // should take card once (?)
    CHECK_FALSE(p1.cardesTaken() == 0);
    CHECK_FALSE(p2.cardesTaken() == 0);
    // one of them lost his stack
    CHECK_FALSE(p1.stacksize() > 0);
    CHECK_FALSE(p2.stacksize() > 0);
}


TEST_CASE("play game"){ //
    // Create two players with their names
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    CHECK_EQ(p1.stacksize(), 26);
    CHECK_EQ(p2.stacksize(), 26);
    game.playAll();
    CHECK(p1.cardesTaken() > 0);
    CHECK(p2.cardesTaken() > 0);
    CHECK_EQ(p1.stacksize(), 0);
    CHECK_EQ(p2.stacksize(), 0);
}

// student tests:
TEST_CASE("The amount of cards before starting a game")
{
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("The amount of cards after starting a game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("The card scheme at the end of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    int sum = p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken();
    CHECK(sum == 52);
}

TEST_CASE("Throwing errors from the functions")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Activating another turn after the game is over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("One player")
{
    Player p1("Alice");
    Game game(p1, p1);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Printing the winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    if (p1.cardesTaken() == p2.cardesTaken())
    {
        CHECK_THROWS(game.printWiner());
    }
    else
    {
        CHECK_NOTHROW(game.printWiner());
    }
}

TEST_CASE("The game ends after at most 26 turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool maxTurns = 26;
    
    for (int i = 0 ; i <= 26 ; i++ && p1.stacksize()>=0)
    {
        game.playTurn();
    }
    CHECK(maxTurns == 26);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}