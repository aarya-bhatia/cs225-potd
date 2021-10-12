#include "Node.h"

using namespace std;

bool contains(Node *head, int data)
{
    while (head != nullptr)
    {
        if (head->data_ == data)
        {
            return true;
        }
        head = head->next_;
    }
    return false;
}

Node *listSymmetricDifference(Node *first, Node *second)
{
    if (first == second)
    {
        return nullptr;
    }

    Node *result = nullptr;
    Node *itr = first;

    while (itr != nullptr)
    {
        Node *tmp = itr->next_;
        if (!contains(second, itr->data_) && !contains(result, itr->data_))
        {
            Node *newNode = new Node;
            newNode->data_ = itr->data_;
            newNode->next_ = result;
            result = newNode;
        }
        itr = tmp;
    }

    itr = second;

    while (itr != nullptr)
    {
        Node *tmp = itr->next_;
        if (!contains(first, itr->data_) && !contains(result, itr->data_))
        {
            Node *newNode = new Node;
            newNode->data_ = itr->data_;
            newNode->next_ = result;
            result = newNode;
        }
        itr = tmp;
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
