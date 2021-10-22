#include <vector>
#include <queue>
#include "BTreeNode.h"

void traverse(BTreeNode *current, std::vector<int> &v)
{

    if (!current)
    {
        return;
    }

    if (current->is_leaf_)
    {
        for (unsigned i = 0; i < current->elements_.size(); i++)
        {
            v.push_back(current->elements_[i]);
        }
    }
    else
    {
        for (unsigned i = 0; i < current->children_.size(); i++)
        {
            traverse(current->children_[i], v);
            if (i < current->elements_.size())
            {
                v.push_back(current->elements_[i]);
            }
        }
    }
}

std::vector<int> traverse(BTreeNode *root)
{
    std::vector<int> v;

    if (!root)
    {
        return v;
    }

    traverse(root, v);
    return v;
}
