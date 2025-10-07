#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
  T *mDataClone = new T[mCap]();
  mDataClone = mData; 
  size_t mSizeClone = mSize;
  size_t mCapClone = mCap;

  mData = other.mData;
  mSize = other.mSize;
  mCap = other.mCap;

  other.mData = mDataClone;
  other.mSize = mSizeClone;
  other.mCap = mCapClone;
}

#endif
