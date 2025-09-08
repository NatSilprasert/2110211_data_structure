#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    multiset<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        int op, start, end;
        cin >> op;
        if (op == 1) {
            cin >> start >> end;
            auto startIt = s.insert({start, 0});
            auto endIt = s.insert({end, 1});

            if (s.size() == 2) continue;

            if (startIt != s.begin() && prev(startIt)->second == 0)
            {
                startIt--;
            }
            else if (startIt != s.begin() && prev(startIt)->second == 1 &&
                     (prev(startIt)->first + 1 == start || prev(startIt)->first == start))
            {
                startIt = prev(prev(startIt));
            }

            if (next(endIt) != s.end() && next(endIt)->second == 1)
            {
                endIt++;
            }
            else if (next(endIt) != s.end() && next(endIt)->second == 0 &&
                     (next(endIt)->first - 1 == end || next(endIt)->first == end))
            {
                endIt = next(next(endIt));
            }

            int val = startIt->first;
            s.erase(startIt, endIt);
            s.insert({val, 0});
            

        }  
        else {
            cout << s.size() / 2 << "\n";
        }
    }
}