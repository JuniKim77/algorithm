#include <iostream>

#ifdef STL
#include "huffman_stl.h"
#else
#include "huffman_no_stl.h"
#endif


using namespace std;

int main() {

    /* ppt에 언급하였듯이 아래에 있는 4개의 함수들은 건드리지 말 것.
     * 수정하였다가 그로 인해 발생하는 compile error등은 본인이 책임져야 함.
     */

    HuffmanCode H;

    // Building Huffman Code Tree with source file.
    H.buildHuffmanTree("./input_files/Aladdin.txt");
    H.printHuffmanTable();

    // Encoding (input file, output file)
    H.encode("./input_files/input.txt", "./output_files/encoded.txt");


    // Decoding (input file, output file)
    H.decode("./output_files/encoded.txt", "./output_files/decoded.txt");


    // Decoding question binary with no STL (58 charaters)
    H.decode("./input_files/question_encoded.txt", "./output_files/answer.txt");

    return 0;
}
