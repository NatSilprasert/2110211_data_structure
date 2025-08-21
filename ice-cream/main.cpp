#include <iostream>
#include <map>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    int prevVal = start;
    int prevDay = 0;
    int total = 0;
    map <long long, pair<long long, int>> d;
    while (n--) {
        int input1, input2;
        cin >> input1 >> input2;

        total += (input1 - prevDay) * prevVal;
        d[total] = {input1 - 1, prevVal};

        prevDay = input1;
        prevVal = input2;
    }

    d[999999] = {999999, prevVal};

    while (m--) {
        int price, scam;
        cin >> price >> scam;

        auto it = d.lower_bound(price);
        int money = prev(it)->first;

        if (scam <= it->second.first) {
            int dayDiff = it->second.first - scam;
            money = dayDiff * it->second.first;
        }

        int date = (price - money) / it->second.second + prev(it)->second.first;
        cout << endl;
        cout << date << " ";
    }

    return 0;
}