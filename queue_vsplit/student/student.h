#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const {
  std::vector<std::queue<T>> ans;
  int remain = mSize % k;
  int n = remain == 0 ? mSize / k : mSize / k + 1;
  int idx = 0;
  for (int i = 0; i < k; i++) {

    int count = n;
    if (remain != 0 && i >= remain) count--;

    std::queue<T> q;
    for (int j = 0; j < count; j++) {
      q.push(mData[(mFront + idx) % mCap]);
      idx++;
    }

    ans.push_back(q);
  }

  output = ans;
}

#endif
