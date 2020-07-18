#include "Huffman.h"

//Public Functions
Huffman_Encoding::Huffman_Encoding(const string filename){
      currSize = 0;
      inputstring = "";
      huffstring = "";
      root = nullptr;


      ifstream inFS(filename);

      if(!inFS){
            cout << "Error Opening Input File" << endl;
            return;
      }

      // string inputstring = "";
      char input;
      inFS.get(input);
      while(!inFS.eof()){
            inputstring+=input;
            inFS.get(input);
      }

      inFS.clear();
      for(int i = 0; i < inputstring.size(); i++){
            char data = inputstring.at(i);
            if(!find(data)){
                  int freq = 1;
                  for(int j = i+1; j < inputstring.size(); j++)
                        if(inputstring.at(j) == data)
                              freq++;
                  insertNode(data,freq);
            }
      }

}
void Huffman_Encoding::print_Huffman_Code(){
      cout << "===============================Translation Table===============================" << endl;
      for(int i = 0; i < currSize; i++)
            if(translation_table[i]->data == '\t')
                  cout << "\\t" << "\t||\t" << translation_table[i]->code << endl;
            else if(translation_table[i]->data == '\n')
                  cout << "\\n" << "\t||\t" << translation_table[i]->code << endl;
            else if(translation_table[i]->data == ' ')
                  cout << "\' \'" << "\t||\t" << translation_table[i]->code << endl;
            else
                  cout << translation_table[i]->data << "\t||\t" << translation_table[i]->code << endl;
      cout << "===============================Translation Table===============================" << endl;
      cout << "Original Text: " << inputstring << endl;
      // for(int i = 0; i < inputstring.size(); i++)
      //       if(inputstring.at(i) == '\t' || inputstring.at(i) == '\n' || inputstring.at(i) == ' ')
      //             cout << inputstring.at(i);
      //       else
      //             for(int j = 0; j < currSize; j++)
      //                   if(translation_table[j]->data == inputstring.at(i)){
      //                         cout << translation_table[j]->code;
      //                         break;
      //                   }
      cout << huffstring;
      cout << endl;
}
void Huffman_Encoding::generate_Huffman_Code(string filename){
      ofstream outFS(filename);
      if(!outFS){
            cout << "Error Opening Output File" << endl;
            return;
      }

      //Base case, where there are only 1 or 2 character
      root = new Huff_Node(0,0);
      Huff_Node* temp = pop();
      if(temp == nullptr)     return;
      root->right = temp;
      temp = pop();
      if(temp == nullptr){
            root->left = root->right;
            root->right = nullptr;
            //generate huffman code based on this root
            generatehuffcode();
      }
      else{
            root->left = temp;

            //Dealing with more than 1 and 2 character
            temp = pop();
            while(temp != nullptr){
                  Huff_Node* temproot = new Huff_Node(0,0);
                  temproot->right = root;
                  temproot->left = temp;
                  root = temproot;
                  temp = pop();
            }
            // printtree();
            generatehuffcode();
            // for(int i = 0; i < currSize; i++)
            //       cout << translation_table[i]->data << "(" << translation_table[i]->code << ") " ;
            // cout << endl;
      }
      // outFS << "NANI THE FUCK";
      // cout << inputstring << endl;
      for(int i = 0; i < inputstring.size(); i++)
            // if(inputstring.at(i) == '\t' || inputstring.at(i) == '\n' || inputstring.at(i) == ' '){
            //       huffstring+= inputstring.at(i);
            // }
            // else
                  for(int j = 0; j < currSize; j++)
                        if(translation_table[j]->data == inputstring.at(i)){
                              huffstring+= translation_table[j]->code;
                              break;
                        }

      outFS << "===============================Translation Table===============================" << endl;
      for(int i = 0; i < currSize; i++)
            if(translation_table[i]->data == '\t')
                  outFS << "\\t" << "\t||\t" << translation_table[i]->code << endl;
            else if(translation_table[i]->data == '\n')
                  outFS << "\\n" << "\t||\t" << translation_table[i]->code << endl;
            else if(translation_table[i]->data == ' ')
                  outFS << "\' \'" << "\t||\t" << translation_table[i]->code << endl;
            else
                  outFS << translation_table[i]->data << "\t||\t" << translation_table[i]->code << endl;
      outFS << "===============================Translation Table===============================" << endl;
      outFS << "Original Text: " << inputstring << endl;
      outFS << huffstring;

}
void Huffman_Encoding::print_compression_ratio(){
      if(inputstring.size() == 0) return;

      long long totalbyte = 0;
      long long charbyte = 8;
      for(int i = 0; i < inputstring.size(); i++)
            if(inputstring.at(i) != '\t' && inputstring.at(i) != '\n' && inputstring.at(i) != ' ')
                  totalbyte+=charbyte;


      long long hbyte = 0;
      for(int i = 0; i < huffstring.size(); i++)
            if(huffstring.at(i) != '\t' && huffstring.at(i) != '\n' && huffstring.at(i) != ' ')
                  hbyte+=1;
      cout << "Compression Ration: ";
      cout << hbyte/hbyte << ":" << (totalbyte* 1.0) /hbyte << endl;

}





