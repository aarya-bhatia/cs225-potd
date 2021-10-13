#include "TreeNode.h"
#include <cstdlib>
#include <cmath>

int getHeight(TreeNode *root) {
  if(!root) return -1;
  return 1 + std::fmax(getHeight(root->left_), getHeight(root->right_));
}

int getHeightBalance(TreeNode* root) {
  if(!root) {
    return 0;
  }
  return std::abs(getHeight(root->left_) - getHeight(root->right_));
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

