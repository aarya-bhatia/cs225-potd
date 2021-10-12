#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

using namespace std;

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(Node &other);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
    private:
        static int numNodes;
};

Node *listSymmetricDifference(Node *first, Node *second);

#endif