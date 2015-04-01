#include "PlayerDeck.h"

PlayerDeck::PlayerDeck(){
	
}

PlayerDeck::~PlayerDeck(){

}

void PlayerDeck::addCard(MainDeck::card newCard){
	deck.push_back(newCard);
}

void PlayerDeck::displayDeck(){

	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << "Card " << (i + 1) << ": ";

		//Get which suit the card is, and output it
		switch (deck[i].suit){
		case 0:
			cout << "Suit: Heart, ";
			break;
		case 1:
			cout << "Suit: Diamond, ";
			break;
		case 2:
			cout << "Suit: Spade, ";
			break;
		case 3:
			cout << "Suit: Club, ";
			break;
		}
		//Output the face value (1 - 13)
		cout << "Value: " << (deck[i].faceValue + 1) << endl;
	}

}

int PlayerDeck::getSize(){
	return deck.size();
}