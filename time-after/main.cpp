#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int hr;
    int min;
    int add;

    cin >> hr >> min >> add;

    min += add;
    if (min >= 60)
    {
        hr += min / 60;
        if (hr >= 24)
        {
            hr %= 24;
        }
        min %= 60;
    }

    string hrStr = to_string(hr);
    if (hrStr.length() == 1)
    {
        hrStr = "0" + hrStr;
    }
    string minStr = to_string(min);
    if (minStr.length() == 1)
    {
        minStr = "0" + minStr;
    }
    cout << hrStr << " " << minStr << endl;

    return 0;
}