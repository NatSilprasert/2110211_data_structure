#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T &value)
{
  
  if (pos > mSize) pos = mSize;
  pos = mSize - pos;

  T *arr = new T[mCap + 1]();
  arr[pos] = value;
  for (size_t i = 0, j = 0; j < mSize; i++, j++) {
    if (i == pos) i++;
    arr[i] = mData[j];
  }

  delete[] mData;
  mData = arr;
  mSize += 1;
  mCap += 1;
}

#endif