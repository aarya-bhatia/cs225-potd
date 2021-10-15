#include <cstdlib>
#include <cmath>
#include <unordered_map>
#include <stack>

#include "TreeNode.h"

static std::unordered_map<TreeNode *, int> nodeHeights;

static int height(TreeNode *node)
{
  return node ? 1 + std::fmax(height(node->left_), height(node->right_)) : -1;
}

bool isHeightBalanced(TreeNode *root)
{
  if (!root)
  {
    return true;
  }

  if (nodeHeights.find(root->right_) == nodeHeights.end())
  {
    nodeHeights[root->right_] = height(root->right_);
  }
  if (nodeHeights.find(root->left_) == nodeHeights.end())
  {
    nodeHeights[root->left_] = height(root->left_);
  }

  return std::abs(nodeHeights[root->right_] - nodeHeights[root->left_]) < 2;
}

TreeNode *findLastUnbalanced(TreeNode *root)
{
  if (root == NULL)
    return NULL;

  TreeNode *left = findLastUnbalanced(root->left_);
  TreeNode *right = findLastUnbalanced(root->right_);

  if (left != NULL || right != NULL)
  {
    return height(root->left_) > height(root->right_) ? left : right;
  }

  return isHeightBalanced(root) ? NULL : root;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

