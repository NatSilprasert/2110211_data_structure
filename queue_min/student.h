#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  T tmp;
  std::sort(pos.begin(), pos.end());
  for (int i = 0; i < pos.size(); i++) {
    if (i == 0) {
      tmp = mData[(mFront + pos[i]) % mCap];
    }
    else if (pos[i] < mSize && comp(mData[(mFront + pos[i]) % mCap], tmp)) {
      tmp = mData[(mFront + pos[i]) % mCap];
    }
  }
  return tmp;
}

#endif
