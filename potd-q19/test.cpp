#include "acutest.hpp"
#include "Node.h"
#include <iostream>

void testToString() {
    Node n;
    Node n1;
    Node n2;

    n.data_ = 0;
    n1.data_ = 1;
    n2.data_ = 2;

    n.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = 0;

    std::string result = toString(&n);
    std::cout << result << std::endl;

    TEST_CHECK_(result == "< 0 1 2 >", "inserting elements into list and output as string");
}

void testInsertSorted() {
    Node *head = nullptr;
    insertSorted(head, 5);
    insertSorted(head, 6);
    insertSorted(head, 4);
    insertSorted(head, 2);
    std::string result = toString(head);
    TEST_ASSERT(toString(head) == "< 2 4 5 6 >");
    destroy(head);
    TEST_ASSERT(head == 0);
}

TEST_LIST = {
    {"begin tests", testToString},
    {"insert sorted", testInsertSorted},
    {0}
};