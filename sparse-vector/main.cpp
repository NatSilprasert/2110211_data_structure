#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int, int> &v, int pos, int value)
{
    vector<pair<int, int>> shifted;
    for (auto it = v.lower_bound(pos); it != v.end(); ++it) {
        shifted.push_back({it->first + 1, it->second});
    }

    auto it = v.lower_bound(pos);
    v.erase(it, v.end());
    v[pos] = value;

    for (pair<int, int> p : shifted) {
        v.insert(v.end(), p);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }
    cout << v.size() << "\n";
    for (auto &x : v)
    {
        cout << x.first << ": " << x.second << "\n";
    }
}