#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    int diff = (mCap - mSize) - (other.mCap - other.mSize);
    if (diff == 0) return 0;
    else if (diff < 0) return -1;
    else if (diff > 0) return 1;
    return 100;
}

#endif
