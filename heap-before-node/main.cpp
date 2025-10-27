#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> child;
    child.insert(m);

    int current = 0;
    int round = 1;
    while (true)
    {
        int target;
        for (int i = 0; i < pow(2, round); i++)
        {
            target = m * pow(2, round) + current + i + 1;
            if (target >= n)
                break;
            child.insert(target);
        }
        if (target >= n)
            break;

        current = (current * 2) + 2;
        round++;
    }

    cout << n - child.size() << endl;
    for (int i = 0; i < n; i++) {
        if (!child.count(i)) cout << i << " ";
    }

    return 0;
}