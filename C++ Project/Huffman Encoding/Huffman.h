#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Huff_Node{
      char data;
      int frequency;
      Huff_Node* left;
      Huff_Node* right;

      Huff_Node(char d, int f): data(d), frequency(f), left(nullptr), right(nullptr) {};
};

struct huffcode{
      char data;
      string code;
      huffcode(char d, string c): data(d), code(c) {};
};

class Huffman_Encoding{
private:
      Huff_Node* huff_heap[129];
      int currSize;
      string inputstring;
      string huffstring;
      Huff_Node *root;
      huffcode* translation_table[129];

      //Helper Functions
      void insertNode(char data, int f);
      bool find(char data);
      void printheap();
      Huff_Node* pop();
      void fixHeap(int index);
      void printtree();
      void printtree(Huff_Node* temp);
      void generatehuffcode();
      void generatehuffcode(Huff_Node* temp, string prefix);

public:
      Huffman_Encoding(const std::string inFS);
      void print_Huffman_Code();
      void generate_Huffman_Code(const string outputfile);
      void print_compression_ratio();
};
#endif
