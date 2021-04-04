#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main() {
 Game specker(3, 4);
 specker.addHeap(10);
 specker.addHeap(20);
 specker.addHeap(17);
 specker.addPlayer(new SneakyPlayer("Tom"));
 specker.addPlayer(new SpartanPlayer("Mary"));
 specker.addPlayer(new GreedyPlayer("Alan"));
 specker.addPlayer(new RighteousPlayer("Robin"));
 specker.play(cout);
}

