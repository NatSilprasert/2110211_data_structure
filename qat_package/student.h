#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  if (idx >= 0) return mData[(idx + mFront) % mCap];
  else return mData[(mFront + mSize + idx) % mCap];
}

#endif
