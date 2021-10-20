#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
  if(!root) {
    return nullptr;
  }

  unsigned i;

  std::vector<int> &keys = root->elements_;

  for(i = 0; i < keys.size() && key > keys[i]; i++);

  if(i < keys.size() && keys[i] == key) return root;

  if(root->is_leaf_) return NULL;

  return find(root->children_[i], key);

}
