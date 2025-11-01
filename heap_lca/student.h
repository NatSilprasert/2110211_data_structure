#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"
#include <iostream>

template <typename T, typename Comp>
size_t CP::priority_queue<T, Comp>::lca(size_t p, size_t q) const
{
  size_t higher = p > q ? p : q;
  size_t lower = p < q ? p : q;
  if (higher == lower) return higher;

  while (higher > 0) {
    if (higher % 2 == 0) higher = (higher - 2) / 2;
    else higher = (higher - 1) / 2;
  
    if (higher <= lower) {
      if (higher == lower) return higher;

      while (lower > 0) {
        if (lower % 2 == 0) lower = (lower - 2) / 2;
        else  lower = (lower - 1) / 2;

        if (higher == lower) return higher;
      }
    }

    lower = p < q ? p : q;
  }

  return 0;
}

#endif
