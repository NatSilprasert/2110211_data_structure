#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> words;
    while (n--) {
        string word;
        cin >> word;
        if (words.count(word) == 1) {
            words[word] += 1;
        } 
        else {
            words[word] = 1;
        }
    }

    for (auto word : words) {
        if (word.second > 1) {
            cout << word.first << " " << word.second << endl;
        }
    }
    return 0;
}