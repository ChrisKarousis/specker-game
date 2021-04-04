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
        out << "nothing"; // endl ???
    }else {
        out << move.targetCoins; // endl ???
    }
    return out;
}

State::State(int h, const int c[], int n) : maxHeaps(h), maxPlayers(n), playing(0){ // playing = 0 (logika)
    cout << "A state is constructed!" << endl;
    coins = new int[maxHeaps];
    for(int i=0 ; i<maxHeaps ; i++){
        coins[i] = c[i];
    }
}

 State::~State(){
    cout << "A state is deleted!" << endl;
    delete coins;
 }

 void State::next(const Move &move) throw(logic_error){
    int sourceHeap = move.getSource(); 
    if(sourceHeap < 0 || sourceHeap >= maxHeaps) throw logic_error("invalid heap"); 
    int targetHeap = move.getTarget();
    if(targetHeap < 0 || targetHeap >= maxHeaps) throw logic_error("invalid heap"); 
    int sourceCoins = move.getSourceCoins();
    if(sourceCoins - coins[sourceHeap] > 0 || sourceCoins <= 0) throw logic_error("invalid amount of coins");  // ?? is this the correct implementation or when if is true we need to                                                      
    int targetCoins = move.getTargetCoins();                                               // get all the coins ??

    coins[sourceHeap] -= sourceCoins;
    coins[targetHeap] += targetCoins;
    playing ++;
    if(playing >= maxPlayers){
            playing = 0;
    }
 }

 bool State::winning() const{
     for(int i=0 ; i<maxHeaps ; i++){
         if(coins[i] > 0){
             return false;
         }
     }
     return true;
 }

 int State::getHeaps() const{
     return maxHeaps;
 }

 int State::getCoins(int h) const throw(logic_error){
    if(h < 0 || h >= maxHeaps) throw logic_error("invalid heap");
        return coins[h];
 }

 int State::getPlayers() const{
     return maxPlayers;
 }
 int State::getPlaying() const{
    return playing;
 }

 ostream & operator << (ostream &out, const State &state){
     int coins;
     int maxHeaps = state.getHeaps();
    for(int i=0 ; i<maxHeaps-1 ; i++){
        coins = state.getCoins(i);
        out << coins << " ,";
    }
    if(maxHeaps >= 1){
        coins = state.getCoins(maxHeaps-1);
        out << coins << " ";
    }
    out << "with " << state.getPlaying() << "/" << state.getPlayers() << " playing next" << endl;
    return out;
 }