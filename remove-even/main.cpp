#include <iostream>
#include <vector>

using namespace std;

void remove_even(vector<int> &v, int a, int b)
{
    if (b % 2 != 0)
    {
        b -= 1;
    }
    for (int i = b; i >= a; i -= 2)
    {
        v.erase(v.begin() + i);
    }
}
int main()
{
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    // call function
    remove_even(v, a, b);
    // display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}