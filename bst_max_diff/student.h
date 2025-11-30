#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
MappedT CP::map_bst<KeyT, MappedT, CompareT>::helper(node *n)
{
  if (nullptr)
    return -1;
  if (n->left == nullptr && n->right == nullptr)
    return -1;
  if (n->left == nullptr)
    return helper(n->right);
  if (n->right == nullptr)
    return helper(n->left);

  MappedT lm = n->left->data.second;
  MappedT rm = n->right->data.second;

  return std::max(std::max(std::abs(lm - rm), helper(n->left)), helper(n->right));
}

template <typename KeyT, typename MappedT, typename CompareT>
MappedT CP::map_bst<KeyT, MappedT, CompareT>::max_value_diff()
{
  return helper(mRoot);
}

#endif
