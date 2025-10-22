#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {  
    // Example q = [1, 2, 3, 4, 5]
    size_t block_size = to - from + 1;
    size_t front_count = from;     
    size_t back_count = mSize - (to + 1);

    // block_remove(1, 2) => q = [1, 4, 5]
    if (front_count <= back_count) {
        // หน้ามากกว่าหลัง
        for (int i = from - 1; i >= 0; i--)
        {
            // เลื่อนข้างหน้าไปต่อข้างหลังแล้ว move mFront Ex. [1, 2, 1, 4, 5]
            size_t old_pos = (mFront + i) % mCap;
            size_t new_pos = (mFront + i + block_size) % mCap;
            mData[new_pos] = mData[old_pos];
        }

        mFront = (mFront + block_size) % mCap;
    }
    else {
        // หลังมากกว่าหน้า
        for (size_t i = to + 1; i < mSize; i++)
        {
            // เลื่อนข้างหลังไปต่อข้างหน้่า Ex. [1, 4, 5, 4, 5]
            size_t old_pos = (mFront + i) % mCap;
            size_t new_pos = (mFront + i - block_size) % mCap;
            mData[new_pos] = mData[old_pos];
        }
    }

    mSize -= block_size;
}

#endif