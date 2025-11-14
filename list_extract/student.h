#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  auto it = a;
  while (it != b) {
    if (*it == value) {
        iterator tmp(it.ptr->next);
        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;
        delete it.ptr;
        mSize--; 
        it = tmp;

        auto oBegin = output.mHeader->next;
        node *n = new node(value, output.mHeader, oBegin);
        output.mHeader->next = n;
        oBegin->prev = n;
        output.mSize++;
    }
    else {
      it++;
    }
  }
}

#endif
