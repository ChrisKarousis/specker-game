#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "players.h"

using namespace std;

class Game {
 public:
 Game(int heaps, int players);
 ~Game();

 void addHeap(int coins) throw(logic_error);
 void addPlayer(Player *player) throw(logic_error);
 void play(ostream &out) throw(logic_error);
 int getPlayers() const;
 const Player *getPlayer(int p) const throw(logic_error);
};