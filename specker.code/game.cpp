#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"

using namespace std;

Game::Game(int heaps, int players) : maxHeaps(heaps), maxPlayers(players), heapsCount(0), playersCount(0){
    pl = new Player*[players];
    c = new int[heaps]; 
}

Game::~Game(){
}


void Game::addHeap(int coins) throw(logic_error){
    if(heapsCount >= maxHeaps){
        throw logic_error("enough heaps!");
    }
    c[heapsCount] = coins; 
    heapsCount++;
    if(heapsCount >= maxHeaps && playersCount >= maxPlayers){
        state = new State(maxHeaps, c, maxPlayers);
    }
    
}

void Game::addPlayer(Player *player) throw(logic_error){
    if(playersCount >= maxPlayers){
        throw logic_error("enough players!");
    }
    pl[playersCount] = player;
    playersCount++;
    if(heapsCount >= maxHeaps && playersCount >= maxPlayers){
        state = new State(maxHeaps, c, maxPlayers);
    }
}

void Game::play(ostream &out) throw(logic_error){
    if(maxPlayers <= 0 || maxHeaps <=0) throw logic_error("Cannot do that!");
    while(!state->winning()){
        for(int i=0 ; i<maxPlayers ; i++){
            cout << *state;
            state->next(pl[i]->play(*state));
            if(state->winning()){
                cout << *pl[i];
                cout << " wins" << endl;
                return ;
            }
        }
    }
    
}

int Game::getPlayers() const{
    return maxPlayers;
}

const Player *Game::getPlayer(int p) const throw(logic_error){
    if(p < 0 || p >= maxPlayers) throw logic_error("Cannot do that");
    return pl[p];
}
