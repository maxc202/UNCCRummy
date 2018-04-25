
#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card(int s, int ord)
{
    if(s == 1)
    {
        suit = "Spades";
        symbol = "\u2660";
        suitnum = 1;
    }
    else if(s==2)
    {
        suit = "Hearts";
        symbol = "\u2764";
        suitnum = 2;
    }
    else if(s==3)
    {
        suit = "Diamonds";
        symbol = "\u2666";
        suitnum = 3;
    }
    else if(s==4)
    {
        suit = "Clubs";
        symbol = "\u2663";
        suitnum = 4;
    }
    
    if(ord>10)
    {
        face = true;
        order = ord;
        scoreval = 10;
    }
    else
    {
        face = false;
        scoreval = order = ord;
    }
    
    if(ord == 1)
    {
        pip = "Ace";
    }
    else if(ord == 11)
    {
        pip = "Jack";
    }
    else if(ord == 12)
    {
        pip = "Queen";
    }
    else if(ord == 13)
    {
        pip = "King";
    }
    else
    {
        pip = to_string(ord);
    }
}

string Card::getSuit()
{
    return suit;
}

string Card::getPip()
{
    return pip;
}

int Card::getScoreval()
{
    return scoreval;
}

int Card::getOrder()
{
    return order;
}

bool Card::operator < (const Card &right)
{
    if(suitnum < right.suitnum)
        return true;
    else if((suitnum==right.suitnum)&&(order<right.order))
        return true;
    else
        return false;
}

ostream& operator << (ostream &strm, Card &French)
{
    if(French.order==10)
    {
        strm << French.pip.substr(0,2) << French.symbol << " " ;
    }
    else if(French.order != 10)
    {
        strm << French.pip.substr(0,1) << French.symbol << " " ;
    }
    return strm;
}


