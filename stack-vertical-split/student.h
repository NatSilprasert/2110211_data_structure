#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  std::vector<std::stack<T>> ans;
  int remain = mSize % k;
  int n = remain == 0 ? mSize / k : mSize / k + 1;
  int idx = 0;
  for (int i = 0; i < k; i++) {
    if (remain != 0 && i == remain) n--;

    std::stack<T> s1;
    for (int j = 0; j < n; j++) {

      s1.push(mData[mSize - 1 - idx]);
      idx++;
    }

    std::stack<T> s2;
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    ans.push_back(s2);
  }
  
  output = ans;
}

#endif
