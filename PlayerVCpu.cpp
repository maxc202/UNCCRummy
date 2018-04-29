#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "Card.h"

using namespace std;

void PlayerVCpu();
bool WhoGoesFirst();
void ShuffleDeck();
void DealHands();
void DisplayHand();
void CheckMeld();
int CheckDeadwood();
int KnockScoring();
int GinScoring();

int main() {

PlayerVCpu();

return 0;
}
//***********************************************************************************************
void PlayerVCpu(){

//variables for as long as the game goes on.
bool playerTurn = true; //Reads true if it is the Humans turn.
bool gameOver = false;	//Reads false as long as no one has Knocked or got into Gin.
int computerRandomVal;	//Random value that will determine the CPU's decisions.
int playerPoints = 0;	//Keeps track of the players points.
int computerPoints = 0;	//Keeps track of the computers points.
string userInput; //String to decide what action the human player will do. 
Card topDiscard;	//The card on top of the discard pile.
Card topDeckCard;	//Card on top of the deck.
Card playerNewCard;	//Card that the human player draws either from the discard pile or the deck.
Card playerDiscard;	//Card that the human player will discard into the discard pile.
Card computerNewCard;	//Card that the CPU will draw either from the discard pile or the deck.
Card computerDiscard;	//Card that the CPU will discard into the discard pile.
vector<Card*> PlayerHand(7);	//List of Human player's hand that will have 7 cards;
vector <Card*> PlayerMeldHand;	//If the human player gets a run or set it will move those cards to this vector.
vector <Card*> PlayerDeadwoodHand;	//If the human player has cards that are not part of a set of it will move it to the this vector.
vector<Card*> ComputerHand(7);	//List of Computer players hand that will have seven cards;
vector<Card*> ComputerMeldHand;	//If the computer has cards that are part of a set or run it wil move it to this vector.
vector<Card*> ComputerDeadwoodHand;	//If the computer has cards that are not part of a run or set it move it to this vector.

ClearScreen();
WhoGoesFirst();
ShuffleDeck();
DealHands();
DisplayHand();

while(!gameOver){
	if(playerTurn && !gameOver){
		DisplayHand();
		cout << "It is your turn. Would you like to take from the discard pile or the deck?" << endl;
		cout << "Type in 'Discard' to take from the discard pile, or 'Deck' to take from the deck." << endl;
		cin >> userInput;
		if(userInput == "Discard"){
			playerNewCard = topDiscard;	//Players new card is the top of the discard pile.
			cout << "Which card would you like to get rid of?" << endl;
			cin >> PlayerHand[i];
			topDiscard = playerDiscard;
			DisplayHand();
		}
		if(userInput == "Deck"){
			playerNewCard = topDeckCard;	//Players new card if the card on top of the deck.
			cout << "Would you like to keep this card? Respond with 'Yes' or 'No'." << endl;
			cin >> userInput;
			if(userInput == "Yes"){
				cout << "What card would you like to discard then?" << endl;
				cin >> playerDiscard;
				topDiscard = playerDiscard;
				DisplayHand();
			}
			if(userInput == "No"){
				topDiscard = topDeckCard;
				DisplayHand();
			}
		}
		CheckMeld();
		CheckDeadwood();
		if(CheckDeadwood() < 10){
			cout << "Would you like to knock? Respond with 'Yes' or 'No'." << endl;
			cin >> userInput;
			if(userInput == "Yes"){
				KnockScoring();
				gameOver = true;
			}
			if(userINput == "No"){
				playerTurn = false;
			}
		}
		if(CheckDeadwood() = 0){
			cout << "You have reached Gin. Let's take the score." << endl;
			GinScoring();
			gameOver = true;
		}

	}			
	else if(!playerTurn && !gameOver){
		cout << "It is the computers turn." << endl;
		srand(time(0));
		computerRandomVal = rand()%2;
		if(computerRandomVal = 0){
			cout << "The computer decided to draw from the discard pile." << endl;
			computerNewCard = topDiscard;
			computerDiscard = computerHand[rand()%7];
			topDiscard = computerDiscard;
		}
		if(computerRandomVal = 1){
			cout << "The computer decided to draw from the deck." << endl;
			computerNewCard = topDeckCard;
			computerRandomVal = rand()%2;
			if(computerRandomVal = 0;){
				topDiscard = computerNewCard;
			}
			else{
				computerNewCard = topDeckCard;
				computerDiscard = computerHand[rand()%7];
				topDiscard = computerDiscard;
			}
		}
		CheckMeld();
		CheckDeadwood();
		if(CheckDeadwood() < 10){	//If the computers Deadwood is less than ten it will randomly generate whether the computer wants to knock or not.
			computerRandomVal = rand()%2;
			if(computerRandomVAl =0){
				computerTurn = false;
			}
			if(computerRandomVal = 1){
				cout << "The computer has decided to knock. Let's take the score." << endl;
				KnockingScoring();
				gameOver = true;
			}
		}
		if(CheckDeadwood() = 0;){	//If the computer has no deadwood then the computer will go into Gin and will start to calculate the points.
			cout << "The computer has reached Gin. Let's take the score." << endl;
			GinScoring();
			gameOver = true;
		}
	}
}
		
//************************************************************************************************
bool WhoGoesFirst(){	//This function decides whether the player or the computer will be going first.
srand(time(0));
	if(rand() %2 == 0){
		return true
	}
	else{
		return false
	}
}	
//************************************************************************************************
void ShuffleDeck(){	//This function shuffles the cards.
vector <Card*> Deck[52];
}
//************************************************************************************************
void DealHands(){	//This function will distribute the cards to the human and the computer player.

for(int i =0; i < 7; ++i){
	vector <Card*> PlayerHand[i] = Deck[rand()%52];
}
for(int i =0; i < 7; ++i){
	vector <Card*> ComputerHand[i] = Deck[rand()%52];
}

}
//************************************************************************************************
void DisplayHand(){	//This function will display the human players hand onto the screen.

for(int i =0; i < 7; ++i){
	cout << PlayerHand[i] << " ";
}

}
//************************************************************************************************
void CheckMeld(){	//This function will go through the human and computer player's hand. If there is a set or a run then it will be moved to another vector.
int setCounter;
int runCounter;
for(i = 0; i < 7; ++i){
	if(PlayerHand(i).pip == PlayerHand(i+1).pip){
		setCounter = secCounter + 1;
		
		
}
//************************************************************************************************
int CheckDeadwood(){	//This fucntion counts the sum of all the cards that do not have sets or runs and sees if the player can knock.
int deadWoodAmount = 0;

for(int i =0; i < 7; ++i){
	deadWoodAmount = deadWoodAmount + PlayerDeadwoodHand[i].scoreVal;
}

return deadWoodAmount;
}
//************************************************************************************************
int KnockScoring(){	//This function will count the score achieved by knocking and add it to the appropriate players overall score.

int playerDeadwoodAmount = 0;
int computerDeadwoodAmount = 0;
int amountScored = 0;

for(int i =0; i < 7; ++i){
	playerDeadwoodAmount = playerDeadwoodAmount + PlayerDeadwoodHand[i].scoreVal;
}
for(int i =0; i < 7; ++i){
	computerDeadwoodAmount = computerDeadwoodAmount + ComputerDeadwoodHand[i].scoreVal;
}

return amountScored;
}
//************************************************************************************************
int GinScoring(){	//This function will count the score achieved by reaching Gin and add it to the appropriate players overall score.
}
