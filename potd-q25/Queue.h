#pragma once

#include <cstddef>

class DoublyIntNode
{
public:
  int data;
  DoublyIntNode *next;
  DoublyIntNode *prev;

  DoublyIntNode(int d)
  {
    data = d;
    next = 0;
    prev = 0;
  }
};

class DoublyIntList
{
public:
  DoublyIntList()
  {
    _size = 0;
    _head = 0;
    _tail = 0;
  }

  ~DoublyIntList()
  {
    destroy_();
  }

  DoublyIntList(const DoublyIntList &other)
  {
    copy_(other);
  }

  DoublyIntList &operator=(const DoublyIntList &other)
  {
    if (this != &other)
    {
      destroy_();
      copy_(other);
    }

    return *this;
  }

  void insertFront(int data)
  {
    DoublyIntNode *insert = new DoublyIntNode(data);

    if (empty())
    {
      _head = insert;
      _tail = insert;
    }
    else
    {
      insert->next = _head;
      _head->prev = insert;
      _head = insert;
    }

    _size++;
  }

  bool empty() const { return _size == 0 && _head == 0 && _tail == 0; }

  void insertBack(int data)
  {
    DoublyIntNode *insert = new DoublyIntNode(data);

    if (empty())
    {
      _head = insert;
      _tail = insert;
    }
    else
    {
      insert->prev = _tail;
      _tail->next = insert;
      _tail = insert;
    }

    _size++;
  }

  void removeFront()
  {

    if (empty())
    {
      return;
    }

    if (_size == 1)
    {
      delete _head;
      _head = 0;
      _tail = 0;
    }
    else
    {
      DoublyIntNode *tmp = _head->next;
      delete _head;
      _head = tmp;
      _head->prev = 0;
    }

    _size--;
  }

  void removeBack()
  {

    if (empty())
    {
      return;
    }

    if (_size == 1)
    {
      delete _head;
      _head = 0;
      _tail = 0;
    }
    else
    {
      DoublyIntNode *tmp = _tail->prev;
      delete _tail;
      _tail = tmp;
      _tail->next = 0;
    }

    _size--;
  }

  bool contains(int data) const
  {
    for (Iterator it = begin(); it != end(); it++)
    {
      if (*it == data)
      {
        return true;
      }
    }

    return false;
  }

  DoublyIntNode **operator[](unsigned index)
  {
    if (index <= 0)
    {
      return &_head;
    }

    DoublyIntNode *current = _head;

    for (unsigned i = 0; i < index - 1 && current; i++)
    {
      current = current->next;
    }

    return &(current->next);
  }

  void reverse(DoublyIntNode **start, DoublyIntNode **end)
  {

    if (!start || !end)
    {
      return;
    }

    DoublyIntNode *itr = *start;

    while (itr && itr != (*end)->next)
    {
      DoublyIntNode *tmp = itr->next;
      itr->next = itr->prev;
      itr->prev = tmp;
      itr = tmp;
    }

    (*start)->next = (*end)->next;
    (*end)->prev = (*start)->prev;

    if (_head == *start)
    {
      _head = *end;
    }
    else
    {
      (*start)->prev->next = *end;
    }

    if (_tail == *end)
    {
      _tail = *start;
    }
    else
    {
      (*end)->next->prev = *start;
    }
  }

  DoublyIntNode *getHead() const { return _head; }
  DoublyIntNode *getTail() const { return _tail; }

  unsigned size() const { return _size; }

  class Iterator
  {
  public:
    Iterator()
    {
      current = 0;
    }

    Iterator(DoublyIntNode *position)
    {
      current = position;
    }

    Iterator &operator++()
    {
      current = current->next;
      return *this;
    }

    Iterator operator++(int)
    {
      DoublyIntNode *tmp = current;
      current = current->next;
      return Iterator(tmp);
    }

    Iterator &operator--()
    {
      current = current->prev;
      return *this;
    }

    Iterator operator--(int)
    {
      DoublyIntNode *tmp = current;
      current = current->prev;
      return Iterator(tmp);
    }

    int operator*()
    {
      return current->data;
    }

    const DoublyIntNode *getPosition()
    {
      return current;
    }

    bool operator!=(const Iterator &other)
    {
      return current != other.current;
    }

  private:
    DoublyIntNode *current;
  };

  Iterator begin() const
  {
    return Iterator(_head);
  }

  Iterator end() const
  {
    return Iterator(0);
  }

private:
  DoublyIntNode *_head;
  DoublyIntNode *_tail;
  unsigned _size;

  void destroy_()
  {
    DoublyIntNode *curr = _head;

    while (curr != 0)
    {
      DoublyIntNode *tmp = curr->next;
      delete curr;
      curr = tmp;
    }

    _size = 0;
  }

  void copy_(const DoublyIntList &other)
  {
    _size = 0;
    _head = 0;
    _tail = 0;

    for (Iterator it = other.begin(); it != other.end(); it++)
    {
      insertBack(*it);
    }
  }
};

class Queue {
    public:
        Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
    private:
        DoublyIntList list_;
};