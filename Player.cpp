#include "Player.hpp"
#include "Game.hpp"
const int num = 7;

namespace coup{
     
        Player::Player(Game &game,string name){
                this->name = move(name);
                this->game = &game;
                this->amount = 0;
                this->inside = true;
                this->blocked = false;
                this->last_action = "";
               if(this->inside){
                game.addp(this);
                }
        }
        //take 1 coin 
        void  Player::income(){
                if(this->name==game->turn()){
                this->amount++;
                game->nextturn();
                this->last_action = "income";

                }
                else{
                        throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
                }

        }
        //remove other player costs 7 coins
        void Player::coup(Player &p) const{
                if(this->name==game->turn()){
                if(p.amount>=num){
                p.inside = false;
                p.amount-=num;
                p.last_action = "coup";
                p.assassinated = p.name;
                game->nextturn();
               
                }else{
                         throw invalid_argument("the player dosent have enough money" );
                }
                }else{
                         throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
                }
        }
        //shows curr role of the player
        int Player::coins(){
                return this->amount;

        }
        
         //douvle coin take
        void  Player::foreign_aid(){
                 if(this->name==game->turn()){
                game->nextturn();
                this->amount+=2;
                this->last_action = "foreign_aid";
                 } else{
                          throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
                 }

        }
        void Player::lastaction(){
                

        }


        
}