#ifndef POTD_H
#define POTD_H

#include <string>

using namespace std;

struct Node {
    int data_;
    Node *next_;

    Node(int data): data_(data), next_(nullptr) {}
};

string stringList(Node *n);

#endif
