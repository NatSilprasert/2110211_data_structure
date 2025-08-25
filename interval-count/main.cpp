#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v;
    while (n--) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    while (m--) {
        int p;
        cin >> p;
        int start = p - k;
        int end = p + k;
        
        auto startPos = lower_bound(v.begin(), v.end(), start);
        auto endPos = upper_bound(v.begin(), v.end(), end);
        endPos--;

        cout << endPos - startPos + 1 << " ";
    }

    return 0;
}