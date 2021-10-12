#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {

  int leftHeight = -1;
  int rightHeight = -1;

  if(left_)
  {
    leftHeight = left_->getHeight();
  }
  if (right_)
  {
    rightHeight = right_->getHeight();
  }
  
  return 1 + std::max(leftHeight, rightHeight);
}