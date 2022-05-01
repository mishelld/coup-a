#include "Contessa.hpp"
#include "Game.hpp"
#include "Player.hpp"
namespace coup{
    Contessa::Contessa(Game &game,string name):Player(game, move(name)){

    }
     void Contessa::block(Player &player){
         if(player.last_action=="coup"){
             player.blocked=true;
             for(Player *p: player.game->p_g_2){
                 if(p->name==player.assassinated){
                     p->inside = true;
                 }
             }
         }
         else{
             throw invalid_argument("the last action is not coup its" +player.last_action);
         }
     }
      void role(){
            cout << "Contessa" << endl;

      }
     
}