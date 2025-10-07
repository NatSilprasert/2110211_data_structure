#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const 
{
  std::vector<std::vector<T>> v(k);
  int n = mSize / k;
  int remain = mSize % k;
  if (remain != 0) n++;
  int idx = 0;
  bool b = true;

  for (size_t i = 0; i < mSize; i++) {
    if (b && idx == remain && remain != 0) {
      b = false;
      n--;
    }
    v[idx].push_back(mData[mSize - 1 - i]);
    if (v[idx].size() == n) idx++;
  }
  return v;
}
#endif
