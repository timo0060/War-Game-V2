#include <iostream>
#include <string>
#include <vector>

#include "MainDeck.h"
#include "PlayerDeck.h"

using namespace std;

int getNumShuffle();
void splitDeck();
void getPlayerName();
void playRound();
void playAutoRound();
bool isGameOver();
string getSuit(int);

//Create Main Decks (Holds all the cards)
MainDeck mainDeck;
PlayerDeck playerDeck;
PlayerDeck compDeck;
PlayerDeck tablePile;

string playerName;
string winner;

int main(){
	
	//Declare game variables
	int numShuffle;
	char playGame;
	bool play = true;
	bool gameOver = false;

	getPlayerName();

	cout << "So, people call you " << playerName << "? Well, welcome to WAR!" << endl << endl;

	numShuffle = getNumShuffle();

	cout << endl;

	mainDeck.shuffleMainDeck(numShuffle);
	
	splitDeck();

	cout << "The Deck has been split........" << endl << endl;

	//Ask the player if they'd like to automate the whole game
	cout << playerName << ", would you like to automate the game? (y/n) ";
	cin >> playGame;

	playGame = tolower(playGame);

	if (playGame == 'y'){
		while (!gameOver)
		{
			playAutoRound();
			gameOver = isGameOver();
		}

		cout << winner << " is the winner!" << endl << endl;

	}
	else if (playGame == 'n'){
		//Start the main play loop
		while (play){
			cout << endl << playerName << "'s Deck: " << playerDeck.getSize() << endl;
			cout << "Computers Deck: " << compDeck.getSize() << endl;

			cout << endl << "Play round? (y/n) : ";
			cin >> playGame; //Get the players input
			cout << endl;

			//Put the players input to lower case so it will ignore case
			playGame = tolower(playGame);

			//If they say no, end the loop thus ending the game.
			if (playGame == 'n'){
				play = false;
			}//If they say yes, continue the game
			else if (playGame == 'y'){
				play = true;
				playRound();
				gameOver = isGameOver();
			}
			else //If they put anything else in there, continue the loop, and inform the player it must be y or a n
			{
				cout << "That was not an y/n" << endl;
			}

			if (gameOver){
				play = false;

				cout << winner << " is the winner!" << endl << endl;
			}
		}
	}


	cout << "Game has ended...." << endl;

	system("pause");

	return 0;
}

