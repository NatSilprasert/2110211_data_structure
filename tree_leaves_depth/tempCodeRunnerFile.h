#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
  if (n == nullptr) return aux - 1;
  if (n->left == nullptr && n->right == nullptr) return aux;
  size_t newAux = aux + 1;
  return my_recur(n->right, newAux) + my_recur(n->left, newAux);
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  return my_recur(mRoot, 0);
}

#endif
