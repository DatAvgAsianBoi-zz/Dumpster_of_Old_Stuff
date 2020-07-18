#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

class BSTree {

private:
      Node *root;

private:
      Node* getNode(const string &)const; //Done
      Node* getParent(const string&); //Done
      bool isleftsibling(Node* parent, Node* kid); //Done
      int numChild(Node* node);//Done
      void remove(Node* node); //Done
      void inOrder(Node* node) const;
      void postOrder(Node *node) const;
      void preOrder(Node* node) const ;
      int height(Node* node) const;

public:
      BSTree(): root(nullptr){};
      void insert(const string &);      //Done
      bool search(const string &) const; //Done
      void inOrder( ) const;
      void postOrder( ) const;
      void preOrder( ) const;
      string largest( ) const; //Done
      string smallest( ) const; //Done
      int height(const string &) const; //Done
      void remove(const string &); //Done
};

#endif
