#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>

using namespace std;

#ifndef MAINDECK_H
#define MAINDECK_H

class MainDeck{
public:

	struct card{
		int suit;
		int faceValue;
	};


	//Default constructor
	MainDeck();

	//Destructor
	~MainDeck();

	//Methods
	void displayDeck();
	void shuffleMainDeck(int);
	int getSize();
	card getCard(int);

private:
	vector<card>deck;

};


#endif