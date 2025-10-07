#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  std::vector<std::vector<T>> ans(k);
  for (int i = 0; i < mSize; i++) {
    ans[i % k].push_back(mData[mSize - 1 - i]);
  }

  for (std::vector<T> &v : ans) {
    std::reverse(v.begin(), v.end());
  }

  return ans;
}

#endif

