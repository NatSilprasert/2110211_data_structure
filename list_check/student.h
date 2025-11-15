#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check() {
  auto current = mHeader;
  for (int i = 0; i < mSize; ++i) {
    auto prev = current;
    current = current->next;
    if (current == nullptr) return false;
    if (current->prev != prev) return false;
  }

  if (current->next != mHeader) return false;
  
  current = mHeader;
  for (int i = 0; i < mSize; ++i) {
    auto next = current;
    current = current->prev;
    if (current == nullptr) return false;
    if (current->next != next) return false;  
  }

  if (current->prev != mHeader) return false; 

  return true;
}


#endif
