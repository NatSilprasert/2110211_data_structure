#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m)
{
    if (m <= 0 || a == b || a < begin() || b < begin() || a >= end() || b >= end() || a + m > end() || b + m > end())
        return false;

    size_t ia = a - begin();
    size_t ib = b - begin();

    if (ia > ib) {
        if (ib + m > ia) return false;
    }
    else {
        if (ia + m > ib) return false;
    }

    for (size_t i = 0; i < m; i++)
    {
        std::swap(mData[ia + i], mData[ib + i]);
    }

    return true;
}

#endif
