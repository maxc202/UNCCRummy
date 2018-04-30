#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;

class Hand{
private:
  vector<Card*> hand;
  vector<Card*> runs;
  vector<Card*> sets;
public:
  
  bool way2sort(Card* i, Card* j) {return *i < *j);
                                   
  Hand(){
    
  }
  
  void draw(vector<Card*>& deck){
    hand.push_back(deck.back());
    deck.pop_back();
  }
   
  void sortHand(){                                 
    sort(hand.begin(), hand.end(), way2Sort);                                 
  }
                                   
  void sortRuns(){
      sort(runs.begin(), runs.end(), way2Sort);
  }
                                   
  void discard(int num, Cardvector<Card*>& discard){
    discard.pop_back(hand[num]);
    hand.erase(num);
  }
      
  void findMelds(){
    //Find sets
    for(int i = 0; i < hand.size(); i++){
      int count = 1;
      for(int j = i; j
  }
  
  int checkDeadwood(){
    int deadwood = 0
    for(int i = 0; i < hand.size()-1; i++){
      deadwood += hand[i].getScoreVal();
    }
    return deadwood;
  }
};
