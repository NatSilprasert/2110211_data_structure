#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last)
{
  std::vector<T> tmp;
  int pos = position - mData;

  for (int i = 0; i < pos; i++)
  {
    tmp.push_back(mData[i]);
  }

  for (auto it = first; it != last; ++it)
  {
    tmp.push_back(*it);
  }

  for (int i = pos; i < mSize; i++)
  {
    tmp.push_back(mData[i]);
  }

  delete[] mData;
  mData = new T[tmp.size()];
  for (size_t i = 0; i < tmp.size(); i++)
  {
    mData[i] = tmp[i];
  }
  mSize = tmp.size();
  mCap = tmp.size();
}

#endif