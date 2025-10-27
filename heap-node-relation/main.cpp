#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int lower = a > b ? b : a;
        int higher = a > b ? a : b;
        if (a == b) {
            cout << "a and b are the same node" <<endl;
            continue;
        }

        while (higher > lower) {
            if (higher % 2 == 0) higher -= 2; 
            else higher -= 1;
            higher /= 2;
        }

        if (higher == lower) {
            if (a < b) cout << "a is an ancestor of b";
            if (a > b) cout << "b is an ancestor of a";
            cout << endl;
        }
        else {
            cout << "a and b are not related" << endl;
        }
    }

    return 0;
}