#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;

class AVLTree{
private:
      Node* root;
      Node* findUnbalancedNode(Node* inserted_node); //Done
      void printBalanceFactors(Node* currNode);//Done
      void visualizeTree(ofstream & outFS, Node* currNode); //Done
      int height(Node* startingNode); //Done
      Node* getParent(Node* node); //Done
      void printBalanceFactor(Node* node);
      void printInorder(Node* node);

      void rotate(Node* currNode); //Done
      Node* rotateLeft(Node* currNode); //Done
      Node* rotateRight(Node* currNode); //Done

public:
      AVLTree():root(nullptr){};
      void insert(const string &word); //Done
      int balanceFactor(Node* currNode); //Done
      void printBalanceFactors();
      void visualizeTree(const string& outFS); //Done
};





#endif
