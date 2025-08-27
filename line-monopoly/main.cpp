#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<int, int>> range;

    for (int i = 0; i < n; i++)
    {
        int op, start, end;
        cin >> op;
        if (op == 1)
        {
            cin >> start >> end;
            end++;
            auto data = make_pair(start, end);

            range.insert(data);

            int left = start;
            int right = start;
            right++;

            while (right != *prev(range.end())) {

            }
        }
        else
        {
            cout << range.size() << "\n";
        }
    }
}