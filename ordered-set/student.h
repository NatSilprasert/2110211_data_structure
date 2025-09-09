#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T> &A, const vector<T> &B)
{
    unordered_set<T> s;
    vector<T> v;
    for (int a : A) {
        v.push_back(a);
        s.insert(a);
    }
    for (int b : B) {
        if (!s.count(b)) v.push_back(b);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B)
{
    unordered_set<T> s;
    vector<T> v;
    for (int b : B) s.insert(b);
    for (int a : A) {
        if (s.count(a) == 1) v.push_back(a);
    }
   
    return v;
}
