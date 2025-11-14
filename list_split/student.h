#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  CP::list<T> result;

  if (pos >= mSize) return result;

  result.mSize = mSize - pos;
  mSize = pos;

  node *ptr = it.ptr;
  node *last = mHeader->prev;

  ptr->prev->next = mHeader;
  mHeader->prev = ptr->prev;

  result.mHeader->next = ptr;
  ptr->prev = result.mHeader;

  result.mHeader->prev = last;
  last->next = result.mHeader;

  return result;
}

#endif
