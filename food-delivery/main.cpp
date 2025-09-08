#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<int> ans;
    queue<int> foodpanda;
    queue<int> lineman;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    int money = 0;
    while (n--) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            if (a == 1) {
                foodpanda.push(b);
            }
            else {
                lineman.push(b);
            }
        }
        else if (op == 2) {
            if (foodpanda.empty()) {
                money += lineman.front();
                lineman.pop();
            }
            else if (lineman.empty()) {
                money += foodpanda.front();
                foodpanda.pop();
            }
            else if (foodpanda.front() > lineman.front()) {
                money += lineman.front();
                lineman.pop();
            }
            else if (foodpanda.front() <= lineman.front()) {
                money += foodpanda.front();
                foodpanda.pop();
            }
            ans.push_back(money);
        }
    }

    for (int num : p) {
        auto it = lower_bound(ans.begin(), ans.end(), num);
        int idx = it - ans.begin() + 1;
        if (it == ans.end()) cout << -1 << " ";
        else cout << idx << " ";
    }

    return 0;
}
