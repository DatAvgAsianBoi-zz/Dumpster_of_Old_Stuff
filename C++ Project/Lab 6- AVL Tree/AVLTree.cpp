#include "AVLTree.h"

//Public
void AVLTree::insert(const string &word){
      Node* newNode = new Node(word);
      if(root == nullptr){
            root = newNode;
            return;
      }

      Node* temp = root;
      while(temp != nullptr){
            if(word < temp->word){
                  if(temp->left == nullptr){
                        temp->left = newNode;
                        break;
                  }
                  temp = temp->left;
            }
            else if(word == temp->word)
                  return;
            else{
                  if(temp->right == nullptr){
                        if(temp->right == nullptr){
                              temp->right = newNode;
                              break;
                        }
                  }
                  temp = temp->right;
            }
      }
      Node* unbalanced = findUnbalancedNode(newNode);
      while(unbalanced != nullptr){
            rotate(unbalanced);
            unbalanced = findUnbalancedNode(newNode);
      }
}
int AVLTree::balanceFactor(Node* currNode){
      return height(currNode->left) - height(currNode->right);
}
void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
void AVLTree::printBalanceFactors(){
      printBalanceFactor(root);
      cout << endl;
}

//Private
int AVLTree::height(Node* node){
      if(node == nullptr)
            return -1;
      int leftHeight = height(node->left);
      int rightHeight= height(node->right);

      if(leftHeight>rightHeight)
            return ++leftHeight;
      return ++rightHeight;
}
Node* AVLTree::getParent(Node* node){
      if(node == root)
            return nullptr;
      string word = node->word;
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
      return nullptr;
}
Node* AVLTree::findUnbalancedNode(Node* inserted_node){
      if(inserted_node == nullptr)
            return nullptr;
      if(balanceFactor(inserted_node) < -1 || balanceFactor(inserted_node)> 1)
            return inserted_node;
      return findUnbalancedNode(getParent(inserted_node));
}
void AVLTree::rotate(Node* currNode){
      Node* parent = getParent(currNode);
      bool isroot = false;
      bool isleft = true;
      if(parent == nullptr)
            isroot = true;
      else if(parent->left != currNode)
            isleft = false;
      Node* newcurr;
      //left cases
      if(balanceFactor(currNode) > 1){
            //left-left
            if(balanceFactor(currNode->left) > 0){
                  newcurr = rotateRight(currNode);
            }
            else{
                  //left-right
                  currNode->left = rotateLeft(currNode->left);
                  newcurr = rotateRight(currNode);
            }
      }

      //right cases
      else{
            //right-right
            if(balanceFactor(currNode->right) < 0){
                  newcurr = rotateLeft(currNode);
            }
            //right-left
            else{
                  currNode->right = rotateRight(currNode->right);
                  newcurr = rotateLeft(currNode);
            }
      }

      if(isroot){
            root = newcurr;
            return;
      }

      if(isleft)
            parent->left = newcurr;
      else
            parent->right = newcurr;
}
Node* AVLTree::rotateLeft(Node* x){
      /*
                  x
                /  \
            xleft   y
                  /   \
               yleft  yright

              to

                    y
                  /  \
                x    yright
              /   \
          xleft  yleft
      */

      if(x == nullptr)
            return x;
      Node* y = x->right;
      if(y == nullptr)
            return y;
      Node* yleft = y->left;

      y->left = x;
      x->right = yleft;
      return y;
}
Node* AVLTree::rotateRight(Node* y){
      /*
                  y
                /  \
              x    yright
            /   \
        xleft  xright

            to

                  x
                /  \
            xleft   y
                  /   \
               xright  yright
      */

      if(y == nullptr)
            return y;
      Node* x = y->left;
      if(y == nullptr)
            return y;
      Node* xright = x->right;

      x->right = y;
      y->left = xright;
      return x;
}
void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->word <<" -> " <<n->left->word<<";"<<endl;
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->word <<" -> " <<n->right->word<<";"<<endl;
        }
    }
}
void AVLTree::printBalanceFactor(Node* node){
      if(node == nullptr)
            return ;
      printBalanceFactor(node->left);
      cout << node->word << "(" << to_string(balanceFactor(node)) << "), ";
      printBalanceFactor(node->right);
}
void AVLTree::printInorder(Node* node){
      if(node == nullptr)
            return;
      printInorder(node->left);
      cout << node->word << " ";
      printInorder(node->right);
}
