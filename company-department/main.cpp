#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, string> person;
    map<string, vector<string>> dp;
    while (n--) {
        string name, department;
        cin >> name >> department;
        if (dp.count(department) == 0) {
            dp[department] = {name};
        }
        else {
            dp[department].push_back(name);
        }
        person[name] = department;
    }

    while (m--) {
        int op;
        string a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            if (dp.count(b) == 0) {
                dp[b] = {a};
            }
            else {
                dp[b].push_back(a);
            }
            auto it = find(dp[person[a]].begin(), dp[person[a]].end(), a);
            dp[person[a]].erase(it);
            person[a] = b;
        }
        else {
            for (string name : dp[a]) {
                if (dp.count(b) == 0) {
                    dp[b] = {name};
                }
                else {
                    dp[b].push_back(name);
                }
                person[name] = b;
            }
            dp.erase(a);
        }
    }

    for (auto [key, value] : dp) {
        cout << key << ": ";
        sort(value.begin(), value.end());
        for (string name : value) {
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}
