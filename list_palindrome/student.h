#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"
#include <iostream>

template <typename T>
size_t CP::list<T>::longest_palindrome()
{
  node *val = mHeader->next;
  for (size_t i = 0; i < mSize / 2; i++)
  {
    val = val->next;
  }

  int count = 1;
  int maxCount = 1;
  node *nxt = val;
  node *prv = val;
  if (mSize % 2 == 0)
  {
    for (size_t i = 0; i < mSize / 2; i++)
    {
      if (i != 0)
        nxt = nxt->next;
      prv = prv->prev;
      if (nxt->data == prv->data)
        count += 2;
      else
        break;
      maxCount = std::max(maxCount, count);
    }
    if (maxCount > 1)
      maxCount--;
  }
  else
  {
    for (size_t i = 0; i < mSize / 2; i++)
    {
      nxt = nxt->next;
      prv = prv->prev;
      // std::cout << i << ": " << nxt->data << " " << prv->data << std::endl;
      if (nxt->data == prv->data)
        count += 2;
      else
        break;
      maxCount = std::max(maxCount, count);
    }
  }

  return maxCount;
}

#endif