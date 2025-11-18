#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux) {
    if (n == nullptr) return -1;
    
    int hl = 1 + my_recur(n->left, aux);
    int hr = 1 + my_recur(n->right, aux);
    aux = std::max(aux, hl + hr);

    return std::max(hl, hr);
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    int max = -1;
    my_recur(mRoot, max);
    return max;
}

#endif
