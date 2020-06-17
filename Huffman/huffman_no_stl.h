#ifndef HUFFMAN_NO_STL_H
#define HUFFMAN_NO_STL_H

#include <string>

using namespace std;

/* ppt에서 설명한 char를 활용한 index 구하는 함수
 */
// int charToIndex(char ch);
// char indextoChar(int index);

/* 아래의 Node는 사용할 때 수정해서 사용하여도 됨.
 */

/*
struct Node
{
  char ch;
  int freq;
  Node* left;
  Node* right;
  Node();
  Node(char ch, int freq);
  Node & operator = (const Node & rhs);
};

class MinHeap
{
  private:
    Node* heapArray[64];
    int size = 0;

  public:
    Node* top();
    int getSize() { return this->size; }
    void swap(Node** x, Node** y);
    void heapify(int i);
    void pop();
    void push(Node *node);
};
*/

class HuffmanCode
{
  private:
/*
    MinHeap heap;
    string huffmanCodeTable[58] = {""};
    int freqs[58] = {0};
    Node* root;
*/  
  public: 
    // constructor
    //HuffmanCode();;

    /* 아래의 4개의 함수들은 사용해도 되고, 사용하지 않아도 됨.
     * 하지만 프로젝트 진행 시 어려움이 있다면 참고를 하여도 됨.
     */
    // void calcFreq(string source_file);
    // void buildHeap();
    // void buildTree();
    // void makeHuffmanCodeTable(Node* node, string str);

    // Implement here (위 4개의 함수를 사용하지 않는다면, 학생 본인이 만든 함수를 선언하는 부분)

    /* 아래의 4개의 함수들은 main.cpp에서 쓰이는 함수들이므로
     * 임의로 수정하지 말 것.
     */
    void buildHuffmanTree(string input_file);
    void printHuffmanTable();

    void encode(string input_file, string encoded_file);
    void decode(string encoded_file, string decoded_file);
};


#endif
