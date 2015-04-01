#include "MainDeck.h"

MainDeck::MainDeck(){
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++){
			deck.push_back(card{i, j});
		}
	}	
}

void MainDeck::displayDeck(){
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

void MainDeck::shuffleMainDeck(int numShuffle){

	for (int i = numShuffle; i > 0; i--){

		random_device timmiesRandomDevice;
		default_random_engine timmiesRandomEngine(timmiesRandomDevice());
		uniform_int_distribution<int> timmiesDistributor(1, 1729);
		shuffle(deck.begin(), deck.end(), timmiesRandomEngine);
	}

}