#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long r, c;
    int k, n;
    cin >> r >> c >> k;

    vector<long long> favorite(k);
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        favorite[i] = (long long)(p - 1) * c + q;
    }

    sort(favorite.begin(), favorite.end());

    cin >> n;
    while (n--) {
        int p, q;
        cin >> p >> q;
        long long startPos = (long long)(p - 1) * c + q;

        if (binary_search(favorite.begin(), favorite.end(), startPos))
        {
            cout << 0 << endl;
            continue;
        }

        auto it = upper_bound(favorite.begin(), favorite.end(), startPos);
        if (it == favorite.end())
        {
            cout << (r * c - startPos) + favorite[0] << endl;
        }
        else
        {
            cout << (*it - startPos) << endl;
        }
    }
    return 0;
}