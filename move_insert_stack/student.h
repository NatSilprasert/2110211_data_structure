#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  CP::stack<T> tmp;
  for (int i = 0; i < mSize - k; i++) {
    tmp.push(mData[i]);
  }

  int n = s2.size();
  for (int i = std::max(n - m, 0); i < n; i++) {
    tmp.push(s2.mData[i]);
    s2.pop();
  }
  for (int i = mSize - k; i < mSize; i++) {
    tmp.push(mData[i]);
  }

  *this = tmp;
}
#endif
