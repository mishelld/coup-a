#include "Ambassador.hpp"
namespace coup{

   Ambassador::Ambassador(Game &game, string name) :Player(game, move(name)){
     
       
   }

   void Ambassador::transfer(Player &player1,Player &player2){
       if(this->name==game->turn()){
       if(player1.amount>=1){
            game->nextturn();
           player1.amount--;
           player2.amount++;
       }
       }else{
           throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );

       }
   }
      /* void role(){
           cout << "Ambassador" << endl;
       }*/

   


}