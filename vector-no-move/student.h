#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  int i = upper_bound(aux.begin(), aux.end(), idx) - aux.begin(); // หา index ของ arr ที่อยู่
  if (i > 0) idx -= aux[i - 1]; // ถ้า i ไม่ได้อยู่ใน arr แรก ให้ลบ idx ด้วยจำนวน mCap ที่ผ่านมา

  return mData[i][idx];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  aux.push_back(mCap);
}

#endif
