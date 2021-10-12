#include "Queue.h"

Queue::Queue()
{
  list_ = DoublyIntList();
}

int Queue::size() const {
  return list_.size();
}

bool Queue::isEmpty() const {
  return list_.empty();
}

void Queue::enqueue(int value) {
  list_.insertFront(value);
}

int Queue::dequeue() {
  if(list_.empty()){
    return -1;
  }
  int value = list_.getTail()->data;
  list_.removeBack();
  return value;
}