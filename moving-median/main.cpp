#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    } 

    vector<int> ans;
    multiset<int> s(v.begin(), v.begin() + w + 1);
    auto median = next(s.begin(), w / 2);
    for (int i = w + 1; i < n; i++) {
        ans.push_back(*median);
        s.insert(v[i]);
        if (v[i] < *median) median--;
        if (v[i - w - 1] <= *median) median++;
        s.erase(s.lower_bound(v[i - w - 1]));
    }
    ans.push_back(*median);

    for (int num : ans) cout << num << " ";

    return 0;
}