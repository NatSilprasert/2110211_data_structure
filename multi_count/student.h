#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>
#include <set>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::vector<std::pair<T, size_t>> ans;
    std::set<T> s;
    std::map<T, int> m;
    for (int i = 0; i < mSize; i++) {
        if (!s.count(mData[(i + mFront) % mCap])) {
            s.insert(mData[(i + mFront) % mCap]);
            m[mData[(i + mFront) % mCap]] = 1;
        } 
        else {
            m[mData[(i + mFront) % mCap]]++;
        }
    }

    for (int i = 0; i < k.size(); i++) {
        if (s.count(k[i])) ans.push_back({k[i], m[k[i]]});
        else ans.push_back({k[i], 0});
    }

    return ans;
}

#endif
