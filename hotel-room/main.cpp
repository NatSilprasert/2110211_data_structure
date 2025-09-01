#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    int total = 0;
    cin >> n >> m;
    multiset<pair<int, int>> floor;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        floor.insert(make_pair(input, -i - 1));
        total += input;
    }

    while (m--) {
        int num;
        cin >> num;
        
        if (num > total) {
            cout << "-1\n";
            continue;
        }
        total -= num;

        vector<pair<int, int>> ans;

        while (num > 0) {
            auto newIt = floor.lower_bound(make_pair(num, INT_MIN));
            if (newIt != floor.end()) {
                auto [r, i] = *newIt;
                ans.push_back(make_pair(-i, num));
                floor.erase(newIt);
                if (r != num) floor.insert(make_pair(r - num, i)); 
                num = 0;
            }
            else {
                auto it = floor.lower_bound(make_pair(floor.rbegin()->first, INT_MIN));
                num -= floor.rbegin()->first;
                ans.push_back(make_pair(-it->second, it->first));
                floor.erase(it);       
            }
        }

        sort(ans.begin(), ans.end());
        for (auto p : ans) {
            cout << p.first << " " << p.second << " ";
        }

        cout << "\n";
    }

    return 0;
}

