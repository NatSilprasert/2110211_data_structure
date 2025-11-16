#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long count = 1;
    long long h = 0;

    if (k == 1) {
        cout << n - 1;
        return 0;
    }

    while (count < n) {
        h++;
        count += pow(k, h);
    }

    cout << h;

    return 0;
}