#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;
bool way2sort(Card* i, Card* j) {return *i < *j;}
bool dumbsort(Card* i, Card* j) {return *i > *j;}


class Hand{
private:
  vector<Card*> hand;
  vector<Card*> runs;
  vector<Card*> sets;
public:
                                   
  void draw(Card* a){
    hand.push_back(a);
  }
   
void sortHand()
{
    sort(hand.begin(), hand.end() , way2sort);
}
            
void sortRuns(){
    
    sort(runs.begin(), runs.end(), way2sort);
}
            
void sortSets(){
    sort(sets.begin(), sets.end(), dumbsort);
}
                                   
Card* discard(int num){
    Card* temp = hand[num];
    hand.erase(hands.begin()+num);
    return temp;
}
                                
void retMelds(){
     for(int i = 0; i < runs.size(); i++){
       hand.push_back(runs[i]);
     }
     for(int i = 0; i < sets.size(); i++){
       handspush_back(sets[i]);
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
          
void findSets()
{
    sort(hand.begin,hand.end, dumbsort);
    for(int k = 1; k != (hand.size() - 1); k++)
    {
        if(
           (abs((( hand[k].getOrder()-( hand[k-1]getOrder() )))==1) && abs(((hand[k].getOrder())-(hand[k+1]getOrder()))) == 1)
           )
        {
            if((k+2)<=hand.sizeof() && hand[k].getOrder()==hand[k+2].getOrder())
            {
                sets.push_back(hand[k+2]);
                hand.erase(hands.begin()+k+2);
                
            }
            sets.push_back(hand[k-1]);
            sets.push_back(hand[k]);
            sets.push_back(hand[k+1]);
            hand.erase(hands.begin()+k);
            hand.erase(hands.begin()+k-1);
            hand.erase(hands.begin()+k+1);
            
            k=0;
        }
        }
}
    
                        
void findRuns()
{
    sortHand();
    for(int k = 0; k != (hand.sizeof - 1); k++)
    {
        int curr = k;
        int count = 1;
        while((hand[curr+1].getOrder() == hand[curr].getOrder+1) && (hand[curr].getSuit == hand[curr+1].getSuit)
        {
            count++;
        }
        if(count >= 3){
            for(int u = k + count-1; u >= k; u--)
            {
                runs.push_back(hand[u]);
                hand.erase(hands.begin()+u);
            }
            k=0;
    }
        /*
        if(hand[k].getSuit==hand[k-1].getSuit && hand[k].getSuit==hand[k+1].getSuit)
        {
            runs.push_back(hand[k-1]);
            runs.push_back(hand[k]);
            runs.push_back(hand[k+1]);
            hand.erase(k);
            hand.erase(k-1);
            hand.erase(k+1);
        }
         */
        
    }
}                   
          
          
};
