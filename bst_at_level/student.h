#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, size_t level, size_t tmp, std::vector<KeyT> &v) {
  if (n == nullptr) return;
  if (tmp == level) {
    v.push_back(n->data.first);
    return;
  }
  tmp++;
  my_recur(n->right, level, tmp, v);
  my_recur(n->left, level, tmp, v);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT, MappedT, CompareT>::at_level(size_t level) {
  std::vector<KeyT> ans;
  my_recur(mRoot, level, 0, ans);
  return ans;
}

#endif
