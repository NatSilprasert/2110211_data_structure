#include "priority_queue.h"
#include <utility>

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k)
{
  size_t i = k * 2 + 1;
  size_t j = k * 2 + 2;
  size_t x = 1;
  while (i < mSize && j < mSize) {
    for (size_t c = 0; c < x; c++) {
      if (i + c >= mSize || j + c >= mSize) break;
      std::swap(mData[i + c], mData[j + c]);
    }
    i = i * 2 + 1;
    j = j * 2 + 1;
    x *= 2;
  }
  return;
}