#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  if (mSize <= 1) return true;
  for (int i = 1; i < mSize; i++) {
    int idx = (i - 1) / 2;
    if (mLess(mData[idx], mData[i])) return false;
  }
  return true;
}

#endif