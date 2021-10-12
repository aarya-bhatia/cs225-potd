#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <sstream>

using namespace std;

void decrypt(HuffmanNode *root, string path, vector<char> &charVec, vector<string> &strVec)
{
    if (!root)
    {
        return;
    }

    if (!root->left_ && !root->right_)
    {
        charVec.push_back(root->char_);
        strVec.push_back(path);
        return;
    }

    decrypt(root->left_, path + '0', charVec, strVec);
    decrypt(root->right_, path + '1', charVec, strVec);
}

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    HuffmanNode *current = huffmanTree;
    string res = "";

    for (unsigned i = 0; i < binaryString.length(); i++)
    {
        char c = binaryString[i];

        if(!current->right_ && !current->left_) {
            res += current->char_;
            current = huffmanTree;
        }
        if(c == '0')
        {
            current = current->left_;
        }
        else {
            current = current->right_;
        }
    }

    return res;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    vector<char> charVec;
    vector<string> strVec;
    decrypt(huffmanTree, "", charVec, strVec);

    stringstream ss;

    for(unsigned i = 0; i < charString.length(); i++)
    {
        char c = charString[i];
        for(unsigned j = 0; j < charVec.size(); j++)
        {
            if(charVec[j] == c)
            {
                string path = strVec[j];
                ss << path;
                break;
            }
        }
    }

    return ss.str();
}
