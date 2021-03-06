#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Move {
public: // Take sc coins from heap sh and put tc coins to heap th.
 Move(int sh, int sc, int th=0, int tc=0);

 int getSource() const;
 int getSourceCoins() const;
 int getTarget() const;
 int getTargetCoins() const;

 friend ostream & operator << (ostream &out, const Move &move);

 private :
 int source, sourceCoins, target, targetCoins;
 };


class State {
 public:
 // State with h heaps, where the i-th heap starts with c[i] coins.
 // A total of n players are in the game, numbered from 0 to n-1,
 // and player 0 is the first to play.
 State(int h, const int c[], int n);
 ~State();

 void next(const Move &move) throw(logic_error);
 bool winning() const;

 int getHeaps() const;
 int getCoins(int h) const throw(logic_error);

 int getPlayers() const;
 int getPlaying() const;

 friend ostream & operator << (ostream &out, const State &state);

 private :
    int maxHeaps, maxPlayers, playing; 
    int *coins; // array of coins in every heap 
};
