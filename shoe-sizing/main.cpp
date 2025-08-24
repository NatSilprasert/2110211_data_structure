#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> sizes;
    while (n--) {
        int input;
        cin >> input;
        sizes.push_back(input);
    }

    sort(sizes.begin(), sizes.end());

    while (m--) {
        int s;
        cin >> s;
        
        auto lower = lower_bound(sizes.begin(), sizes.end(), s);
        auto upper = upper_bound(sizes.begin(), sizes.end(), s);

        upper--;
        if (upper == sizes.begin() - 1) 
        {
            cout << sizes[0] << " ";
        }
        else if (lower == sizes.end() || *lower - s > s - *upper) 
        {
            cout << *upper << " ";
        }
        else if (*lower - s < s - *upper || *lower - s == s - *upper)
        {
            cout << *lower << " ";
        }
    }

    return 0;
}