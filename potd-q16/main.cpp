#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;
  cout << "-------------" << endl;

  // Test 2: A list with exactly one node
  Node * n1 = new Node(1);
  head = n1;

  cout << stringList(head) << endl;
  cout << "-------------" << endl;

  // Test 3: A list with more than one node
  Node * n2 = new Node(2);
  Node * n3 = new Node(3);

  head->next_ = n2;
  n2->next_ = n3;

  cout << stringList(head) << endl;
  cout << "-------------" << endl;

  return 0;
}
