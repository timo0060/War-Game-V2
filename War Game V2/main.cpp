#include <iostream>
#include <string>
#include <vector>

#include "MainDeck.h"

using namespace std;

int getNumShuffle();

int main(){
	//Create Main Deck (Holds all the cards)
	MainDeck mainDeck;


	//Declare game variables
	int numShuffle;

	numShuffle = getNumShuffle();

	cout << endl;

	mainDeck.shuffleMainDeck(numShuffle);
	mainDeck.displayDeck();

	system("pause");

	return 0;
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