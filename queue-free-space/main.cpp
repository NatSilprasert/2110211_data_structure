#include <iostream>

using namespace std;

int main() {
    int n;
    long long cap = 1, size = 0;
    cin >> n;
    while (n--) {
        int t;
        long long x;
        cin >> t >> x;
        if (t == 0) {
            size += x;
            while (cap < size) cap *= 2;
        }
        if (t == 1) {
            size -= x;
        }
    }

    cout << cap - size;
}