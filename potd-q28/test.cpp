#include "TreeNode.h"

int main() {
    TreeNode *root = new TreeNode(4); 
    TreeNode *n1 = new TreeNode(1);

    root->right_ = nullptr;
    root->left_ = n1;

    n1->left_ = nullptr;
    n1->right_ = nullptr;

    inorderPrint(root);

    deleteNode(root, 4);

    // inorderPrint(root);

    deleteTree(root);

    return 0;
}