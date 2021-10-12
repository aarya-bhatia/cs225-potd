#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
  if(*head == NULL || (*head)->data_ >= insert->data_) {
    insert->next_ = *head;
    *head = insert;
    return;
  }

  Node* itr = *head;

  while(itr->next_ != nullptr && itr->next_->data_ < insert->data_){
    itr=itr->next_;
  }

  insert->next_=itr->next_;
  itr->next_=insert;
}
