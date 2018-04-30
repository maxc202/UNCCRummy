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
  bool dumbsort(Card* i, Card* j) {return *i > *j);
                                   
  void draw(Card* a){
    hand.push_back(a);
  }
   
  void sortHand(){                                 
    sort(hand.begin(), hand.end(), way2Sort);                                 
  }
                                   
  void sortRuns(){
      sort(runs.begin(), runs.end(), way2Sort);
  }
                                   
  void sortSets(){
   sort(sets.begin(), sets.end(), dumbsort); 
  }
                                   
  Card* discard(int num){
    Card* temp = hand[num];
    hand.erase(num);
    return temp;
  }
                                
  void findMelds(){
    //Find sets
    for(int i = 0; i < hand.size(); i++){
      int count = 1;
      for(int j = i; j
  }
  
   void retMelds(){
     for(int i = 0; i < runs.size(); i++){
       hands.push_back(runs[i]);
     }
     for(int i = 0; i < sets.size(); i++){
       hands.push_back(sets[i]);
     }
     runs.clear();
     sets.clear();2 
   }
  
  int checkDeadwood(){
    int deadwood = 0
    for(int i = 0; i < hand.size()-1; i++){
      deadwood += hand[i].getScoreVal();
    }
    return deadwood;
  }
};
