#include <iostream>
#include <cmath>
using namespace std;

bool is_father(long long S, long long a, long long b)
{
    if (a == 0 && b == 0) return false;
    if (a < b) swap(a, b);
    return (long long)((a - 1) / S) == b;
}

bool is_decendant(long long S, long long a, long long b)
{
    if (a == 0 && b == 0) return false;
    if (a == b) return false;
    if (a < b) swap(a, b);
    while (a > b) {
        a = ((a - 1) / S);
    }
    return a == b;
}

long long get_height(long long S, long long pos) 
{
    long long count = 0;
    while (pos > 0) {
        pos = (pos - 1) / S;
        count++;
    }
    return count;
}

bool is_same_level(long long S, long long a, long long b) 
{
    return get_height(S, a) == get_height(S, b);
}

int relation(long long S, long long a, long long b)
{
    if (is_father(S, a, b))
        return 1;
    if (is_decendant(S, a, b))
        return 2;
    if (!is_same_level(S, a, b))
        return 3;
    return 4;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long S, a, b;
    cin >> n;
    while (n--)
    {
        cin >> S >> a >> b;
        cout << relation(S, a, b) << " ";
    }
    cout << endl;
}