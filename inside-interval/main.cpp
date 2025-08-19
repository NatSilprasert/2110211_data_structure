#include <iostream>
#include <set>
#include <limits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    while (n--) {
        int start, stop;
        cin >> start >> stop;
        s.insert({start, stop});
    }
    while (m--) {
        int num;
        cin >> num;
        auto it = s.upper_bound({num, numeric_limits<int>::max()});
        if (it == s.begin()) {
            cout << "0 ";
            continue;
        }
        it--;
        if (it->first <= num && num <= it->second) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }

    return 0;
}