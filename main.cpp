
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;

vector<Card*> makedeck();  //Makes a deck of cards

int main() {
    vector<Card*> deck = makedeck();
    
    for (int k = 0; k < deck.size(); k++)
    {
        cout << endl << (*(deck[k])) << endl;
    }
    
    for (int k = 0; k < deck.size(); k++)
    {
        delete deck[k];
    }
    
    return 0;
}

vector<Card*> makedeck()
{
    vector<Card*> playdeck;
    Card* deckptr = NULL;
    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 14 ; j++){
            deckptr = new Card(i,j);
            playdeck.push_back(deckptr);
            cout << endl << *deckptr << endl;
        }
    }
    random_shuffle(playdeck.begin(),playdeck.end());
    return playdeck;
}


