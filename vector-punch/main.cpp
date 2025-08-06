#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> result;

    auto start = v.begin();
    auto end = v.end();

    if (it - v.begin() > k) {
        auto left = it - k;
        result.insert(result.begin(), start, left);
    }
    if (it + k < v.end()) {
        auto right = it + k + 1;
        result.insert(result.end(), right, end);
    }
   
    return result;
}
int main()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}