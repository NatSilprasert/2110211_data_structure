#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); 
    
    int n, m;
    cin >> n >> m;
    multiset<pair<string, string>> v;
    while (n--) {
        string flight, seat;
        cin >> flight >> seat;
        v.insert(make_pair(flight, seat));
    }

    while (m--) {
        bool ok = true;
        int num;
        cin >> num;
        multiset<pair<string, string>> userDel;
        while (num--) {
            string flight, seat;
            cin >> flight >> seat;
            pair<string, string> p = make_pair(flight, seat);

            auto it = v.find(p);
            if (it == v.end()) {
                ok = false;
                while (num--) cin >> flight >> seat;
                v.insert(userDel.begin(), userDel.end());
                cout << "NO" << endl;
                break;
            }
            else {
                userDel.insert(*it);
                v.erase(it);
            }


        }

        if (ok) cout << "YES" << endl;
    }

    return 0;
}