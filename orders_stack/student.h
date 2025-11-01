#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"
#include <iostream>
#include <stack>
#include <vector>

template <typename T>
void CP::stack<T>::push(const T &value)
{
  if (mSize == 0)
  {
    mData[0] = value;
    mSize++;
    return;
  }

  T *arr = new T[mSize + 1]();

  size_t idx = 0;
  size_t pos = mSize;
  bool c = true;
  for (size_t i = 0; i < mSize; i++)
  {
    if (c && mData[i] < value)
    {
      pos = idx;
      c = false;
      idx++;
    }
    arr[idx] = mData[i];
    idx++;
  }

  arr[pos] = value;

  delete[] mData;
  mData = arr;
  mSize += 1;
  if (mSize > mCap)
  {
    mCap = (mSize > 2 * mCap) ? mSize : 2 * mCap;
  }

  return;
}

template <typename T>
void CP::stack<T>::pop()
{
  // Do not modify this line
  if (size() == 0)
    throw std::out_of_range("index of out range");
  mSize--;

  return;
}

#endif
