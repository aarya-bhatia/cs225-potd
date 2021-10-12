#include <iostream>
#include "potd.h"

using namespace std;

void printList(Node *head) {
  if (head == NULL) {
    cout << "Empty list" << endl << endl;
    return;
  }

  Node *temp = head;
  int count = 0;
  while(temp != NULL) {
    cout << "Node " << count++ << ": " << temp ->data_ << endl;
    temp = temp->next_;
  }
  cout << endl;
}

int main() {
  // Empty List:
  Node *head = NULL;
  printList(head);

  // Add 3 to list:
  Node three;
  three.data_ = 3;
  three.next_ = NULL;
  insertSorted(&head, &three);
  printList(head);

  // Add 9 to list:
  Node nine;
  nine.data_ = 9;
  nine.next_ = NULL;
  insertSorted(&head, &nine);
  printList(head);

  // Add 1 to list:
  Node one;
  one.data_ = 1;
  one.next_ = NULL;
  insertSorted(&head, &one);
  printList(head);

  // Add 5 to list:
  Node five;
  five.data_ = 5;
  five.next_ = NULL;
  insertSorted(&head, &five);
  printList(head);

  return 0;
}
