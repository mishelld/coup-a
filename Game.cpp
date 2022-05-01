#include "Game.hpp"
#include "Player.hpp"
namespace coup{

    //the players that playing in the current game
    vector<string> Game::players(){
        vector <string> p;
        for(Player *pl: p_g){
           if(pl->inside==true) {
               p.push_back(pl->name);
           }
           p_g_2.push_back(pl);

        }
        return p;
    }
     


        void Game::addp(Player *p){
            p_g.push_back(p);
        }

    /// | | |
    string Game::turn(){
     unsigned int s = p_g.size();
       return p_g[t%s]->name;

    }
    //the winner of the game , if game still on throw exception
    void Game::winner(){



    }

    string Game::nextturn(){
        t++;
      unsigned int s = p_g.size();
       return p_g[(t%s)]->name;

    }

}