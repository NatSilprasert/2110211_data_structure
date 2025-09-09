#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_set>
#include <vector>
using namespace std;

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos)
{
  
  unordered_set<int> del(pos.begin(), pos.end());

  size_t newSize = mSize - del.size();
  vector<T> newV;

  for (size_t i = 0; i < mSize; i++)
  {
    if (del.count(i) == 0)
      newV.push_back(mData[i]);
  }

  delete[] mData;
  mData = new T[newV.size()];
  for (size_t i = 0; i < newV.size(); i++)
    mData[i] = newV[i];

  mSize = newV.size();
  mCap = newV.size(); 
}

#endif