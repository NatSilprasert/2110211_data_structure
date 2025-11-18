#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  // your code here
  CP::map_bst<KeyT, MappedT, CompareT> result;
  node *now = mRoot;
  node *nowOriginal = NULL;
  mRoot = NULL;
  node *nowSplit = NULL;
  result.mRoot = NULL;

  while (true) {
    if (now == NULL) break;

    if (mLess(now->data.first, val)) {
      if (nowOriginal == NULL) {
        mRoot = now;
        mRoot->parent = NULL;
      }
      else if (mLess(nowOriginal->data.first, now->data.first)) {
        nowOriginal->right = now;
        now->parent = nowOriginal;
      }
      else {
        nowOriginal->left = now;
        now->parent = nowOriginal;
      }
      nowOriginal = now;
      now = now->right;
      nowOriginal->right = NULL;
    }
    else { 
      // in split
      if (nowSplit == NULL) {
        result.mRoot = now;
        result.mRoot->parent = NULL;
      }
      else if (mLess(nowSplit->data.first, now->data.first)) {
        nowSplit->right = now;
        now->parent = nowSplit;
      }
      else {
        nowSplit->left = now;
        now->parent = nowSplit;
      }
      nowSplit = now;
      now = now->left;
      nowSplit->left = NULL;
    }
  }
  
  return result;
}

#endif
