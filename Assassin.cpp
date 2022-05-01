#include "Assassin.hpp"
namespace coup{
     Assassin::Assassin(Game &game, string name) :Player(game,move(name) )
    {
    }

   void Assassin::coup(Player &player)
   {   
        if(this->name==game->turn()){
       if(player.amount>=3){
           game->nextturn();
           player.amount-=3;
           player.inside = false; 
           this-> last_action = "coup";
           this->assassinated = player.name;
           
       }
        }else{
                                    throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );

        }

    }

    /*void role(){
        cout << "Assassin" << endl;

    }*/
}