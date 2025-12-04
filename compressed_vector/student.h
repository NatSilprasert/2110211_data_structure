#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T>
void CP::CompressedVector<T>::expand(size_t capacity)
{
  // write your code here
  T *arr1 = new T[capacity]();
  size_t *arr2 = new size_t[capacity]();

  for (int i = 0; i < mSize; i++)
  {
    arr1[i] = mDataV[i];
    arr2[i] = mDataL[i];
  }

  delete[] mDataV;
  delete[] mDataL;

  mDataV = arr1;
  mDataL = arr2;
  mCap = capacity;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element)
{
  // write your code here
  if (index == 0)
  {
    if (mSize != 0 && element == mDataV[0])
    {
      mDataL[0]++;
    }
    else
    {
      ensureCapacity(mSize + 1);
      for (int i = mSize; i > 0; i--)
      {
        mDataV[i] = mDataV[i - 1];
        mDataL[i] = mDataL[i - 1];
      }
      mDataV[0] = element;
      mDataL[0] = 1;
      mSize++;
    }
    return;
  }

  size_t x = 0;
  for (int i = 0; i < mSize; i++)
  {
    x += mDataL[i];
    if (x == index)
    {
      if (mDataV[i] == element)
      {
        mDataL[i]++;
      }
      else if (i + 1 < mSize && mDataV[i + 1] == element)
      {
        mDataL[i + 1]++;
      }
      else
      {
        ensureCapacity(mSize + 1);
        for (int j = mSize; j > i + 1; j--)
        {
          mDataV[j] = mDataV[j - 1];
          mDataL[j] = mDataL[j - 1];
        }
        mDataV[i + 1] = element;
        mDataL[i + 1] = 1;
        mSize++;
      }
      break;
    }
  }
}

template <typename T>
T &CP::CompressedVector<T>::operator[](int index) const
{
  // write your code here
  size_t x = 0;
  for (int i = 0; i < mSize; i++)
  {
    size_t sz = mDataL[i];
    x += sz;
    if (index < x)
      return mDataV[i];
  }
  return mDataV[mSize - 1];
}

#endif
