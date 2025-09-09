#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> maxPower(m, 1);
    vector<int> powerList(n);
    for (int i = 0; i < n; i++) {
        cin >> powerList[i];
    }

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        int power = powerList[i];
        if (maxPower[type] < power) maxPower[type] = power;

        cout << *min_element(maxPower.begin(), maxPower.end()) << " ";
    }

    return 0;
}