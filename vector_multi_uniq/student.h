#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>
#include <vector>
#include <algorithm>
#include "vector.h"

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs)
{
  std::set<T> seen;
  std::set<T *> duplicates;

  for (auto it : itrs) {
    if (seen.count(*it)) {
      duplicates.insert(&(*it));
    }
    else {
      seen.insert(*it);
    }
  }

  CP::vector<T> tmp;
  for (size_t i = 0; i < mSize; i++) {
    if (!duplicates.count(&mData[i])) tmp.push_back(mData[i]);
  }

  *this = tmp;
}

#endif