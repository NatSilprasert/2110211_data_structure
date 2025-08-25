#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> key(k);
    
    for (int i = 0; i < k; i++) {
        cin >> key[i];
    }

    unordered_set<string> words;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words.insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        string word;
        for (int j = 0; j < k; j++)
        {
            char c;
            cin >> c;
            c = ((c - 'a' + key[j]) % 26) + 'a';
            word += c;
        }
        if (words.count(word))
        {
            cout << "Match\n";
        }
        else
        {
            cout << "Unknown\n";
        }
    }
}