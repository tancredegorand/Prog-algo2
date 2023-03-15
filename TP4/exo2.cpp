#include <time.h>
#include <stdio.h>

#include <QApplication>
#include <QDebug>

#include "tp3.h"
#include "tp4.h"
#include "HuffmanNode.h"

_TestMainWindow* w = nullptr;
using std::size_t;
using std::string;


void charFrequences(string data, Array& frequences)
{
    /**
      * Fill `frequences` array with each caracter frequence.
      * frequences is an array of 256 int. frequences[i]
      * is the frequence of the caracter with ASCII code i
     **/

    frequences.fill(0);

    // Your code
}

void HuffmanHeap::insertHeapNode(int heapSize, HuffmanNode* newNode)
{
    /**
      * Insert a HuffmanNode into the lower heap. A min-heap put the lowest value
      * as the first cell. Instead of storing int, the cells of HuffmanHeap store HuffmanNode*.
      * To compare these nodes use their frequences.
      * this->get(i): HuffmanNode*  <-> this->get(i)->frequences
     **/

    // Your code
}

void buildHuffmanHeap(const Array& frequences, HuffmanHeap& priorityMinHeap, int& heapSize)
{
    /**
      * Do like Heap::buildHeap. Use only non-null frequences
      * Define heapSize as numbers of inserted nodes
     **/
    heapSize = 0;

    // Your code
}

HuffmanNode* HuffmanHeap::extractMinNode(int heapSize)
{
    /**
      * Extract the first cell, replace the first cell with the last one and
      * heapify the heap to get a new well-formed heap without the returned cell
     **/

    // Your code

    return nullptr;
}

HuffmanNode* makeHuffmanSubTree(
    HuffmanNode* rightNode,
    HuffmanNode* leftNode
)
{

    /**
     * Make a subtree (parent + 2 children) with the given 2 nodes.
     * These 2 characters will be the children of a new parent node which character is '\0'
     * and frequence is the sum of the 2 children frequences
     * Return the new HuffmanNode* parent
     **/

    // Your code

    return nullptr;
}

void HuffmanNode::processCodes(std::string baseCode)
{
    /**
      * Travel whole tree of HuffmanNode, each time you call the left
      * child, add '0' to the baseCode and each time call the right
      * child, add '1'. If the node is a leaf, it takes the baseCode.
     **/

    // Your code
}

void HuffmanNode::fillCharactersArray(std::string charactersCodes[])
{
    /**
      * Fill the string array with all nodes codes of the tree
      * It store a node into the cell corresponding to its ascii code
      * For example: the node describing 'O' should be at index 79
     **/
    if (!this->left && !this->right)
        charactersCodes[this->character] = this->code;
    else {
        if (this->left)
            this->left->fillCharactersArray(charactersCodes);
        if (this->right)
            this->right->fillCharactersArray(charactersCodes);
    }
}


void displayCharacterFrequences(Array frequences)
{
    bool atLeastOne = false;
    qDebug("Frequences:");
    for (unsigned char i=0u; i<255u; i++)
    {
        if (frequences[i])
        {
            qDebug("\t%c: %d\n", i, frequences[i]);
            atLeastOne = true;
        }
    }
    if (!atLeastOne)
        qDebug("There is no frequences processed !");
}


string huffmanEncode(const string& toEncode, HuffmanNode*& huffmanTree)
{
    /**
      * Encode a string by using the huffman compression.
      * Fill the given parameter `huffmanTree` with the huffman
      * nodes used to encode the string
     **/

    // this array store each caracter frequences indexed by their ascii code
    Array characterFrequences(256);
    characterFrequences.fill(0);
    // this array store each caracter code indexed by their ascii code
    string characterCodes[256];
    HuffmanHeap priorityMinHeap;

    string encoded = "";



    // Your code
    // fill characters frequences array
    // build a priority heap


    displayCharacterFrequences(characterFrequences);

    // while the heap has more than 1 node
    //  extract the two minimum nodes and build a new subtree with it
    //  store the new parent into the priorityHeap

    if (priorityMinHeap.effectiveSize() > 0)
    {
        huffmanTree = priorityMinHeap[0];
    }
    else
    {
        huffmanTree = new HuffmanNode('?');
    }


    // Travel the huffman tree to process all codes

    // fill the codes array and use it to


    return encoded;
}


string huffmanDecode(const string& toDecode, const HuffmanNode& huffmanTree)
{
    /**
      * Use each caracters of toDecode, which is '0' either '1',
      * to travel the Huffman tree. Each time you get a leaf, get
      * the decoded character of this node.
     **/
    string decoded = "";
    // Your code
    return decoded;
}

void main_function(HuffmanNode*& huffmanTree)
{

    string data = "Ouesh, bien ou bien ? Ceci est une chaine de caracteres sans grand interet";

    string encoded = huffmanEncode(data, huffmanTree);
    string decoded = huffmanDecode(encoded, *huffmanTree);

    qDebug("Encoded: %s\n", encoded.c_str());
    qDebug("Decoded: %s\n", decoded.c_str());
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Array::wait_for_operations = false;
    w = new HuffmanMainWindow(main_function);
    w->show();
    return a.exec();
}
