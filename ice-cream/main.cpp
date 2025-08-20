#include <iostream>
#include <map>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    map <int, int> d;
    while (n--) {
        int input1, input2;
        cin >> input1 >> input2;
        d[input1] = input2;
    }

    while (m--) {
        int collect = start, 
            money = start, 
            prevDay = 0, 
            maxVal = 0, 
            price, scam;
        cin >> price >> scam;

        for (auto it = d.begin(); it != d.end(); ++it) {
            maxVal += (it->first - prevDay) * money;
            
            int date = it->first - 1;
            if (date > scam) {
                maxVal = (date - scam) * money;
            }

            if (price <= maxVal) {
                while (price <= maxVal - money) {
                    maxVal -= money;
                    date--;
                }
                cout << date << " ";
                break;
            }
            else if (it == prev(d.end())) {
                while (price > maxVal) {
                    if (date == scam) {maxVal = 0;}
                    maxVal += it->second;
                    date++;
                }
                cout << date << " ";
            }
            else {
                money = it->second;
                prevDay = it->first;
            }
            
        }
    }

    return 0;
}