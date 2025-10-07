#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  std::vector<int> idx;
  std::vector<T> sortValues;

  for (auto &it : pos) {
    idx.push_back(it - begin());
    sortValues.push_back(*it);
  }

  std::sort(idx.begin(), idx.end());
  std::sort(sortValues.begin(), sortValues.end(), comp);

  for (int i = 0; i < idx.size(); i++) {
    mData[idx[i]] = sortValues[i];
  }
}

#endif
