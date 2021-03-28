#include <iostream>
#include <string>
#include <cstdlib>
#include "MovesAndStates.h"

using namespace std;

Move::Move(int sh, int sc, int th, int tc) : source(sh), sourceCoins(sc), targetCoins(tc), target(th){
    cout << "A move made" << endl;
}

int Move::getSource() const{
    return source;
}

int Move::getSourceCoins() const{
    return sourceCoins;
}

int Move::getTarget() const{
    return target;
}

int Move::getTargetCoins() const{
    return targetCoins; 
}

ostream& operator << (ostream &out, const Move &move){ // will the moves be well defined ?
    cout << move.source << " takes " << move.sourceCoins << " coins from heap " << move.target << " and puts ";
    if(move.targetCoins == 0){
        cout << "nothing" << endl; // endl ???
    }else {
        cout << move.targetCoins << endl; // endl ???
    }
}

State::State(int h, const int c[], int n) : heapsCount(h), playersCount(n){
    cout << "A state is constructed!" << endl;
    coins = new int[heapsCount];
    for(int i=0 ; i<heapsCount ; i++){
        coins[i] = c[i];
    }
}

 State::~State(){
    cout << "A state is deleted!" << endl;
    delete coins;
 }

 void State::next(const Move &move){

 }

 bool State::winning() const{

 }

 int State::getHeaps() const{

 }

 int State::getCoins(int h) const{

 }

 int State::getPlayers() const{

 }
 int State::getPlaying() const{

 }

 ostream & operator << (ostream &out, const State &state){
     
 }