void getPlayerName(){

	cout << "Welcome Player, What is your name? ";
	cin >> playerName;
	cout << endl;
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

//Loop through one round
void playRound(){

	bool isTie = false;

	cout << playerName << "'s Card: " << endl;
	cout << getSuit(playerDeck.getFront().suit) << ", " << playerDeck.getFront().faceValue << endl;

	cout << "Computers Card: " << endl;
	cout << getSuit(compDeck.getFront().suit) << ", " << compDeck.getFront().faceValue << endl;


	if (playerDeck.getFront().faceValue > compDeck.getFront().faceValue){
		cout << playerName << " Won this Hand" << endl;
		playerDeck.addCard(playerDeck.getFront());
		playerDeck.eraseCard();
		playerDeck.addCard(compDeck.getFront());
		compDeck.eraseCard();
	}
	else if (playerDeck.getFront().faceValue < compDeck.getFront().faceValue){
		cout << "Computer Won this Hand" << endl;
		compDeck.addCard(compDeck.getFront());
		compDeck.eraseCard();
		compDeck.addCard(playerDeck.getFront());
		playerDeck.eraseCard();
	}
	else{
		//Set isTie to be true
		isTie = true;
		//While it is still a tie, do this
		while (isTie){
			cout << "It was a Tie!!" << endl;

			//Remove the already flipped card, and the three top cards from the players hand and place them into the table vector
			for (int i = 0; i < 4; i++){
				tablePile.addCard(playerDeck.getFront());
				playerDeck.eraseCard();

				if (playerDeck.getSize() == 1){
					i = 4;
				}
			}
			//Remove the already flipped card, and the three top cards from the computers hand and place them into the table vector
			for (int i = 0; i < 4; i++){
				tablePile.addCard(compDeck.getFront());
				compDeck.eraseCard();

				if (compDeck.getSize() == 1){
					i = 4;
				}
			}

			cout << playerName << "'s Card: " << endl;
			cout << getSuit(playerDeck.getFront().suit) << ", " << playerDeck.getFront().faceValue << endl;

			cout << "Computers Card: " << endl;
			cout << getSuit(compDeck.getFront().suit) << ", " << compDeck.getFront().faceValue << endl;

			if (playerDeck.getFront().faceValue > compDeck.getFront().faceValue){
				cout << playerName << " Won The Tie" << endl;
				playerDeck.addCard(playerDeck.getFront());
				playerDeck.eraseCard();
				playerDeck.addCard(compDeck.getFront());
				compDeck.eraseCard();

				while (tablePile.getSize() > 0){
					playerDeck.addCard(tablePile.getFront());
					tablePile.eraseCard();
				}

				isTie = false;
			}
			else if (playerDeck.getFront().faceValue < compDeck.getFront().faceValue){
				cout << "Computer Won The Tie" << endl;
				compDeck.addCard(compDeck.getFront());
				compDeck.eraseCard();
				compDeck.addCard(playerDeck.getFront());
				playerDeck.eraseCard();

				while (tablePile.getSize() > 0){
					compDeck.addCard(tablePile.getFront());
					tablePile.eraseCard();
				}

				isTie = false;
			}
			else{
				cout << "Another Tie" << endl;
			}

		}
	}
}


//Get the cards suit
string getSuit(int suitNum){
	string suitString;

	switch (suitNum){
	case 0:
		cout << "Hearts";
		break;
	case 1:
		cout << "Diamonds";
		break;
	case 2:
		cout << "Spades";
		break;
	case 3:
		cout << "Clubs";
		break;
	}

	return suitString;
}

//Find out if the game is over
bool isGameOver(){

	if ((playerDeck.getSize() <= 0) || (compDeck.getSize() <= 0)){

		if (playerDeck.getSize() <= 0){
			winner = "The Computer";
		}
		else{
			winner = playerName;
		}

		return true;
	}

	return false;
}

//Play the entire game automatically
void playAutoRound(){

	bool isTie = false;


	if (playerDeck.getFront().faceValue > compDeck.getFront().faceValue){
		playerDeck.addCard(playerDeck.getFront());
		playerDeck.eraseCard();
		playerDeck.addCard(compDeck.getFront());
		compDeck.eraseCard();
	}
	else if (playerDeck.getFront().faceValue < compDeck.getFront().faceValue){
		compDeck.addCard(compDeck.getFront());
		compDeck.eraseCard();
		compDeck.addCard(playerDeck.getFront());
		playerDeck.eraseCard();
	}
	else{
		//Set isTie to be true
		isTie = true;
		//While it is still a tie, do this
		while (isTie){

			//Remove the already flipped card, and the three top cards from the players hand and place them into the table vector
			for (int i = 0; i < 4; i++){
				tablePile.addCard(playerDeck.getFront());
				playerDeck.eraseCard();
				if (playerDeck.getSize() == 1){
					i = 4;
				}
			}
			//Remove the already flipped card, and the three top cards from the computers hand and place them into the table vector
			for (int i = 0; i < 4; i++){
				tablePile.addCard(compDeck.getFront());
				compDeck.eraseCard();
				if (compDeck.getSize() == 1){
					i = 4;
				}
			}

			if (playerDeck.getFront().faceValue > compDeck.getFront().faceValue){
				playerDeck.addCard(playerDeck.getFront());
				playerDeck.eraseCard();
				playerDeck.addCard(compDeck.getFront());
				compDeck.eraseCard();

				while (tablePile.getSize() > 0){
					playerDeck.addCard(tablePile.getFront());
					tablePile.eraseCard();
				}

				isTie = false;
			}
			else if (playerDeck.getFront().faceValue < compDeck.getFront().faceValue){
				compDeck.addCard(compDeck.getFront());
				compDeck.eraseCard();
				compDeck.addCard(playerDeck.getFront());
				playerDeck.eraseCard();

				while (tablePile.getSize() > 0){
					compDeck.addCard(tablePile.getFront());
					tablePile.eraseCard();
				}

				isTie = false;
			}

		}
	}

}