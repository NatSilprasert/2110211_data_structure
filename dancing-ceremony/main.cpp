#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = n * (n - 1) / 2;

    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum[i] = a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        sum[i] -= b;
    }
    
    sort(sum.begin(), sum.end());
    
    // cout << endl;
    // for (int num : sum) {
    //     cout << "num : " << num << endl;
    // }

    for (auto st = sum.begin(); st < sum.end(); st++) {
        int num = *st;
        if (num >= 0) {
            break;
        }
        int newNum = num * -1;
        auto it = upper_bound(st, sum.end(), newNum);
        it--;
        total -= it - st;
        // cout << "num : " << num << " diff : " << it - st << endl;
    }
    
    cout << total;

    return 0;
}