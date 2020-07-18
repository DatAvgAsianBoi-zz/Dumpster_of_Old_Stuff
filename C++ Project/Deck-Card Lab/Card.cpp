#include <iostream>
#include <string>
#include "Card.h"

Card::Card(){
	suit = 'c';
	rank = 2;
}

Card::Card(char s, int r){
	string str = "cdhs";
	s = static_cast<char>(tolower(s));

	if(str.find(s) == string::npos)
		suit = 'c';
	else
		suit = s;

	if(r < 1 || r > 13)
		rank = 2;
	else
		rank = r;
}

char Card::getSuit() const{
	return suit;
}

int Card::getRank() const{
	return rank;
}

ostream & operator<<(ostream & out, const Card& card){
	int rank = card.getRank();
	char suit = card.getSuit();

	if(rank > 10 || rank == 1)
		if(rank == 1)
			out << "Ace";
		else if(rank == 11)
			out << "Jack";
		else if(rank == 12)
			out << "Queen";
		else
			out << "King";
	else
		out << rank;

	out << " of ";

	if(suit == 'c')
		out << "Clubs";
	else if(suit == 'd')
		out << "Diamonds";
	else if(suit == 'h')
		out << "Hearts";
	else
		out << "Spades";
	return out;
}
