#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <set>
#include <algorithm>
#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  std::set<std::pair<int, int>> range;
  for (auto p : ranges) {
    int l = p.first - begin();
    int r = p.second - begin() - 1;
    if (range.empty()) {
      range.insert({r, l});
      continue;
    }
    while (true) {
      auto it = range.lower_bound({l - 1, -100});
      if (it != range.end() && it->second <= r + 1) {
        l = std::min(l, it->second);
        r = std::max(r, it->first);
        range.erase(it);  
      }
      else break;
    }
    range.insert({r, l});
  }
  
  CP::vector<T> tmp;
  for (auto p : range) {
    int l = p.second;
    int r = p.first;
    for (int i = l; i < r + 1; i++) {
      mData[i] = -999999;
    }
  }

  for (int i = 0; i < mSize; i++) {
    if (mData[i] != -999999) tmp.push_back(mData[i]);
  }

  *this = tmp;
}

#endif
