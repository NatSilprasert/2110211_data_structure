#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<string, int> people;
    while (n--) {
        string name;
        cin >> name;
        if (people.count(name) == 1) {
            people[name] += 1;
        }
        else {
            people[name] = 1;
        }
    }

    vector<int> votes;
    for (auto &person : people) {
        votes.push_back(person.second);
    }
    sort(votes.begin(), votes.end(), greater<int>());
    
    if (votes.size() < k) {
        cout << *(votes.end() - 1) << endl;
    } 
    else {
        cout << votes[k - 1] << endl;
    }

    return 0;
}