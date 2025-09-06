#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long x;
    cin >> x;
    int k = ceil(log2(x));
    cout << (long long)(pow(2, k) - x) << endl;
    return 0;
}