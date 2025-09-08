#include <iostream>
#include <vector>
#include <queue>
using namespace std;
size_t qcount(queue<int> q, int k)
{
    int n = 0;
    queue<int> tmp;
    while (!q.empty()) {
        tmp.push(q.front());
        if (q.front() == k) n++;
        q.pop();
    }
    while (!tmp.empty()) {
        q.push(tmp.front());
        tmp.pop();
    }
    
    return n;
}
int main()
{
    // for faster cin, cout
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    cout << qcount(q, k) << endl;
}