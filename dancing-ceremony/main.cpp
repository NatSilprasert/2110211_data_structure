#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        v[i] -= b;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
    {
        int j = upper_bound(v.begin() + i + 1, v.end(), -v[i]) - v.begin();
        ans += n - j;
    }

    cout << ans << endl;

    return 0;
}