#include "BSTree.h"

Node*  BSTree::getNode(const string &word)const{
      Node* temp = root;
      while(temp->word != word){
            if(word < temp->word)
                  temp = temp->left;
            else if(word > temp->word)
                  temp = temp->right;
            else
                  return temp;
      }
      return temp;
}

Node* BSTree::getParent(const string& word){
      //word should never be root
      if(root == nullptr)
            return nullptr;
      if(word == root->word)
            return nullptr;
      Node* temp = root;
      while(temp != nullptr){
            if(word < temp->word){
                  if(temp->left->word == word)
                        return temp;
                  temp = temp->left;
            }
            else{
                  if(temp->right->word == word)
                        return temp;
                  temp = temp->right;
            }
      }
      cout << "Unreachable line is reached in getParent()" << endl;
      return temp; //This line should never reach

}

bool BSTree::isleftsibling(Node* parent, Node* kid){
      return parent->left == kid;
}

void BSTree::insert(const string & word){
      if(root == nullptr){
            root = new Node(word, 1);
            return;
      }

      //Increment count if word already exist
      if(search(word)){
            Node* temp = getNode(word);
            temp->count = temp->count + 1;
            return;
      }

      Node* temp = root;
      while(temp != nullptr){
            if(word < temp->word){
                  if(temp->left == nullptr){
                        // cout << word  << " is left child of " << temp->word << endl;
                        temp->left = new Node(word, 1);
                        return;
                  }
                  else
                        temp = temp->left;
            }
            else{
                  if(temp->right == nullptr){
                        // cout << word  << " is right child of " << temp->word << endl;
                        temp->right = new Node(word,1);
                        return;
                  }
                  else
                        temp = temp->right;
            }
      }
}

bool BSTree::search(const string &word) const{
      if(root == nullptr)
            return false;

      Node* temp = root;
      while(temp != nullptr){
            if(temp->word == word)
                  return true;
            if(word < temp->word)
                  temp = temp->left;
            else
                  temp = temp->right;
      }
      return false;
}

string BSTree::largest() const{
      Node* temp = root;
      while(temp != nullptr){
            if(temp->right == nullptr)
                  return temp->word;
            temp = temp->right;
      }
      return "";
}

string BSTree::smallest() const{
      Node* temp = root;
      while(temp!= nullptr){
            if(temp->left == nullptr)
                  return temp->word;
            temp = temp->left;
      }
      return "";
}

int BSTree::height(const string &word) const{
      if(root == nullptr || !search(word))
            return -1;
      int hl = (height(getNode(word)->left)), hr = height(getNode(word)->right);
      return  (hl>hr?hl:hr);
}

int BSTree::height(Node* node) const{
      if(node == nullptr)
            return 0;
      int lefth = height(node->left);
      int righth = height(node->right);
      if(lefth > righth)
            return ++lefth;
      return ++righth;
}

int BSTree::numChild(Node* node){
      if(node == nullptr)
            return -1;
      if(node->left == nullptr && node->right == nullptr)
            return 0;
      if(node->left == nullptr || node->right == nullptr)
            return 1;
      return 2;
}

void BSTree::remove(const string& word){
      //Exit if word doesnt exist
      if(!search(word))
            return;

      Node* toRemove = getNode(word);

      //Decrease count if count > 1
      if(toRemove->count > 1){
            toRemove->count = toRemove->count - 1;
            return;
      }

      //If toRemove is leaf node, kill it
      if(numChild(toRemove) == 0){
            //Root case
            if(word == root->word){
                  // cout << "Root is being removed";
                  root = nullptr;
                  delete toRemove;
                  return;
            }
            //toRemove must have parent - all other case
            Node* parent = getParent(word);
            if(isleftsibling(parent,toRemove))
                  parent->left = nullptr;
            else
                  parent->right = nullptr;
            delete toRemove;
            return;
      }
      // cout << "Node have children" << endl;
      //if node has child
      Node* sucessor;
      if(toRemove->left != nullptr){
            sucessor = toRemove->left;
            while(sucessor->right != nullptr)
                  sucessor = sucessor->right;
            // cout << "Node has left child" << endl;
      }
      else{
            sucessor = toRemove->right;
            while(sucessor->left != nullptr)
                  sucessor = sucessor->left;
            // cout << "Node has right child" << endl;
      }
      string newWord = sucessor->word;
      int newCount = sucessor->count;
      // cout << "calling remove()" << endl;
      remove(sucessor);
      toRemove->word = newWord;
      toRemove->count = newCount;
      // cout << "Done";

}

void BSTree::remove(Node* toBeRemoved){
      if(toBeRemoved == nullptr)
            return;

      if(numChild(toBeRemoved) == 0){
            if(toBeRemoved == root)
                  root = nullptr;
            else{
                  Node* parent = getParent(toBeRemoved->word);
                  if(isleftsibling(parent,toBeRemoved))
                        parent->left = nullptr;
                  else
                        parent->right = nullptr;
            }
            delete toBeRemoved;
            return;
      }

      //if node has child
      Node* sucessor;
      if(toBeRemoved->left != nullptr){
            sucessor = toBeRemoved->left;
            while(sucessor->right != nullptr)
                  sucessor = sucessor->right;
      }
      else{
            sucessor = toBeRemoved->right;
            while(sucessor->left != nullptr)
                  sucessor = sucessor->left;
      }
      string newWord = sucessor->word;
      int newCount = sucessor->count;
      remove(sucessor);
      toBeRemoved->word = newWord;
      toBeRemoved->count = newCount;


}

void BSTree::inOrder( ) const{
      inOrder(root);
      cout << endl;
}

void BSTree::postOrder( ) const{
      // cout << "Root is " << root->word << endl;
      postOrder(root);
      cout << endl;
}

void BSTree::preOrder( ) const{
      preOrder(root);
      cout << endl;
}

void BSTree::inOrder( Node* node )const {
      if(node == nullptr)
            return;
      inOrder(node->left);
      cout << node->word << "(" << to_string(node->count) << "), ";
      inOrder(node->right);
}

void BSTree::postOrder( Node* node )const {
      if(node == nullptr)
            return;

      postOrder(node->left);
      postOrder(node->right);
      cout << node->word << "(" << to_string(node->count) << "), ";
}

void BSTree::preOrder( Node* node )const {
      if(node == nullptr)
            return;
      cout << node->word << "(" << to_string(node->count) << "), ";
      preOrder(node->left);
      preOrder(node->right);
}
