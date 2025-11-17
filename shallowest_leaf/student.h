#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if (n == nullptr) return -1;
  if (n->left == nullptr && n->right == nullptr) return 0;

  int l = shallowest_leaf(n->left);
  int r = shallowest_leaf(n->right);

  if (n->left == nullptr) return r + 1;
  if (n->right == nullptr) return l + 1;

  return std::min(l, r) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  return shallowest_leaf(mRoot);
}


#endif
