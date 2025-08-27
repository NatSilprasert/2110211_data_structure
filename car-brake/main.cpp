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
    }

    sort(speedCount.begin(), speedCount.end());

    while (m--) {
        int op, input;
        cin >> op >> input;
        auto upper = upper_bound(speed.begin(), speed.end(), make_pair(input, INT_MAX)); // input = time
        auto upperCount = upper_bound(speedCount.begin(), speedCount.end(), make_pair(input, 0)); // input = speed
        upperCount--;
        upper--;
        if (op == 1) {
            cout << upper->second << "\n";
        }
        else if (op == 2 && upperCount != speedCount.begin() - 1) {
            cout << upperCount->second<< "\n";
        }
        else if (op == 2 && upperCount == speedCount.begin() - 1) {
            cout << next(upperCount)->second<< "\n";
        }
    }
    

    return 0;
}