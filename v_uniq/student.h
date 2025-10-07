#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq() {
  CP::vector<T> tmp;
  std::set<T> s;
  for (int i = 0; i < mSize; i++) {
    if (!s.count(mData[i])) {
      s.insert(mData[i]);
      tmp.push_back(mData[i]);
    }
  }

  *this = tmp;
}

#endif
