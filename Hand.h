#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Hand{
private:
  vector<Card*> hand;
  vector<Card*> runs;
  vector<Card*> sets;
public:
  Hand(){
    for(int i = 0; i < 10; i++){
      this.draw(vector<Card*> deck);
  }
  
  void draw(vector<Card*> deck){
    hand.push_back(deck[0]);
  }


};
