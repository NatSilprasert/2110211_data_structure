#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{

    vector<int> nums;
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin >> x;
        if (cin.peek() == ' ')
        {
            cin >> y;
        }

        if (x == "pb")
        {
            nums.push_back(y);
        }
        else if (x == "sa")
        {
            sort(nums.begin(), nums.end());
        }
        else if (x == "sd")
        {
            sort(nums.begin(), nums.end(), greater<int>());
        }
        else if (x == "r")
        {
            reverse(nums.begin(), nums.end());
        }
        else if (x == "d")
        {
            nums.erase(nums.begin() + y);
        }
    }

    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}