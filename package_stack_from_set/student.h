#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first, typename std::set<T>::iterator last) {
  mSize = 0;
  mCap = 1;
  mData = new T[mCap]();

  if (first == last) return;

  while (true) {
    last--;
    push(*last);
    if (last == first) break;
  }
}

#endif
