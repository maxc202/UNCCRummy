#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class Card(){
private:
  int value; //1-13 (Ace through King)
  char suit; //d h s c
public:
  //Default constructor makes Ace of Spades
  Card(){
    value = 1;
    char = 's';
  }
  Card(int v, char c){
    value = v;
    char = c;
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
    
    if(char == 'd'){
      cout << "Diamonds";
    }
    else if(char == 's'){
      cout << "Spades";
    }
    else if(char == 'h'){
      cout << "Hearts";
    }
    else if(char == 'c'){
      cout << "Clubs";
    }
}

#endif
