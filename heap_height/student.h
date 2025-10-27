#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  if (mSize == 0) return -1;
  int n = 1;
  int count = 0;
  while (n < mSize) {
    n += std::pow(2, count + 1);
    count++;
  }
  return count;
}

#endif

