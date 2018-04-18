//
//  main.cpp
//  Stuff
//
//  Created by Maksim Chayun on 4/17/18.
//  Copyright © 2018 Maksim Chayun. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;


int main() {
    vector<Card*> deck;
    Card* deckptr = NULL;
    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 14 ; j++){
            deckptr = new Card(i,j);
            deck.push_back(deckptr);
            cout << endl << *deckptr << endl;
        }
    }
    
    cout << deck.size() << endl;
    
    /* random_shuffle(deck.begin(),deck.end());
    
    for (int k = 0; k < deck.size(); k++)
    {
        cout << endl << (*(deck[k])) << endl;
    }
    */
    
    for (int k = 0; k < deck.size(); k++)
    {
        delete deck[k];
    }
    
    //Card thisc(2,11); // Enter a number for a suit, and an order number. Try it
    //cout << thisc;
    return 0;
}
