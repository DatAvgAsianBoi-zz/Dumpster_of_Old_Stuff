#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Deck.h"

using namespace std;


Deck::Deck(){
	vector<Card> temp;

	string str = "cdhs";
	for(unsigned i1 = 0; i1 < str.size(); i1++)
		for(unsigned i2 = 1; i2 < 14; i2++){
				temp.push_back(Card(str[i1],i2));
		}

	for(int i = 0; i < 52; i++){
		theDeck.push_back(temp.back());
		temp.pop_back();
	}
//	theDeck = temp;
	temp.clear();


	// cout << "The Deck" << endl;
	// for(int i = 0; i < 52 ; i++){
	// 	cout << theDeck.at(i) << "\t";
	// }
	// cout << endl;
}

Card Deck::dealCard(){
	// Card c = theDeck.front();
	// dealtCards.push_back(c);
	// theDeck.erase(theDeck.begin());

	Card c = theDeck.back();
	dealtCards.push_back(c);
	theDeck.pop_back();


	return c;
}

void Deck::shuffleDeck(){

	int size = dealtCards.size();

	for(int i = 0; i < size; i++){
		theDeck.push_back(dealtCards.front());
		dealtCards.erase(dealtCards.begin());
	}
	dealtCards.clear();

	random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const{
	return theDeck.size();
}
