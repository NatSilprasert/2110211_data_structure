#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <stack>
#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last) {
	last = std::min(last + 1, mSize);
	std::stack<T> s;
	
	for (size_t i = first; i < last; i++) {
		s.push(mData[mSize - i - 1]);
	}

	for (size_t i = first; i < last; i++) {
		mData[mSize - i - 1] = s.top();
		s.pop();
	}
}

#endif
