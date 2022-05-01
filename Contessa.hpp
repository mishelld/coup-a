#include "Player.hpp"

namespace coup{
      class Contessa :public Player
    {
       public:  
       Contessa(Game &game,string name);
       static void block(Player &Player1);
       void role();

    };
}