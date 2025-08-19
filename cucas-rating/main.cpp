#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(2);
    int n;
    cin >> n;
    map<long long, int> courseVotes;
    map<string, int> teacherVotes;
    map<long long, float> courseRating;
    map<string, float> teacherRating;
    while (n--) {
        long long course;
        string teacher;
        int score;

        cin >> course >> teacher >> score;
        if (courseRating.count(course) == 1) {
            courseRating[course] += score;
            courseVotes[course] += 1;
        }
        else {
            courseRating[course] = score;
            courseVotes[course] = 1;
        }

        if (teacherRating.count(teacher) == 1) {
            teacherRating[teacher] += score;
            teacherVotes[teacher] += 1;
        }
        else {
            teacherRating[teacher] = score;
            teacherVotes[teacher] = 1;
        }
    }

    for (auto c : courseRating) {
        cout << c.first << " " << (c.second + 0.0) / courseVotes[c.first] << endl;
    }
    for (auto t : teacherRating) {
        cout << t.first << " " << (t.second + 0.0) / teacherVotes[t.first] << endl;
    }

    return 0;
}