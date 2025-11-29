#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> hash(n);
    while (m--) {
        cin >> a >> b;
        if (a == 1) {
            hash[b] = b;
        }
        else if (a == 2) {

        }
    }

    return 0;
}