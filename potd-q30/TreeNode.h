#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
    }
};

int getHeightBalance(TreeNode* root);

void deleteTree(TreeNode* root);

int getHeight(TreeNode *root);

#endif
