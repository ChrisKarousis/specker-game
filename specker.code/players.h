#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "MovesAndStates.h"

using namespace std;

class Player {
 public:
 Player(const string &n);
 virtual ~Player();
 virtual const string & getType() const = 0;
 virtual Move play(const State &s) = 0;

 friend ostream & operator << (ostream &out, const Player &player);
 };

 class Greedy : public Player {

};

class Spartan : public Player {

};

class Sneaky : public Player {

};

class Righteous : public Player {
    
};
