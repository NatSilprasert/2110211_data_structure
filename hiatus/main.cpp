#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    while (n--) {
        int year, month;
        cin >> year >> month;
        v.push_back(make_pair(year, month));
    }

    sort(v.begin(), v.end());

    while (m--) {
        int year, month;
        cin >> year >> month;
        auto previous = upper_bound(v.begin(), v.end(), make_pair(year, month));
        previous--;
        if (previous == v.begin() - 1) {
            cout << "-1 -1" << " ";
        }
        else if (previous->first == year && previous->second == month) {
            cout << "0 0" << " ";
        }
        else {
            cout << previous->first << " " << previous->second << " ";
        }
    }
    
    return 0;
}