#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    set<int> a, b;
    while (m--) {
        int num;
        cin >> num;
        a.insert(num);
    }
    while (n--) {
        int num;
        cin >> num;
        b.insert(num);
    }

    set<int> result;
    set_intersection(a.begin(), a.end(),
                     b.begin(), b.end(),
                     inserter(result, result.begin()));
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
