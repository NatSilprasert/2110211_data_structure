#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template <typename T>
size_t CP::list<T>::fix_wrong()
{
  size_t count = 0;
  node *n = mHeader;
  for (size_t i = 0; i <= mSize; ++i) {
    if (n->next->prev != n) {
      n->next->prev = n;
      count++;
    }
    n = n->next;
  }

  return count;
}

#endif