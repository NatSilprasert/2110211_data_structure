#ifndef _CP_SEGMENTED_VECTOR_INCLUDED_
#define _CP_SEGMENTED_VECTOR_INCLUDED_
#include <iostream>

namespace CP {

template <typename T>
class SegmentedVector {
	private:
		T** mData;
		size_t mCap;
		size_t mSize;
		size_t blockSize;
	protected:
		void ensureCapacity(size_t capacity) {
			if (capacity > mCap) {
				size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
				expand(s);
			}
		}
	public:
		SegmentedVector(int bsz) {
			mCap = 1;
			mSize = 0;
			blockSize = bsz;
			mData = new T*[mCap]();
			mData[0] = new T[bsz]();
		}
		size_t size() {
			return mSize;
		}
		size_t capacity() {
			return mCap;
		}
		void pop_back() {
			mSize--;
		}
		void push_back(const T& element) {
			insert(mSize, element);
		}

	/* --------------- FOR student.h --------------- */
	protected:
		void expand(size_t capacity);
	public:
		~SegmentedVector();
		void insert(int index, const T& element);
		T& operator[](int index) const;
	/* --------------------------------------------- */
};

}
#endif