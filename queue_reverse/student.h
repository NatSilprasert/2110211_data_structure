#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <cmath>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  while (b > a) {
    T t = mData[(mFront + a) % mCap];
    mData[(mFront + a) % mCap] = mData[(mFront + b) % mCap];
    mData[(mFront + b) % mCap] = t;
    a++; b--;
  }
}

#endif
