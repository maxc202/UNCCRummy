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
    
  }
  
  void draw(vector<Card*>& deck){
    hand.push_back(deck[0]);
    deck.pop_back();
  }
  
  void discard(int num, Cardvector<Card*>& discard){
    discard.pop_back(hand[num]);
    hand.erase(num);
  }
      
  void findMelds(){
    //Find sets
    for(int i = 0; i < hand.size(); i++){
      int count = 1;
      for(int j = i; j < hand.size(); j++){
  }
};
