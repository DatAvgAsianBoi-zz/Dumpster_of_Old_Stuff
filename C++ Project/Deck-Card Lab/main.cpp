#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>

#include "Card.h"
#include "Deck.h"

using namespace std;

bool hasPair(vector<Card> &c){
  int size = c.size();
  for(int i = 0; i < size - 1; i++)
    for(int i2 = i+1; i2 < size; i2++)
      if(c.at(i).getRank() == c.at(i2).getRank())
        return true;
  return false;
}

int main(){
  srand(2222);
  string input;
  int simulations, numCards, pairFound = 0;
  string outputFile;


  cout << "Do you want to output all hands to a file?(Yes/No) ";
  cin >> input;
  cout << endl;

  if(input == "Yes" || input == "yes"){
    cout << "Enter name of output file: ";
    cin >> outputFile;
    cout << endl;
  }

  cout << "Enter number of cards per hand: ";
  cin >> numCards;
  cout << endl;

  cout << "Enter number of deals (simulations): ";
  cin >> simulations;
  cout << endl;


  Deck d;

  if(input == "Yes" || input == "yes"){
      ofstream fout(outputFile.c_str());
      if(!fout.is_open()){
        cout << "Error opening " << outputFile << endl;
        return 1;
      }
      for(int i = 0; i < simulations; i++){
          d.shuffleDeck();
          vector<Card> dealtCards;

          for(int c = 0; c < numCards; c++)
            dealtCards.push_back(d.dealCard());

          if(hasPair(dealtCards)){
            pairFound++;
            fout << "Found Pair!! ";
            for(int c = 0; c < numCards; c++){
              if(c == numCards - 1)
                fout << dealtCards.at(c);
              else
                fout << dealtCards.at(c) << ", ";
            }
          }
          else{
            fout << "             ";
            for(int c = 0; c < numCards; c++){
              if(c == numCards - 1)
                fout << dealtCards.at(c);
              else
                fout << dealtCards.at(c) << ", ";
            }
          }
          fout << endl;
      }
  }
  else{
    for(int i = 0; i < simulations; i++){
        d.shuffleDeck();
        vector<Card> dealtCards;

        for(int c = 0; c < numCards; c++)
          dealtCards.push_back(d.dealCard());

        if(hasPair(dealtCards))
          pairFound++;
    }
  }


  cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: ";
  cout << ((pairFound * 1.0) / (simulations * 1.0)) * 100;
  cout << "%" << endl;

  return 0;
}
