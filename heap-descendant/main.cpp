#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> child;
    child.push_back(m);
    
    int current = 0;
    int round = 1;
    while (true) {
        int target;
        for (int i = 0; i < pow(2, round); i++) {
            target = m * pow(2, round) + current + i + 1;
            if (target >= n) break;
            child.push_back(target);
        }
        if (target >= n) break;

        current = (current * 2) + 2;
        round++;
    }

    cout << child.size() << endl;
    for (int c : child) {
        cout << c << " ";
    }

    return 0;
}
