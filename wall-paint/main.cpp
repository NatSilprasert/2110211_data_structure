#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n, m;
vector<pair<int, int>> v;

int main() {

    cin >> n >> m;
    v.resize(m + 1);
    v[0] = {0, n + 1};

    for (int i = 0; i < m * 2; i++) {
        int x, c, d;
        cin >> x >> c >> d;
        if (d == 0) v[c].first = x;
        if (d == 1) v[c].second = x;
    }


    map<int, pair<int, int>> wall;
    set<int> s;
    s.insert(0);
    wall[0] = {0, n + 1};
    int max = 1;
    for (int i = 1; i < v.size(); i++) {
        auto it = s.upper_bound(v[i].first);
        it--;

        int startPos = *it;
        if (v[i].second >= wall[startPos].second || startPos == v[i].first) {
            continue;
        }

        wall[v[i].first] = {wall[startPos].first + 1, v[i].second};
        wall[v[i].second] = {wall[startPos].first, wall[startPos].second};
        wall[startPos] = {wall[startPos].first, v[i].first};

        s.insert(v[i].first);
        s.insert(v[i].second);

        if (wall[startPos].first + 1 > max) {
            max = wall[startPos].first + 1;
        }
    }   

    cout << max; 

    return 0;
}