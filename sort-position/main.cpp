#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v[i].first = input;
        v[i].second = i + 1;
    }
    
    sort(v.begin(), v.end());
    
    vector<pair<int, int>> reverseV(n);
    for (int i = 0; i < n; i++) {
        reverseV[i].first = v[i].second;
        reverseV[i].second = i + 1;
    }

    sort(reverseV.begin(), reverseV.end());

    for (pair<int, int> p : reverseV) {
        cout << p.second << " ";
    }

    return 0;
}