#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class Card(){
private:
  int value; //1-13 (Ace through King)
  int suit; //0 1 2 3
public:
  //Default constructor makes Ace of Spades
  Card(){
    value = 1;
    suit = 0;
  }
  Card(int v, int c){
    value = v;
    suit = c;
  }
  void output(){
    if(value == 1){
      cout << "Ace of ";
    }
    else if(value == 11){
      cout << "Jack of ";
    }
    else if(value == 12){
      cout << "Queen of ";
    }
    else if(value == 13){
      cout << "King of ";
    }
    else{
      cout << value << " of ";
    }
    
    if(suit == 1){
      cout << "Diamonds";
    }
    else if(suit == 0){
      cout << "Spades";
    }
    else if(suit == 2){
      cout << "Hearts";
    }
    else if(suit == 3){
      cout << "Clubs";
    }
};

#endif
