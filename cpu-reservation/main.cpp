#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<int, int>> chosen;
    for (int i = 0; i < n; ++i)
    {
        int s, e;
        cin >> s >> e;

        auto it = chosen.lower_bound({s, INT_MIN});

        bool ok = true;

        if (it != chosen.begin())
        {
            auto prev_it = prev(it);
            if (prev_it->second >= s)
                ok = false;
        }

        if (it != chosen.end())
        {
            if (e >= it->first)
                ok = false;
        }

        if (ok)
        {
            chosen.insert({s, e});
            cout << i + 1 << " ";
        }
    }

    return 0;
}