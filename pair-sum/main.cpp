#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> nums;
    while (n--) {
        int newNum;
        cin >> newNum;
        nums.insert(newNum);
    }

    while (m--) {
        bool b = false;
        int input;
        cin >> input;
        for (int num : nums) {
            if (num > input) {break;}
            if (nums.count(input - num) == 1 && num != input - num) {
                b = true;
                break;
            } 
        }

        if (b) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}