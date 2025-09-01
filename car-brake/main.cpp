#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    while (n--) {
        int time, brake;
        cin >> time >> brake;
        v.push_back(make_pair(time, brake));
    }

    sort(v.begin(), v.end());

    vector<pair<int, int>> speed = {{0, k}};
    vector<pair<int, int>> speedCount = {{k, 0}};
    int prevSpeed = k;
    for (pair<int, int> p : v) {
        int currentSpeed = prevSpeed - p.second;
        if (currentSpeed < 0) currentSpeed = 0;
        speed.push_back(make_pair(p.first, currentSpeed));
        speedCount.push_back(make_pair(currentSpeed, p.first));
        prevSpeed -= p.second;
        if (prevSpeed <= 0) break;
    }

    sort(speedCount.begin(), speedCount.end());

    while (m--) {
        int op, input;
        cin >> op >> input;
        if (op == 1) {
            auto it = prev(upper_bound(speed.begin(), speed.end(), make_pair(input, INT_MAX)));
            cout << it->second << endl;
        }
        else {
            auto it = lower_bound(speedCount.begin(), speedCount.end(), make_pair(input, -1));
            if (it != speedCount.begin()) it = prev(it);
            cout << it->second << endl;
        }
    }
    

    return 0;
}

