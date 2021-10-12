#include "potd.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string stringList(Node *head) {
    if(head == nullptr) {
        return "Empty list";
    }

    Node *current = head;

    std::ostringstream out;

    int count = 0;

    while(current != nullptr) {
        out << "Node " << count << ": " << current->data_;
        
        if(current->next_ != nullptr) {
            out << " -> ";
        }

        count++;
        current = current->next_;
    }

    return out.str();

}
