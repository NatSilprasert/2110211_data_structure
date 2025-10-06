#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element) 
{
	ensureCapacity(mSize + m);

	
	if (p < mSize - p) {
		// move the front part
		for (size_t i = 0; i < p; i++) {
			mData[(mFront - m + i + mCap) % mCap] = mData[(mFront + i) % mCap];
		}

		// insert the new element
		for (size_t i = 0; i < m; i++) {
			mData[(mFront - m + p + i + mCap) % mCap] = element;
		}

		// update the front pointer
		mFront = (mFront - m + mCap) % mCap;
	}
	else {
		// move the back part
		for (size_t i = 0; i < mSize - p; i++) {
			mData[(mFront + m + mSize - i - 1) % mCap] = mData[(mFront + mSize - i - 1) % mCap];
		}

		// insert the new element
		for (size_t i = 0; i < m; i++) {
			mData[(mFront + p + i) % mCap] = element;
		}

		// no need to update the front pointer
	}

	mSize += m;
}

#endif
