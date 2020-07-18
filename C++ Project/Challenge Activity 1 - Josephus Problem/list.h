#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

using namespace std;


struct Node{
      string name;
      Node *next;
      Node(string name): name(name), next(nullptr){}
};

class list{
      Node* head;
      Node* tail;
public:
      list():head(nullptr), tail(nullptr){}

      ~list();
      void push_back(string name);
      void remove(string name);
      void print();
      int size();
      void playGame(int,int);
};


#endif
