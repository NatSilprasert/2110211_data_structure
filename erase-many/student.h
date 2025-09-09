#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_set>
#include <vector>
using namespace std;

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  unordered_set<int> del(pos.begin(), pos.end());
  vector<T> newV;
  newV.reserve(mSize - del.size());

  for (int i = 0; i < mSize; i++) {
    if (del.count(i) == 0) newV.push_back(mData[i]);  
  }

  mData.swap(newV);
  mSize = newV.size();
}

#endif