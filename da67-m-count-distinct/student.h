#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    std::set<T> s;
    for (auto it = a; it != b; it++) {
        s.insert(*it);
    }

    return s.size();
}

#endif