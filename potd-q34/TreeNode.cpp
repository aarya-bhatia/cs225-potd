#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
  if(rightHeavy(subroot))
  {
    if(rightHeavy(subroot->right_))
    {
      return TreeNode::left;
    }
    else
    {
      return TreeNode::rightLeft;
    }
  }
  else if(leftHeavy(subroot))
  {
    if(leftHeavy(subroot->left_))
    {
      return TreeNode::right;
    }
    else 
    {
      return TreeNode::leftRight;
    }
  }

  return TreeNode::right;
}
