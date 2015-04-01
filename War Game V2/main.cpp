#include <iostream>
#include <string>
#include <vector>

#include "MainDeck.h"
#include "PlayerDeck.h"

using namespace std;

int getNumShuffle();
void splitDeck();
void getPlayerName();

//Create Main Decks (Holds all the cards)
MainDeck mainDeck;
PlayerDeck playerDeck;
PlayerDeck compDeck;

string playerName;

int main(){
	
	//Declare game variables
	int numShuffle;
	bool play = true;
	bool gameOver = false;

	getPlayerName();

	cout << "So, people call you " << playerName << "? Well welcome to WAR!" << endl << endl;

	numShuffle = getNumShuffle();

	cout << endl;

	mainDeck.shuffleMainDeck(numShuffle);
	
	splitDeck();

	cout << "The Deck has been split........" << endl << endl;



	system("pause");

	return 0;
}

void getPlayerName(){

	cout << "Welcome Player, What is your name? ";
	cin >> playerName;
}

int getNumShuffle(){

	bool shuffleIsNumber = false;
	int numShuffle;
	string shuffleInput;

	//Do this while the player has yet to enter a valid number
	do{
		//Ask the player
		cout << "How many times would you like to shuffle the deck? ";
		cin >> shuffleInput;	//get the player's input

		try{
			numShuffle = std::stoi(shuffleInput);

			if (numShuffle > 0){
				shuffleIsNumber = true;
				cout << numShuffle << endl;
			}
			else{
				cout << "Please enter an Integer greater then 0" << endl << endl;
			}
		}
		catch (exception e){
			cout << "Please enter an Integer greater then 0" << endl << endl;
		}

	} while (!shuffleIsNumber);

	return numShuffle;
}

//Split the deck
void splitDeck(){

	int mainDeckHalf = (mainDeck.getSize() / 2);

	for (int i = 0; i < mainDeckHalf; i++){		
		playerDeck.addCard(mainDeck.getCard(i));
		compDeck.addCard(mainDeck.getCard(i + mainDeckHalf));
	}

}