#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  while (K--) {
    pop(); 
    if (size() == 0) break;
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<T> s1, s2;
  while (K--) {
    s1.push(top());
    pop();
    if (size() == 0) break;
  }
  
  while (!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }

  return s2;
}

#endif
