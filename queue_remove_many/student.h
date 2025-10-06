#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <set>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  CP::queue<T> q;
  std::set<size_t> s;
  for (size_t x : pos) s.insert(x);

  for (size_t i = 0; i < mSize; i++) {
    if (!s.count(i)) q.push(mData[(mFront + i) % mCap]);
  }
  
  *this = q;
}

#endif
