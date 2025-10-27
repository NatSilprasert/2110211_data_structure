#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <cmath>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  std::vector<T> r;
  for (int i = std::pow(2, k) - 1; i < std::pow(2, k + 1) - 1; i++) {
    if (i >= mSize) break;
    r.push_back(mData[i]);
  }
  std::sort(r.rbegin(), r.rend(), mLess);

  return r;
}

#endif

