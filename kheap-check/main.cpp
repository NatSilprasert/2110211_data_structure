#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        vector<int> data;
        while (n--) {
            int x;
            cin >> x;
            data.push_back(x);
        }

        bool check = true;
        for (int i = 1; i < data.size(); i++) {
            if (data[i] > data[(i - 1) / k]) {
                check = false;
                break;
            }
        }
        cout << (check ? "true" : "false") << endl;
    }

    return 0;
}