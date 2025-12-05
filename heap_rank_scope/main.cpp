#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;
    int height = floor(log2(x + 1));
    int childcnt = 0;
    int rightChildIdx = (2 * x + 1);
    int childIdx = rightChildIdx;
    int cnt = 2;
    while (true)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (childIdx > N - 1)
                break;
            childcnt++;
            childIdx++;
        }
        if (childIdx > N - 1)
            break;
        rightChildIdx = (2 * rightChildIdx + 1);
        childIdx = rightChildIdx;
        cnt *= 2;
    }
    cout << childcnt + 1 << " " << N - height;
}