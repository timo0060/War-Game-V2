#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PLAYINGDECK_H
#define PLAYINGDECK_H

class PlayingDeck{
public:

	struct card{
		int suit;
		int faceValue;
	};


	//Default constructor
	PlayingDeck();

private:
	vector<card>deck;

};


#endif