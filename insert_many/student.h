#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>
#include <vector>
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
  vector<T> v;
  std::map<int, T> m(data.begin(), data.end());
  for (size_t i = 0; i < mSize; i++) {
    if (m.find(i) != m.end()) {
      v.push_back(m[i]);
    }
    v.push_back(mData[i]);
  }
  
  for (auto x : data) {
    if (x.first >= mSize) v.push_back(x.second);
  }
  
  *this = v;
}

#endif
