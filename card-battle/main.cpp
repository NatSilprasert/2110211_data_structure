#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    multiset<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.insert(x);
    }

    int round = 1;
    for (int j = 0; j < m; j++)
    {
        int num;
        cin >> num;
        vector<int> enemy(num);
        for (int i = 0; i < num; i++)
        {
            cin >> enemy[i];
        }

        for (int power : enemy)
        {
            auto upper = v.upper_bound(power);
            if (upper == v.end())
            {
                cout << round;
                return 0;
            }
            v.erase(upper); // O(log n)
        }

        round++;
        if (round == m + 1)
        {
            cout << round;
        }
    }

    return 0;
}