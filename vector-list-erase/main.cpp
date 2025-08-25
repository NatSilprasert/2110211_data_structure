#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
void list_erase(vector<int> &v, vector<int> &pos)
{
    unordered_set<int> toErase(pos.begin(), pos.end());
    vector<int> newV;
    newV.reserve(v.size() - pos.size());

    for (int i = 0; i < (int)v.size(); i++)
    {
        if (toErase.find(i) == toErase.end())
        {
            newV.push_back(v[i]);
        }
    }
    v.swap(newV);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> pos[i];
    list_erase(v, pos);
    cout << "After call list_erase" << endl
         << "Size = " << v.size() << endl;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}