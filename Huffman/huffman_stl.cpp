#include "huffman_stl.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void HuffmanCode::freeMemory(Node* node)
{
    if (node->left != nullptr)
    {
        freeMemory(node->left);
    }
    if (node->right != nullptr)
    {
        freeMemory(node->right);
    }

    delete node;
}

HuffmanCode::HuffmanCode()
    : root(nullptr)
{
}

HuffmanCode::~HuffmanCode()
{
    freeMemory(root);
}

void HuffmanCode::makeHuffmanCodeTable(Node* node, string str)
{
    // Leaf노드가 나올 때까지 재귀적으로 계속 호출함
    if (node->left != nullptr)
    {
        makeHuffmanCodeTable(node->left, str + "0");
    }
    if (node->right != nullptr)
    {
        makeHuffmanCodeTable(node->right, str + "1");
    }
    // Leaf 노드일때, 테이블에 기록
    if (node->left == nullptr && node->right == nullptr)
    {
        huffmanCodeTable[node->ch] = str;
    }
}

void HuffmanCode::buildHuffmanTree(string source_file)
{
  // Implement here
    ifstream fin;
    fin.open(source_file, ios_base::in);
    
    char character;
    while (true)
    {
        fin.get(character);
        // EOF시, 실패 -> 끝
        if (fin.fail())
        {
            break;
        }
        freqs[character]++;
    }
    // freqs를 pq로 옮김, 알아서 정렬됨. 그래서 priority_queue가 필요
    for (auto iter = freqs.begin(); iter != freqs.end(); ++iter)
    {
        Node* node = new Node(iter->first, iter->second);
        pq.push(node);
    }
    // 크기 2까지 계속 진행하다 보면 마지막엔 크기 1짜리 노드만 남음.
    while (pq.size() >= 2)
    {
        Node* node1 = pq.top();
        pq.pop();
        Node* node2 = pq.top();
        pq.pop();

        Node* newNode = new Node(node1->freq + node2->freq, node1, node2);

        pq.push(newNode);
    }
    // 그 마지막 노드가 root 노드가 됨
    root = pq.top();
    pq.pop();

    makeHuffmanCodeTable(root, "");

    fin.close();
}

void HuffmanCode::printHuffmanTable()
{
    // Implement here
    cout << "Huffman Code Table" << endl << endl;
    for (auto iter = huffmanCodeTable.begin(); iter != huffmanCodeTable.end(); ++iter)
    {
        // 빈칸 일시,
        if (iter->first == 32)
        {
            cout << setw(5) << left << "ws";
        }
        // 뉴 라인 일시
        else if (iter->first == 10)
        {
            cout << setw(5) << left << "nl";
        }
        else
        {
            cout << setw(5) << left << iter->first;
        }
        
        cout << iter->second << endl;
    }
}


void HuffmanCode::encode(string input_file, string encoded_file)
{
    // Implement here
    ifstream fin;
    fin.open(input_file, ios_base::in);
    ofstream fout;
    fout.open(encoded_file);

    char character;
    while (true)
    {
        fin.get(character);
        if (fin.fail())
        {
            break;
        }
        fout << huffmanCodeTable[character];
    }

    fin.close();
    fout.close();
}


void HuffmanCode::decode(string encoded_file, string decoded_file)
{
    // Implement here
    ifstream fin;
    fin.open(encoded_file, ios_base::in);
    ofstream fout;
    fout.open(decoded_file);

    char character;
    while (true)
    {
        fin.get(character);
        if (fin.fail())
        {
            break;
        }
        // 0이면 왼쪽 노드 호출 fin 과 fout을 넘겨줘서 읽고 쓰는 것을 일치시킴
        if (character == '0')
        {
            decoding(&fin, &fout, root->left);
        }
        // 1이면 오른쪽 노드 호출 fin 과 fout을 넘겨줘서 읽고 쓰는 것을 일치시킴
        else
        {
            decoding(&fin, &fout, root->right);
        }
    }

    fin.close();
    fout.close();
}

void HuffmanCode::decoding(ifstream* fin, ofstream* fout, Node* node)
{
    // Leaf 노드이면 출력!
    if (node->left == nullptr && node->right == nullptr)
    {
        *fout << node->ch;
        return;
    }

    char character;
    fin->get(character);
    // 0이면 왼쪽 노드 호출 fin 과 fout을 넘겨줘서 읽고 쓰는 것을 일치시킴
    if (character == '0')
    {
        decoding(fin, fout, node->left);
    }
    // 1이면 오른쪽 노드 호출 fin 과 fout을 넘겨줘서 읽고 쓰는 것을 일치시킴
    else
    {
        decoding(fin, fout, node->right);
    }
}
