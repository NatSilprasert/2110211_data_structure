#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value)
{
  // Your code here
  int bucket = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  int pos = index;
  if (bucket > 0)
  {
    pos = pos - aux[bucket - 1];
  }
  if (pos == 0)
  {
    mData.insert(mData.begin() + bucket, value);
    if (bucket > 0)
    {
      aux.insert(aux.begin() + bucket, aux[bucket - 1] + value.size());
    }
    else
    {
      aux.insert(aux.begin() + bucket, value.size());
    }
    for (size_t i = bucket + 1; i < aux.size(); ++i)
    {
      aux[i] += value.size();
    }
  }
  else
  {
    int old_size = mData[bucket].size();
    mData.insert(mData.begin() + bucket + 1, std::vector<T>(value.size()));
    int space = old_size - pos;
    if (space < value.size())
    {
      for (int i = value.size() - 1, j = old_size - 1; j >= pos; --i, --j)
      {
        mData[bucket + 1][i] = mData[bucket][j];
      }
      int value_idx = 0;
      for (int i = pos; i < old_size; ++i, ++value_idx)
      {
        mData[bucket][i] = value[value_idx];
      }
      for (int i = 0; value_idx < value.size(); ++i, ++value_idx)
      {
        mData[bucket + 1][i] = value[value_idx];
      }
    }
    else
    {
      int j = old_size - 1;
      for (int i = value.size() - 1; i >= 0; --i, --j)
      {
        mData[bucket + 1][i] = mData[bucket][j];
      }
      for (int i = old_size - 1; j >= pos; --i, --j)
      {
        mData[bucket][i] = mData[bucket][j];
      }
      for (int i = 0; i < value.size(); ++i)
      {
        mData[bucket][pos + i] = value[i];
      }
    }
    aux.insert(aux.begin() + bucket + 1, aux[bucket] + value.size());
    for (int i = bucket + 2; i < aux.size(); ++i)
    {
      aux[i] += value.size();
    }
  }
  mCap = aux.back();
  mSize = aux.back();
}

#endif