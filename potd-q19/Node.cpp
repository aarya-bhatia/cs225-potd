#include "Node.h"

#include <unordered_set>
#include <string>
#include <sstream>
#include <iostream>

std::string toString(Node *head)
{
    std::ostringstream ss;
    ss << "< ";
    while (head != nullptr)
    {
        ss << head->data_ << " ";
        head = head->next_;
    }
    ss << ">";
    return ss.str();
}

void sortedInsert(Node **head_ref,
                  Node *new_node)
{
    Node *current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data_ >= new_node->data_)
    {
        new_node->next_ = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->next_ != NULL && current->next_->data_ < new_node->data_)
        {
            current = current->next_;
        }
        new_node->next_ = current->next_;
        current->next_ = new_node;
    }
}

void printSet(std::unordered_set<int> &items) {
    std::unordered_set<int>::iterator itr;
    std::cout << "< ";
    for (itr = items.begin(); itr != items.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << ">" << std::endl;
}

Node *listUnion(Node *first, Node *second)
{
    Node *out = nullptr;
    std::unordered_set<int> items;

    while (first != nullptr)
    {
        if (items.find(first->data_) == items.end())
        {
            items.insert(first->data_);
        }
        first = first->next_;
        printSet(items);
    }

    while (second != nullptr)
    {
        if (items.find(second->data_) == items.end())
        {
            items.insert(second->data_);
        }
        second = second->next_;
        printSet(items);
    }

    std::unordered_set<int>::iterator itr;
    for (itr = items.begin(); itr != items.end(); itr++)
    {
        Node *newNode = new Node;
        newNode->data_ = *itr;
        sortedInsert(&out, newNode);
    }

    return out;
}

Node::Node()
{
    numNodes++;
}

Node::Node(const Node &other)
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
