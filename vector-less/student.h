#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const
{

    size_t n = std::min(mSize, other.mSize);

    for (size_t i = 0; i < n; i++)
    {
        if (mData[i] < other[i])
            return true;
        if (other[i] < mData[i])
            return false;
    }

    return mSize < other.mSize;
}

#endif
