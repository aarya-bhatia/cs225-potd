#include "Node.h"

using namespace std;

Node *SortedMerge(Node *a, Node *b);
void FrontBackSplit(Node *source,
                    Node **frontRef, Node **backRef);
void MergeSort(Node **headRef);

void sortList(Node **headRef)
{
  MergeSort(headRef);
}

void MergeSort(Node **headRef)
{
  Node *head = *headRef;
  Node *a;
  Node *b;

  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next_ == NULL))
  {
    return;
  }

  /* Split head into 'a' and 'b' sublists */
  FrontBackSplit(head, &a, &b);

  /* Recursively sort the sublists */
  MergeSort(&a);
  MergeSort(&b);

  /* answer = merge the two sorted lists together */
  *headRef = SortedMerge(a, b);
}

Node *SortedMerge(Node *a, Node *b)
{
  Node *result = NULL;

  /* Base cases */
  if (a == NULL)
    return (b);
  else if (b == NULL)
    return (a);

  /* Pick either a or b, and recur */
  if (a->data_ <= b->data_)
  {
    result = a;
    result->next_ = SortedMerge(a->next_, b);
  }
  else
  {
    result = b;
    result->next_ = SortedMerge(a, b->next_);
  }
  return (result);
}

void FrontBackSplit(Node *source,
                    Node **frontRef, Node **backRef)
{
  Node *fast;
  Node *slow;
  slow = source;
  fast = source->next_;

  /* Advance 'fast' two nodes, and advance 'slow' one node */
  while (fast != NULL)
  {
    fast = fast->next_;
    if (fast != NULL)
    {
      slow = slow->next_;
      fast = fast->next_;
    }
  }

  /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
  *frontRef = source;
  *backRef = slow->next_;
  slow->next_ = NULL;
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
