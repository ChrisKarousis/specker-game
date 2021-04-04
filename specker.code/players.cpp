#include <iostream>
#include <string>
#include <cstdlib>
#include "players.h"

using namespace std;

Player::Player(const string &n){
    name = n;
}

Player::~Player(){
    cout << "Player destroyed!" << endl;
}

ostream & operator << (ostream &out, const Player &player){
    string s = player.getType();
    out << s;
    out << " player " << player.name;
    return out;
}

GreedyPlayer::GreedyPlayer(const string &n) : Player(n){
}

GreedyPlayer::~GreedyPlayer(){
}

const string & GreedyPlayer::getType() const{
    return "Greedy";
}

Move GreedyPlayer::play(const State &s){
    int max = -1, max_position;
    for(int i=0 ; i < s.getHeaps() ; i++){
        if(max < s.getCoins(i)){
            max = s.getCoins(i);
            max_position = i;
        }
    }
    return Move(max_position, max); // ginetai ??
}

SpartanPlayer::SpartanPlayer(const string &n) : Player(n){
}

SpartanPlayer::~SpartanPlayer(){
}

const string & SpartanPlayer::getType() const{
    return "Spartan";
}

Move SpartanPlayer::play(const State &s){
    int max = -1, max_position;
    for(int i=0 ; i < s.getHeaps() ; i++){
        if(max < s.getCoins(i)){
            max = s.getCoins(i);
            max_position = i;
        }
    }
    return Move(max_position, 1); // ginetai ??
}

SneakyPlayer::SneakyPlayer(const string &n) : Player(n){
}

SneakyPlayer::~SneakyPlayer(){
}

const string & SneakyPlayer::getType() const{
    return "Sneaky";
}

Move SneakyPlayer::play(const State &s){
    int min = s.getCoins(0), min_position=0;
    for(int i=0 ; i < s.getHeaps() ; i++){
        if((min > s.getCoins(i) || min == 0) && (s.getCoins(i) != 0)){
            min = s.getCoins(i);
            min_position = i;
        }
    }
    return Move(min_position, min); // ginetai ??
}

RighteousPlayer::RighteousPlayer(const string &n) : Player(n){
}

RighteousPlayer::~RighteousPlayer(){
}

const string & RighteousPlayer::getType() const{
    return "Righteous";
}

Move RighteousPlayer::play(const State &s){
    int max = 0, max_position, min = s.getCoins(0), min_position = 0;
    for(int i=0 ; i < s.getHeaps() ; i++){
        if(max < s.getCoins(i)){
            max = s.getCoins(i);
            max_position = i;
        }
        if(min > s.getCoins(i)){
            min = s.getCoins(i);
            min_position = i;
        }
    }
    cout << max_position << min_position << endl;
    return Move(max_position, max/2+ max%2, min_position, max/2+ max%2 -1); // ginetai ?? ta coins einai int gia floor
}