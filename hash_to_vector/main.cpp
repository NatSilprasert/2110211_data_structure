#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void hash_to_vector(unordered_map<int, string> hash, vector<int> &key, vector<string> &value)
{
    for (auto it = hash.begin(); it != hash.end() ;++it) {
        key.push_back(it->first);
        value.push_back(it->second);
    }
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int, string> hash;
    while (n--)
    {
        int a;
        string st;
        cin >> a >> st;
        hash[a] = st;
    }

    vector<int> k;
    vector<string> v;
    hash_to_vector(hash, k, v);
    for (auto &x : k)
        cout << x << " ";
    cout << endl;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}