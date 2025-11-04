#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <vector>

template <typename T>
void CP::queue<T>::rotate(int k)
{

  if (mSize == 0)
    return;
  if (k > 0)
  {
    for (size_t i = 0; i < k % mSize; i++)
    {
      T x = front();
      pop();
      push(x);
    }
  }
  else
  {
    k = -k;
    k %= mSize;
    while (k--)
    {
      T b = back();
      if (mFront == 0)
        mFront = mCap - 1;
      else
        mFront--;
      mData[mFront] = b;
    }
  }
}

#endif
