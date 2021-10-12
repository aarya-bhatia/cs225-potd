#include "Node.h"

#include <unordered_set>

using namespace std;

Node *listIntersection(Node *first, Node *second)
{
    unordered_set<int> set;
    unordered_set<int> intersection;

    Node *result = 0;

    Node *it = first;

    while (it != 0)
    {
        int data = it->data_;
        if (set.find(data) == set.end())
        {
            set.insert(data);
        }
        it = it->next_;
    }

    it = second;

    while(it != 0)
    {
        int data = it->data_;
        if(set.find(data) != set.end() && intersection.find(data) == intersection.end())
        {
            intersection.insert(data);
        }
        it = it->next_;
    }

    for(unordered_set<int>::iterator itr = intersection.begin(); itr != intersection.end(); itr++)
    {
        Node *newNode = new Node;
        newNode->data_ = *itr;
        newNode->next_ = result;
        result = newNode;
    }

    return result;
}

Node::Node()
{
    numNodes++;
}

Node::Node(Node &other)
{
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node()
{
    numNodes--;
}

int Node::numNodes = 0;
