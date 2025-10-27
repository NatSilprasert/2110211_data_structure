#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::operator==(const CP::priority_queue<T, Comp> &other) const
{
  // write your code here
  if (mSize != other.mSize) return false;

  auto temp1 = *this;
  auto temp2 = other;

  while (!temp1.empty()) {
    if (temp1.top() != temp2.top()) return false;
    temp1.pop();
    temp2.pop();
  }
  return true;
}

#endif