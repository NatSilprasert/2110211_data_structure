#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    vector<int> result;
    set_intersection(a.begin(), a.end(),
                     b.begin(), b.end(),
                     inserter(result, result.begin()));

    for (int x : result)
        cout << x << " ";

    return 0;
}