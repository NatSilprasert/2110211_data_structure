#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <list>
using namespace std;
int get_second_min(stack<int> &s)
{
    if (s.empty())
        return INT_MIN;

    stack<int> tmp;
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        if (x < min1)
        {
            min2 = min1;
            min1 = x;
        }
        else if (x > min1 && x < min2)
        {
            min2 = x;
        }
        tmp.push(x);
    }

    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }

    return (min2 == INT_MAX) ? min1 : min2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // repeat n-1 times
    for (int last = 1; last < n; last += 1)
    {
        stack<int> s;
        // build s;
        bool distinct = false;
        for (int i = last; i >= 0; i--)
        {
            s.push(v[i]);
            if (v[i] != v[0])
                distinct = true;
        }
        cout << "--use v[" << last << "] to v[0] --" << "\n";
        if (distinct)
        {
            // call get_second_min if we have at least 2 distinct value
            int answer = get_second_min(s);
            // print result and s
            cout << "result is " << answer << "\n";
            cout << "size of s is " << s.size() << "\n"
                 << "member of s are ";
            while (s.size() > 0)
            {
                cout << s.top() << " ";
                s.pop();
            }
            cout << "\n";
        }
        else
        {
            cout << "skip because s has only one value\n\n\n";
        }
    }
    return 0;
}