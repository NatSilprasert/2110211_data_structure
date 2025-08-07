#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col, n;
    cin >> row >> col >> n;

    vector<vector<int>> nums(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> nums[i][j]; 
        }
    }

    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2 || c1 > c2) {
            cout << "INVALID" << endl;
        }
        else if ((r1 > row && r2 > row) || (c1 > col && c2 > col))
        {
            cout << "OUTSIDE" << endl;
        }
        else {
            int result = -999999999;
            for (int j = r1 - 1; j < r2; j++) {
                for (int k = c1 - 1; k < c2; k++) {
                    if (k < col && j < row && nums[j][k] > result) {
                        result = nums[j][k];
                    }
                }
            }
            cout << result << endl;
        }
    }

    return 0;
}