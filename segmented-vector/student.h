#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "segmented_vector.h"
template <typename T>
CP::SegmentedVector<T>::~SegmentedVector()
{
    for (size_t i = 0; i < mCap; ++i) {
        delete[] mData[i];
    }
    delete[] mData;
}

template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity)
{
    T **arr = new T *[capacity]();
    for (int i = 0; i < capacity; i++) {
        arr[i] = new T[blockSize]();
    }

    for (int i = 0; i < mSize; i++) {
        arr[i / blockSize][i % blockSize] = mData[i / blockSize][i % blockSize];
    }
    for (int i = 0; i < mCap; i++) {
        delete[] mData[i];
    }
    delete[] mData;

    mData = arr;
    mCap = capacity;
}

template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T &element)
{
    ensureCapacity((mSize + 1 + blockSize - 1) / blockSize);

    for (int i = mSize - 1; i >= index; i--) {
        std::swap(mData[i / blockSize][i % blockSize], mData[(i + 1) / blockSize][(i + 1) % blockSize]);
    }
 
    mData[index / blockSize][index % blockSize] = element;

    mSize++;
}

template <typename T>
T &CP::SegmentedVector<T>::operator[](int index) const
{
    // TODO: Write your code here
    int n = index / blockSize;
    int remain = index % blockSize;
    return mData[n][remain];
}
#endif