#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Seat
{
    long long freeTime;
    int chef;
    bool operator>(const Seat &o) const
    {
        if (freeTime == o.freeTime)
            return chef > o.chef;
        return freeTime > o.freeTime;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> T(n);
    for (int i = 0; i < n; i++)
        cin >> T[i];

    priority_queue<Seat, vector<Seat>, greater<Seat>> pq;

    for (int i = 0; i < n; i++) pq.push({0, i});

    for (int customer = 0; customer < m; customer++)
    {
        auto cur = pq.top();
        pq.pop();
        cout << cur.freeTime << "\n";
        pq.push({cur.freeTime + T[cur.chef], cur.chef});
    }

    return 0;
}