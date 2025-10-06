#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    set<pair<int, int>> st;
    int count = 0;

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        while (true) {
            auto it = st.lower_bound({l - 1, INT_MIN});
            if (it != st.end() && it->second <= r + 1)
            {
                l = min(it->second, l);
                r = max(it->first, r);
                count -= it->first - it->second + 1;
                st.erase(it);
                continue;
            }
            break;
        }
        st.insert({r, l});
        count += r - l + 1;
        cout << n - count << "\n";
    }
    return 0;
}