#include "Duke.hpp"
namespace coup
{

        Duke::Duke(Game &game,string name): Player(game, move(name)){
          
        }
        //tax-can take 3 coins without anyone stopping him
        void Duke::tax(){
                game->nextturn();
                this->amount+=3;
        }
        //block- can clock double pay - the player that is blocked needs to retrun 2 coins
        void Duke::block(Player &player){
                if(player.last_action=="foreign_aid"){
                        player.blocked = true;
                        if( player.amount>=2){
                        player.amount-=2;
                        }else{
                        throw invalid_argument("the player dosent have enough money");
                        }
                }
                else{
                throw invalid_argument("the players last action is not foreign_aid");


                }

        }



}