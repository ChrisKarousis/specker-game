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

 private :
    string name;
 };

 class GreedyPlayer : public Player {
 public :
 GreedyPlayer(const string &n);
 ~GreedyPlayer();
 const string & getType() const;
 Move play(const State &s);
};

class SpartanPlayer : public Player {
 public :
 SpartanPlayer(const string &n);
 ~SpartanPlayer();
 const string & getType() const;
 Move play(const State &s);
};

class SneakyPlayer : public Player {
 public :
 SneakyPlayer(const string &n);
 ~SneakyPlayer();
 const string & getType() const;
 Move play(const State &s);
};

class RighteousPlayer : public Player {
 public :
 RighteousPlayer(const string &n);
 ~RighteousPlayer();
 const string & getType() const;
 Move play(const State &s);
};
