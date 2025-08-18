#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int, greater<string>> people;
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

    int maxVal = -1;
    string maxKey;
    for (auto &person : people) {
        if (person.second > maxVal) {
            maxVal = person.second;
            maxKey = person.first;
        }
    }

    cout << maxKey << " " << maxVal << endl;

    return 0;
}