#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Card.h"
#include "Hand.h"

using namespace std;

//Global Vars
vector<Card*> deck;
Hand p1;
Hand cpu;
vector<Card*> discard;
//Function Templates
void ClearScreen();
int Menu();
void Instructions();
void PlayerVCpu();
void resetRound();
/*
int PlayerGinScoring();
int CpuGinScoring();
int PlayerKnockScoring();
int CpuKnockScoring();
*/

//**************************************************************************
int main(){


int menuSelection = 0;
ClearScreen();
while(menuSelection == 0)
				{
	menuSelection = Menu();
	if(menuSelection == 1)
	{
		PlayerVCpu();
	}
	if(menuSelection == 2)
	{
		Instructions();
		menuSelection = 0;
	}
	if(menuSelection == 3)
	{
		return 0;
	}
				}
}

//**************************************************************************
void ClearScreen()
{
for(int i = 0; i < 50; ++i)
{
cout << endl;
}
}
//**************************************************************************
int Menu()
{
string selection = "";
bool keepAsk = true;

cout << "GIN RUMMY" << endl << endl;
cout << "1. Player vs CPU" << endl;
cout << "2. Instructions" << endl;
cout << "3. Quit" << endl;

while (keepAsk) {
	cout << "Enter a number 1-3: ";
	cin >> selection;

if(selection.size() == 1 && isdigit(selection[0]) && selection[0] == '1' || selection[0] == '2' || selection[0] == '3')
{
	if(selection[0] == '1')
	{
		return 1;
	}
	if(selection[0] == '2')
	{
		return 2;
	}
	if(selection[0] == '3')
	{
		return 3;
	}
	}
}

}
//**************************************************************************
void Instructions()
{
ClearScreen();
cout << "How to Play:" << endl << endl;
cout << "Objective:" << endl;
cout << "The purpose of the game is to create as many Runs or Sets with your cards before your opponent." << endl;
cout << "A Run is when you have 3 or more cards of the same suit in sequence." << endl;
cout << "EX: Having 7, 8, and 9 of Clubs will be considered a Run." << endl;
cout << "A Set is when you have 3, or even four, of a kind." << endl;
cout << "EX: Having a 3 of Spades, 3 of Diamonds, and 3 of Hearts would be considered a Set." << endl << endl;
cout << "Dealing:" << endl;
cout << "A coin flip will decided whether the player or the computer will go first." << endl;
cout << "Each player is dealt seven cards, alternating between each player until both player's hand reaches seven." << endl;
cout << "After each person is dealt seven cards, a card from the top of the deck is then flipped to create the Discard Pile." << endl << endl;
cout << "Gameplay:" << endl;
cout << "Whoever is first will decided if they either want to take the card in the Discard Pile or choose a new card from the deck." << endl;
cout << "If they decided to take from the discard they will put it into their hand and also drop another card in the discard pile face up." << endl;
cout << "If they decided to take from the deck they will draw the top card and decided whether they want to take that card and drop another card into the Discard Pile, or just drop the card they drew into the Discard Pile and end their turn." << endl;
cout << "Turns will alternate as so until someone has made Runs or Sets will all the cards in their hand, or until someone Knocks" << endl << endl;
cout << "Scoring:" << endl;
cout << "There are two ways to end a game. The first way is to go into Gin. Gin is when a player has created either Runs or Sets with every card in his or her hand." << endl;
cout << "The person that scored Gin will sum up the face value of each of his opponent's UNMATCHED cards and add 20 points to it and add it to his overall score. The person that did NOT reach Gin will recieve no points." << endl;
cout << "Another way to end a round is to Knock.When the face value of all of you unmatched cards are less than 10 then they can Knock and end the round. When a Knock is called the player that DID NOT knock can Layoff his unmatched cards and match them to his opponents cards." << endl;
cout << "The person that did knock will take the sum of his opponents unmatch cards and subtract it to the sum of his own unmatched cards. If the total value is negative then the person that knocked gets those points. If it is positive then the person that did NOT knock will get the points." << endl;
}
//*******************************************************************************
void PlayerVCpu()
{

bool gameOver = false;
bool playerTurn = true;
int PLAYER_SCORE = 0;
int CPU_SCORE = 0;
int computerRandomVal;
resetRound();

while(!gameOver)
{
	string userInput;
	if(playerTurn && !gameOver)	//If it is the player's turn and the game is not over then execute this If-Statement.
	{	
		
		cout << "It is your turn. " << endl;
		p1.output();	//Displays players hand.
		cout << endl << "The top card on the discard is: ";
		discard.back()->output();
		cout << endl;
		cout << "Would you like to draw a card from the Deck or Discard pile?" << endl;
		cout << "Type in 'Deck' to draw from deck or 'Discard' to draw from the discard pile." << endl;
		cin >> userInput;
		if(userInput == "Discard")
		{
			p1.draw(discard.back());
			discard.pop_back();
		}
		if(userInput == "Deck")
		{
			p1.draw(deck.back());
			
			deck.pop_back();
		}
		//p1.findMelds();
		p1.findSets();
		p1.findRuns();
		p1.output();
		if(p1.checkDeadwood() <= 10)
		{
			cout << "Would you like to knock? Respond with 'Yes' or 'No'." << endl;
			cin >> userInput;
			if(userInput == "Yes")
			{
				if(p1.checkDeadwood() == 0)
				{
					cout << "You have reached Gin. Let's take the score." << endl;
					//PlayerGinScoring();				
					PLAYER_SCORE += p1.checkDeadwood();
					gameOver = true;
					break;
				}
			}
		}
		
		else 
		{
			p1.retMelds();			
			cout << "Choose a card to discard" << endl << "Type the number value of the card on the list." << endl;
			int numDisc;
			cin >> numDisc;
			discard.push_back(p1.discard(numDisc-1));	
			playerTurn = false;	
		}
		p1.output();

	}			
	else if(!playerTurn && !gameOver)	//If it's not the player's turn but the game is not over then execute the CPU's turn.
	{	
		cout << "It is the computers turn." << endl;
		srand(time(0));
		computerRandomVal = rand()%2;
		if(computerRandomVal = 0)	//Randomly generates whether the CPU will either take from the discard pile or the deck.
		{	
			cout << "The computer decided to draw from the discard pile." << endl;
			cpu.draw(discard.back());
			discard.pop_back();
		}
		if(computerRandomVal = 1)
		{
			cout << "The computer decided to draw from the deck." << endl;
			cpu.draw(deck.back());
			
			deck.pop_back();
		}
		//cpu.findMelds();
		//cpu.findSets();
		cpu.findRuns();
		
		if(cpu.checkDeadwood() <= 10)	//If the CPU's Deadwood is less than ten then it will knock.
		{	
			if(cpu.checkDeadwood() == 0)	//If the computer has no deadwood then the computer will go into Gin and will start to calculate the points.
			{	
				cout << "The computer has reached Gin. Let's take the score." << endl;
				//CpuGinScoring();
				gameOver = true;
				//break;
			}			
			cout << "The computer has knocked. Let's take the score." << endl;
			CPU_SCORE += cpu.checkDeadwood();
			gameOver = true;
			//break;
		}
		
		cpu.retMelds();
		discard.push_back(cpu.discard(1));
		playerTurn = true;
		cout << endl << endl << endl;
		
	}
}		
}
//*******************************************************************************
void resetRound()
{
	deck.clear();
	p1.handClear();
	cpu.handClear();
	discard.clear();	
	Card* deckptr = NULL;
   	 for(int i = 1; i < 5; i++){
       		 for(int j = 1; j < 14 ; j++){
            		deckptr = new Card(i,j);
            		deck.push_back(deckptr);
            		//cout << endl << *deckptr << endl;
        	}
    	}
	deckptr = deck[51];
	discard.push_back(deckptr);
	deck.pop_back();
	random_shuffle(deck.begin(), deck.end());
	for(int i = 0; i < 10; i++){
		p1.draw(deck.back());
		deck.pop_back();
	}	
	for(int i = 0; i < 10; i++){
		cpu.draw(deck.back());
		deck.pop_back();
	}
}
/*
//*******************************************************************************************************************
int PlayerGinScoring()
{

}
//*******************************************************************************************************************
int CpuGinScoring()
{
}
//*************************************************************************************************************
int PlayerKnockScoring()
{
}
//**************************************************************************************************************
int CpuKnockScoring()
{
}
*/

