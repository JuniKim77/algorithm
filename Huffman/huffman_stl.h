#ifndef HUFFMAN_STL_H
#define HUFFMAN_STL_H

#include <string>
#include <queue>
#include <map>

using namespace std;


struct Node
{
  char ch;
  int freq;
  Node* left;
  Node* right;

  Node(char _ch, int _freq)
      : ch(_ch)
      , freq(_freq)
      , left(nullptr)
      , right(nullptr)
  {
  }

  Node(int _freq, Node* left, Node* right)
      : freq(_freq)
      , left(left)
      , right(right)
  {
  }
};


class Compare 
{
  public: 
    bool operator()(Node* left, Node* right)  
    {   
      return (left->freq > right->freq); 
    }   
}; 


class HuffmanCode
{
  private:
    priority_queue<Node*, vector<Node*>, Compare> pq;
    map<char, string> huffmanCodeTable;
    map<char, int> freqs;
    Node* root;
    // 소멸 헬프 함수
    void freeMemory(Node* node);

  public:
    // constructor
    HuffmanCode();
    // 소멸자
    ~HuffmanCode();

    // void calcFreq(string source_file);
    // void buildHeap();
    // void buildTree();
    // 테이블 빌드 헬프 함수
    void makeHuffmanCodeTable(Node* node, string str);

    void buildHuffmanTree(string source_file);
    void printHuffmanTable();

    void encode(string input_file, string binary_file);
    void decode(string binary_file, string output_file);
    // 디코딩 헬프 함수
    void decoding(ifstream* fin, ofstream* fout, Node* node);
};


#endif
