#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;

    vector<pair<int, int>> v;
    vector<long long> money = {start};
    long long prevAmount = start;
    long long prevMoney = start;
    long long prevDay = 1;
 
    while (n--) {
        long long input1, input2;
        cin >> input1 >> input2;
        v.push_back(make_pair(input1, input2));
    }

    sort(v.begin(), v.end());

    for (auto [key, val] : v) {
        long long count = key - prevDay;
        while (count--) {
            prevAmount += prevMoney;
            money.push_back(prevAmount);
        }
        prevMoney = val;
        prevDay = key;
    }

    while (money.size() <= 100000) {
        prevAmount += prevMoney;
        money.push_back(prevAmount);
    }

    while (m--) {
        long long price, scam;
        cin >> price >> scam;
        auto it = lower_bound(money.begin(), money.end(), price);
        long long day = it - money.begin();
        if (day <= scam) {
            cout << day << " ";
        }
        else {
            auto newIt = lower_bound(it, money.end(), price + money[scam]);
            cout << newIt - money.begin() << " ";
        }
    }

    return 0;
}