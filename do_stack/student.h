#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__

#include "stack.h"

template <typename T>
void CP::stack<T>::push(const T &value)
{
  // You can write your code below here
  ensureCapacity(mSize + 1);
  mData[mSize++] = value;
  aux_stack_1.push({1, value});
  aux_stack_2 = std::stack<std::pair<int, T>>();
  return;
}

template <typename T>
void CP::stack<T>::pop()
{
  // Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range");
  mSize--;
  aux_stack_1.push({2, mData[mSize]});
  aux_stack_2 = std::stack<std::pair<int, T>>();
  return;
}

template <typename T>
void CP::stack<T>::undo()
{
  if (!aux_stack_1.empty()) {
    auto [op, value] = aux_stack_1.top();
    aux_stack_1.pop();

    if (op == 1) {
      mSize--;
      aux_stack_2.push({1, value});
    }
    else if (op == 2) {
      ensureCapacity(mSize + 1);
      mData[mSize++] = value;
      aux_stack_2.push({2, value});
    }
  }
  return;
};

template <typename T>
void CP::stack<T>::redo()
{
  // You can write your code below here
  if (!aux_stack_2.empty()) {
    auto [op, value] = aux_stack_2.top();
    aux_stack_2.pop();
    if (op == 1) {
      ensureCapacity(mSize + 1);
      mData[mSize++] = value;
      aux_stack_1.push({1, value});
    }
    else if (op == 2) {
      mSize--;
      aux_stack_1.push({2, value});
    }
  }
  return;
}
#endif