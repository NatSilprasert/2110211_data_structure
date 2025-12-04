#include "sparse_vector.h"

template <typename T>
void CP::sparse_vector<T>::range_reserve(int left, int right)
{
    std::map<int, T> temp;
    for (auto it = mData.begin(); it != mData.end(); it++)
    {
        int index = it->first;
        if (index >= left && index <= right)
        {
            index = right + left - index;
        }
        temp[index] = it->second;
    }
    mData = temp;
}
