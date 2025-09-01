#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::isReverse(const std::vector<T> &other) const
{
    if (data.size() != other.size())
        return false;

    int n = data.size();
    for (int i = 0; i < n; i++)
    {
        if (data[i] != other[n - 1 - i])
            return false;
    }
    return true;
}

#endif