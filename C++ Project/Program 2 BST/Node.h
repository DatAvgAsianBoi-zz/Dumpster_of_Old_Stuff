#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct  Node{
      string word;
      int count;
      Node* left;
      Node* right;

      Node(string w, int c);
};



#endif
