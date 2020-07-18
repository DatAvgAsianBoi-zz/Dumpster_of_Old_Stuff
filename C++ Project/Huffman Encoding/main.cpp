#include "Huffman.h"


int main(){
      string inFS = "data.txt";

      Huffman_Encoding huff(inFS);
      huff.generate_Huffman_Code("output.txt");
      huff.print_Huffman_Code();
      huff.print_compression_ratio();
      return 0;
}
