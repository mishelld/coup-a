#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;

Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();
TEST_CASE("good tests")
{
    duke.income();
    CHECK_EQ(duke.coins(),1);

    assassin.foreign_aid();
    CHECK_EQ(assassin.coins(),2);

    ambassador.transfer(duke,assassin);
    CHECK_EQ(assassin.coins(),3);
    
    CHECK_THROWS(contessa.income());

    captain.steal(assassin);
     CHECK_EQ(captain.coins(),2);
     CHECK_EQ(assassin.coins(),1);

   CHECK_THROWS(contessa.block(assassin));
   contessa.income();
   int i =0;
   while(i !=10){
     duke.income();
	assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();
    CHECK_EQ(contessa.coins(),i+2);
    i++;
 }
/* duke.tax();
assassin.coup(duke);
players = game_1.players();
ambassador.income();
captain.income();
contessa.income();*/
duke.income();
assassin.income();
ambassador.income();
captain.income();
contessa.income();  


while(i!=100){
    duke.income();
assassin.income();
ambassador.income();
captain.income();
  contessa.income();  
   CHECK_EQ(contessa.coins(),i+3);
   i++;
}

CHECK_NOTHROW(duke.tax());

CHECK_EQ(duke.coins(),104);

CHECK_EQ(assassin.coins(),102);

CHECK_EQ(ambassador.coins(),101);

CHECK_EQ(captain.coins(),103);

CHECK_EQ(contessa.coins(),102);



assassin.foreign_aid();

ambassador.foreign_aid();

captain.foreign_aid();

CHECK_THROWS(contessa.block(assassin));







    

   

    


}