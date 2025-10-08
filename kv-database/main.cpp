#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    int q;
    cin >> q;
    unordered_map<int, vector<pair<int, int>>> m;
    int cur = 1;

    while (q--) {
        char o;
        int pos, v;
        cin >> o >> pos >> v;
        auto &f = m[pos];
        
        if (f.empty()) f.push_back({0, -1});
        
        if (o == 'U') {
            f.push_back({-cur, v});
            ++cur;
        }
        else {
            auto lwb = lower_bound(f.rbegin(), f.rend(), make_pair(-v, -1));
            cout << lwb->second << '\n';
        }
    }
}