#include "arithmeticExpression.h"

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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

arithmeticExpression::arithmeticExpression(const string &express){
      root = nullptr;
      infixExpression = express;
}

void arithmeticExpression::buildTree(){
      stack<TreeNode*> operations;
      string postfix = infix_to_postfix();
      int count = 0;
      string alp = "abcdefghijklmnopqrstuvwxyz";
      //pushing everything to stack
      for(char c: postfix){
            TreeNode* newNode = new TreeNode(c,alp[count++]);
            if(priority(c) == 0)
                  operations.push(newNode);
            else{
                  newNode->right = operations.top();
                  operations.pop();
                  newNode->left = operations.top();
                  operations.pop();
                  operations.push(newNode);
            }
      }
      root = operations.top();
}

void arithmeticExpression::infix(){
      infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix(){
      prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix(){
      postfix(root);
}


void arithmeticExpression::infix(TreeNode *node){
      if(node == nullptr)
            return;
      if(priority(node->data) > 0)
            cout << "(";
      infix(node->left);
      cout << node->data;
      infix(node->right);
      if(priority(node->data) > 0)
            cout << ")";
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
   by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode *node){
      if(node == nullptr)
            return;
      cout << node->data;
      prefix(node->left);
      prefix(node->right);
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
   by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode *node){
      if(node == nullptr)
            return;
      postfix(node->left);
      postfix(node->right);
      cout << node->data;
}

/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream &outFS, TreeNode *node){
      if(node == nullptr)
            return;

      visualizeTree(outFS, node->left);

      outFS << node->key << " [label=\"" << node->data << "\"]" << endl;

      visualizeTree(outFS, node->right);

      if(node->left != nullptr)
            outFS << node->key << "->" << node->left->key << endl;
      if(node->right != nullptr)
            outFS << node->key << "->" << node->right->key << endl;


}
