//
//  Card.hpp
//  Rummy
//
//  Created by Maksim Chayun on 4/18/18.
//  Copyright © 2018 Maksim Chayun. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>
using namespace std;

class Card {
private:
    string suit, pip; //Suit should be obvious, pip is the "name" of the card "Jack" or "10"
    string symbol; //Unicode Symbol for the Suit
    int scoreval, order, suitnum; /* Scoreval is the is 10 for a facecard, and the number for the number card.  Order is the ordering of the card: Ace is 1, Two is 2, etc. */
    bool face; //If true, facecard.
public:
    //Constructor
    Card(int s, int ord); //Only one constructor, we don't need facecards without attributes
    //Getters
    string getSuit();
    string getPip();
    int getScoreval();
    int getOrder();
    //Overloaded Operators
    bool operator < (const Card &);
    friend ostream& operator << (ostream &, Card & ); /*
    J❤
    */
};


#endif /* Card_hpp */
