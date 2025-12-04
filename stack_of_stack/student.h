#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>

// can include other libs or write util funtion here
template <typename T>
size_t mCap(std::vector<std::vector<T>> &v)
{
    return (v.size() + 1) * (v.size()) / 2;
}

template <typename T>
void CP::stack<T>::push(const T &value)
{
    if (mSize == 0 || mCap(mData) < mSize + 1)
    {
        mData.push_back(std::vector<T>());
    }
    mData.back().push_back(value);
    mSize++;
}

template <typename T>
void CP::stack<T>::pop()
{
    if (size() == 0)
        throw std::out_of_range("index of out range");
    mData.back().pop_back();
    if (mData.back().size() == 0)
        mData.resize(mData.size() - 1);
    mSize--;
}

template <typename T>
size_t CP::stack<T>::size() const
{
    return mSize;
}

template <typename T>
const T &CP::stack<T>::top() const
{
    // write your code here
    if (size() == 0)
        throw std::out_of_range("index of out range");
    return mData.back().back();
}

/*
Push and pop with steady hand,
or tears may fall from teacher’s stand.
*/

#endif