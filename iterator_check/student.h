#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  
  if (mSize == 0 || it == nullptr) return false;

  return (it >= mData && it < mData + mSize);
}

#endif
