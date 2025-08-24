#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;    
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input > n || input < 0) {
            cout << "NO";
            return 0;
        }
        s.insert(input);
    }

    if (s.size() == n) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}