//Helper Functions
void Huffman_Encoding::insertNode(char data, int frequency){
      Huff_Node* temp = new Huff_Node(data, frequency);
      huff_heap[++currSize] = temp;

      int curr = currSize;
      int parent = currSize/2;

      while(parent > 0)
            if(huff_heap[curr]->frequency <= huff_heap[parent]->frequency){
                  huff_heap[curr] = huff_heap[parent];
                  huff_heap[parent] = temp;
                  curr = parent;
                  parent = curr/2;
            }
            else
                  break;

}
void Huffman_Encoding::printheap(){
      if(currSize == 0) return;
      for(int i = 1; i < currSize+1; i++)
            cout << huff_heap[i]->data << "(" << huff_heap[i]->frequency << ")\n";
}
bool Huffman_Encoding::find(char data){
      for(int i  = 1; i < currSize+1; i++)
            if(huff_heap[i]->data == data)
                  return true;

      return false;
}
Huff_Node* Huffman_Encoding::pop(){
      if(currSize == 0) return nullptr;
      Huff_Node* temp = huff_heap[1];
      huff_heap[1] = huff_heap[currSize--];

      fixHeap(1);

      return temp;
}
void Huffman_Encoding::fixHeap(int index){
      if(index >= currSize) return;

      int child1 = index*2;
      if(child1 < currSize){
            if(huff_heap[child1]->frequency < huff_heap[index]->frequency){
                  Huff_Node *temp = huff_heap[index];
                  huff_heap[index] = huff_heap[child1];
                  huff_heap[child1] = temp;
                  fixHeap(child1);
                  fixHeap(index);
            }
            else{
                  int child2 = child1+1;
                  if(huff_heap[child2]->frequency < huff_heap[index]->frequency){
                        Huff_Node *temp = huff_heap[index];
                        huff_heap[index] = huff_heap[child2];
                        huff_heap[child2] = temp;
                        fixHeap(child2);
                        fixHeap(index);
                  }
            }
      }

}
void Huffman_Encoding::printtree(){
      printtree(root);
      cout << endl;
}
void Huffman_Encoding::printtree(Huff_Node* temp){
      if(temp == nullptr)     return;
      printtree(temp->left);
      if(temp->frequency != 0)
            cout << temp->data << "(" << temp->frequency << ") ";
      else
            cout << "r ";
      printtree(temp->right);
}
void Huffman_Encoding::generatehuffcode(){
      currSize = 0;
      generatehuffcode(root, "");
}
void Huffman_Encoding::generatehuffcode(Huff_Node* temp, string prefix){
      if(temp == nullptr)     return;
      if(temp->frequency > 0)
            translation_table[currSize++] = new huffcode(temp->data,prefix);
      else{
            generatehuffcode(temp->left, prefix+"0");
            generatehuffcode(temp->right, prefix+"1");
      }
}
