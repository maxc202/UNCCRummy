#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"
using namespace std;

class Deck{
private:
  Card deck[52];
public:
  Deck(){
    int count = 0;
    for(int i = 0; i < 13; i++){
      for(int j = 0; j < 4; j++){
        Card temp = new Card(i, j);
        deck[count] = temp;
        delete temp;
        count++;
      }
    }
  }
  
  void output(){
    for(int i = 0; i < 52; i++){
      deck[i].output();
      cout << endl; 
    }
  }
};
