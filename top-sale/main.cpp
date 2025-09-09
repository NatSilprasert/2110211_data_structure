#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    multiset<pair<int, int>> v;
    map<int, int> products;
    while (n--) {
        int product;
        cin >> product;
        v.insert({0, product});
        products[product] = 0;
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            if (products.count(a) == 0) continue;
            v.erase({products[a], a});
            products[a] += b;
            v.insert({products[a], a});
        }
        else {
            int k;
            cin >> k;
            auto it = v.upper_bound({k - 1, INT_MAX});
            if (it == v.begin()) {
                cout << "NONE\n";
            }
            else {
                it--;
                if (it->first == 0) cout << "NONE" << "\n";
                else cout << it->second << "\n";    
            }
        }
    }

    return 0;
}