#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    multiset<pair<int, int>> maxPower;
    vector<int> typePower(m, 1);
    vector<int> powerList(n);
    for (int i = 0; i < n; i++) {
        cin >> powerList[i];
    }

    for (int i = 0; i < m; i++) {
        maxPower.insert({1, i});
    }

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        int power = powerList[i];
        if (typePower[type] < power) {
            maxPower.erase({typePower[type] ,type});
            typePower[type] = power;
            maxPower.insert({power ,type});
        } 
        cout << maxPower.begin()->first << " ";
    }

    return 0;
}