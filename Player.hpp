#include "Game.hpp"
#include <string>
#pragma once
using namespace std;
namespace coup{
    class Game;
    class Player
    {   
        public:
        int amount;
        string name;
        Game *game;
        bool inside;
        bool blocked;
        string last_action;
        string assassinated;
        Player(Game &game,string name);
        //take 1 coin 
        void income();
        //remove other player costs 7 coins
        void coup(Player &p) const;
        //shows curr role of the player
        void role();
        
        //shows amount of coins 
        int coins();

        int shekels();
         //douvle coin take
        void foreign_aid();

        void lastaction();

    };
}