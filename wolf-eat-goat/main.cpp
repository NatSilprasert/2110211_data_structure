#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, d;
    cin >> n;
    vector<int> goat(n);
    while (n--)
    {
        int goatPos;
        cin >> goatPos;
        goat[n] = goatPos;
    }

    sort(goat.begin(), goat.end());

    cin >> d;
    while (d--)
    {
        int wPos;
        cin >> wPos;
        auto lower = lower_bound(goat.begin(), goat.end(), wPos);
        auto upper = upper_bound(goat.begin(), goat.end(), wPos);
        upper--;
        // cout << "upper = " << *upper << endl;
        // cout << "lower = " << *lower << endl;
        if (upper == goat.begin() - 1)
        {
            cout << *lower - wPos << endl;
        }
        else if (lower == goat.end())
        {
            cout << wPos - *upper << endl;
        }
        else if (*lower - wPos < wPos - *upper)
        {
            cout << *lower - wPos << endl;
        }
        else
        {
            cout << wPos - *upper << endl;
        }
    }

    return 0;
}