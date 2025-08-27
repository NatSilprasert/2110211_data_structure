#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            int s, e;
            cin >> s >> e;
            pair<int, int> p = {s, e};
            auto lower = lower_bound(v.begin(), v.end(), make_pair(s, 0)); 
            auto upper = upper_bound(v.begin(), v.end(), make_pair(s, 99999999)); 
            upper--;

            if (
                upper != v.begin() - 1 && lower != v.end() &&
                (upper->second + 1 >= s) && (lower->first - 1 <= e)
            )   
            {
                pair<int, int> newP = {upper->first, lower->second};
            }
            else if (
                upper == v.begin() - 1 && lower != v.end() && (lower->first - 1 <= e)
            )
            {
                pair<int, int> newP = {s, lower->second};
            }
            else if (
                lower == v.end() && upper != v.begin() - 1 && (upper->second + 1 >= s)
            )
            {
                pair<int, int> newP = {upper->first, e};
            }
            else
            {
                v.push_back(p);
            }

            sort(v.begin(), v.end());
        }
        if (op == 2) {
           
            cout << v.size() << "\n";
        }
    }

    return 0;
}