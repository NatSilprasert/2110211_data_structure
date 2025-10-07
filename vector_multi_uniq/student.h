#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <unordered_set>
#include <vector>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  std::unordered_set<int> seen;
  std::vector<CP::vector<T>::iterator> del;

  std::sort(itrs.begin(), itrs.end());

  for (int i = 0; i < itrs.size(); i++) {
    if (!seen.count(*itrs[i])) {
      seen.insert(*itrs[i]);
    }
    else {
      del.push_back(itrs[i]);
    }
  }

  for (int i = del.size() - 1; i >= 0; i--) {
    erase(del[i]);
  }

}

#endif
