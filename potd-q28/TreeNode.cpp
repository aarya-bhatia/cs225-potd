#include "TreeNode.h"
#include <iostream>

TreeNode *deleteNode(TreeNode *root, int k)
{
  // Base case
  if (!root)
    return root;

  // Recursive calls for ancestors of
  // node to be deleted
  if (root->val_ > k)
  {
    root->left_ = deleteNode(root->left_, k);
    return root;
  }
  else if (root->val_ < k)
  {
    root->right_ = deleteNode(root->right_, k);
    return root;
  }

  // We reach here when root is the node
  // to be deleted.

  // If one of the children is empty
  if (root->left_ == NULL)
  {
    TreeNode *temp = root->right_;
    delete root;
    return temp;
  }
  else if (root->right_ == NULL)
  {
    TreeNode *temp = root->left_;
    delete root;
    return temp;
  }

  // If both children exist
  else
  {

    TreeNode *succParent = root;

    // Find successor
    TreeNode *succ = root->right_;
    while (succ->left_ != NULL)
    {
      succParent = succ;
      succ = succ->left_;
    }

    // Delete successor.  Since successor
    // is always left_ child of its parent
    // we can safely make successor's right_
    // right_ child as left_ of its parent.
    // If there is no succ, then assign
    // succ->right_ to succParent->right_
    if (succParent != root)
      succParent->left_ = succ->right_;
    else
      succParent->right_ = succ->right_;

    // Copy Successor Data to root
    root->val_ = succ->val_;

    // Delete Successor and return root
    delete succ;
    return root;
  }
}

void inorderPrint(TreeNode *node)
{
  if (!node)
    return;
  inorderPrint(node->left_);
  std::cout << node->val_ << " ";
  inorderPrint(node->right_);
}

void deleteTree(TreeNode *root)
{
  if (root == NULL)
    return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
