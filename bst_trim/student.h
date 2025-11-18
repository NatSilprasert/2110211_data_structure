#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int level, int tmp)
{
    if (n == nullptr)
        return;
    my_recur(n->left, level, tmp + 1);
    my_recur(n->right, level, tmp + 1);
    if (tmp > level)
    {
        if (n == mRoot)
            mRoot = nullptr;
        delete n;
        --mSize;
    }
    if (tmp == level)
    {
        n->left = nullptr;
        n->right = nullptr;
        return;
    }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::trim(int depth)
{
    my_recur(mRoot, depth, 0);
}

#endif
