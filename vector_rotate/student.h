#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  int firstIdx = first - begin();
  std::vector<T> v(first, last);
  for (int i = 0; i < v.size(); i++) {
    mData[firstIdx + i] = v[(i + k) % v.size()];
  } 
}

#endif
