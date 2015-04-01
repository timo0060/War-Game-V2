#include <iostream>
#include <string>
#include <vector>
#include "MainDeck.h"

using namespace std;

#ifndef PLAYERDECK_H
#define PLAYERDECK_H

class PlayerDeck{

public:

	//Default Constructor
	PlayerDeck();

	//Destructor
	~PlayerDeck();

	//Methods
	void addCard(MainDeck::card);
	void displayDeck();
	int getSize();
	MainDeck::card getFront();
	void eraseCard();
	void eraseCard(int);

private:
	vector<MainDeck::card>deck;

};

#endif
